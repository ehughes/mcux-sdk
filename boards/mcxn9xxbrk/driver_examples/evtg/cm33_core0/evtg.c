/*
 * Copyright  2022 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "board.h"
#include "fsl_sctimer.h"
#include "fsl_evtg.h"

#include "fsl_inputmux.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_EVTG       EVTG0
#define DEMO_EVTG_INDEX kEVTG_Index0
#define EVTG_HAS_NO_OUTPUT_PIN

#define DEMO_SCT                SCT0
#define SCTIMER_CLK_FREQ        CLOCK_GetSctClkFreq()
#define DEMO_FIRST_SCTIMER_OUT  kSCTIMER_Out_0
#define DEMO_SECOND_SCTIMER_OUT kSCTIMER_Out_1

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Initialize the SCTIMER.
 *
 */
static void SCTIMER_Config(void);
/*!
 * @brief Initialize the EVTG.
 *
 */
static void EVTG_Config(void);
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void)
{
    /* Board pin, clock, debug console init */
    /* Enables the clock for INPUTMUX: Enables clock */
    CLOCK_EnableClock(kCLOCK_InputMux0);
    /* Enables the clock for INPUTMUX: Enables clock */
    CLOCK_EnableClock(kCLOCK_Evtg);

    /* attach FRO 12M to FLEXCOMM4 (debug console) */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /* attach FRO HF to SCT */
    CLOCK_SetClkDiv(kCLOCK_DivSctClk, 1u);
    CLOCK_AttachClk(kFRO_HF_to_SCT);

    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    /* SCT output 0 is selected for EVTG triger 0 */
    INPUTMUX_AttachSignal(INPUTMUX0, 0U, kINPUTMUX_SctOut0ToEvtgTrigger);
    /* SCT output 1 is selected for EVTG triger 1 */
    INPUTMUX_AttachSignal(INPUTMUX0, 1U, kINPUTMUX_SctOut1ToEvtgTrigger);

    /* EVTG0 outputA is selected for SCT input 0 */
    INPUTMUX_AttachSignal(INPUTMUX0, 0U, kINPUTMUX_EvtgOut0AToSct0);

    /* Init the SCTIMER */
    SCTIMER_Config();

    /* Init the EVTG */
    EVTG_Config();

#if defined(EVTG_HAS_NO_OUTPUT_PIN)
    /* Init the LED. */
    LED_RED_INIT(LOGIC_LED_ON);
#endif

    PRINTF("\r\nThe example output 2 PWM signals by SCtimer and their intersection by EVTG.\r\n");

    while (1)
    {
#if defined(EVTG_HAS_NO_OUTPUT_PIN)
        /* Get SCT input 1 data */
        if (0U == (SCT_INPUT_AIN0_MASK & DEMO_SCT->INPUT))
        {
            LED_RED_ON(); /* Turn on led. */
        }
        else
        {
            LED_RED_OFF(); /* Turn off led. */
        }
#endif
    }
}

static void SCTIMER_Config(void)
{
    sctimer_config_t sctimerInfo;
    sctimer_pwm_signal_param_t pwmParam;
    uint32_t event;
    uint32_t sctimerClock;

    sctimerClock = SCTIMER_CLK_FREQ;

    SCTIMER_GetDefaultConfig(&sctimerInfo);

    /* Initialize SCTimer module */
    SCTIMER_Init(DEMO_SCT, &sctimerInfo);

    /* Configure first PWM with frequency 240HZ from first output */
    pwmParam.output           = DEMO_FIRST_SCTIMER_OUT;
    pwmParam.level            = kSCTIMER_HighTrue;
    pwmParam.dutyCyclePercent = 50;

    if (SCTIMER_SetupPwm(DEMO_SCT, &pwmParam, kSCTIMER_CenterAlignedPwm, 240U, sctimerClock, &event) == kStatus_Fail)
    {
        PRINTF("\r\nFirst SCTimer output failed!\r\n");
        return;
    }
    PRINTF("\r\nFirst SCTimer output success!\r\n");

    /* Configure second PWM with frequency 240HZ from second output */
    pwmParam.output           = DEMO_SECOND_SCTIMER_OUT;
    pwmParam.level            = kSCTIMER_LowTrue;
    pwmParam.dutyCyclePercent = 20;

    if (SCTIMER_SetupPwm(DEMO_SCT, &pwmParam, kSCTIMER_CenterAlignedPwm, 240U, sctimerClock, &event) == kStatus_Fail)
    {
        PRINTF("\r\nSecond SCTimer output failed!\r\n");
        return;
    }
    PRINTF("\r\nSecond SCTimer output success!\r\n");

    /* Start the 32-bit unify timer */
    SCTIMER_StartTimer(DEMO_SCT, kSCTIMER_Counter_U);
}

static void EVTG_Config(void)
{
    evtg_config_t evtgConfig;

    /* Initialize EVTG module */
    EVTG_GetDefaultConfig(&evtgConfig, kEVTG_FFModeBypass);
    evtgConfig.aoi0Config.productTerm0.aInput = kEVTG_InputDirectPass;
    evtgConfig.aoi0Config.productTerm0.bInput = kEVTG_InputDirectPass;
    evtgConfig.aoi0Config.productTerm0.cInput = kEVTG_InputLogicOne;
    evtgConfig.aoi0Config.productTerm0.dInput = kEVTG_InputLogicOne;
    EVTG_Init(DEMO_EVTG, DEMO_EVTG_INDEX, &evtgConfig);
    PRINTF("\r\nEVTG output success.\r\n");
}
