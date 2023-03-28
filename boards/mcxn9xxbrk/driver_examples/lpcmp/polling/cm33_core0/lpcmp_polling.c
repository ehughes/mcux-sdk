/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_lpcmp.h"

#include "fsl_vref.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_LPCMP_BASE             CMP0
#define DEMO_LPCMP_USER_CHANNEL     0U
#define DEMO_LPCMP_DAC_CHANNEL      7U
#define DEMO_LPCMP_IRQ_ID           HSCMP0_IRQn
#define LED_INIT()                  LED_RED_INIT(LOGIC_LED_ON)
#define LED_ON()                    LED_RED_ON()
#define LED_OFF()                   LED_RED_OFF()
#define DEMO_LPCMP_IRQ_HANDLER_FUNC HSCMP0_IRQHandler
#define DEMO_VREF_BASE              VREF0

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

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
    lpcmp_config_t mLpcmpConfigStruct;
    lpcmp_dac_config_t mLpcmpDacConfigStruct;

    /* Initialize hardware. */
    vref_config_t vrefConfig;

    /* attach FRO 12M to FLEXCOMM4 (debug console) */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /* attach FRO 12M to CMP0 */
    CLOCK_SetClkDiv(kCLOCK_DivCmp0FClk, 1u);
    CLOCK_AttachClk(kFRO12M_to_CMP0F);

    /* enable VREF */
    SPC0->ACTIVE_CFG1 |= 0x1;
    /* enable CMP0 */
    SPC0->ACTIVE_CFG1 |= (0x1 << 16u);

    VREF_GetDefaultConfig(&vrefConfig);
    /* Initialize the VREF mode. */
    VREF_Init(DEMO_VREF_BASE, &vrefConfig);
    /* Get a 1.8V reference voltage. */
    VREF_SetTrim21Val(DEMO_VREF_BASE, 8U);

    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    PRINTF("LPCMP polling Example.\r\n");

    /*
     *   k_LpcmpConfigStruct->enableStopMode      = false;
     *   k_LpcmpConfigStruct->enableOutputPin     = false;
     *   k_LpcmpConfigStruct->useUnfilteredOutput = false;
     *   k_LpcmpConfigStruct->enableInvertOutput  = false;
     *   k_LpcmpConfigStruct->hysteresisMode      = kLPCMP_HysteresisLevel0;
     *   k_LpcmpConfigStruct->powerMode           = kLPCMP_LowSpeedPowerMode;
     */
    LPCMP_GetDefaultConfig(&mLpcmpConfigStruct);
    /* Init the LPCMP module. */
    LPCMP_Init(DEMO_LPCMP_BASE, &mLpcmpConfigStruct);

    /* Configure the internal DAC to output half of reference voltage. */
    mLpcmpDacConfigStruct.enableLowPowerMode     = false;
    mLpcmpDacConfigStruct.referenceVoltageSource = kLPCMP_VrefSourceVin2;
    mLpcmpDacConfigStruct.DACValue =
        ((LPCMP_DCR_DAC_DATA_MASK >> LPCMP_DCR_DAC_DATA_SHIFT) >> 1U); /* Half of reference voltage. */
    LPCMP_SetDACConfig(DEMO_LPCMP_BASE, &mLpcmpDacConfigStruct);

    /* Configure LPCMP input channels. */
    LPCMP_SetInputChannels(DEMO_LPCMP_BASE, DEMO_LPCMP_USER_CHANNEL, DEMO_LPCMP_DAC_CHANNEL);

    /* Init the LED. */
    LED_INIT();

    while (1)
    {
        if (0U == (kLPCMP_OutputAssertEventFlag & LPCMP_GetStatusFlags(DEMO_LPCMP_BASE)))
        {
            LED_OFF(); /* Turn off led. */
        }
        else
        {
            LED_ON(); /* Turn on led. */
        }
    }
}
