/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "mcuxCsslExamples.h"
#include "els_pkc_asymmetric.h"

#include "fsl_clock.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    char ch;
    uint8_t pass = 0;
    uint8_t fail = 0;

    /* Init board hardware. */
    /* attach FRO 12M to FLEXCOMM4 (debug console) */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    PRINTF("\r\nELS PKC asymmetric cipher example\r\n");
    PRINTF("\r\n============================\r\n");

    PRINTF("PKC ECC keygen sign verify:");
    if (ecc_keygen_sign_verify() == true)
    {
        pass++;
        PRINTF("pass \r\n");
    }
    else
    {
        fail++;
        PRINTF("fail \r\n");
    }

    PRINTF("PKC RSA no-verify:");
    if (mcuxClRsa_verify_NoVerify_example() == true)
    {
        pass++;
        PRINTF("pass \r\n");
    }
    else
    {
        fail++;
        PRINTF("fail \r\n");
    }

    PRINTF("PKC RSA sign no-encode:");
    if (mcuxClRsa_sign_NoEncode_example() == true)
    {
        pass++;
        PRINTF("pass \r\n");
    }
    else
    {
        fail++;
        PRINTF("fail \r\n");
    }

    PRINTF("PKC RSA-PSS sign SHA256:");
    if (mcuxClRsa_sign_pss_sha2_256_example() == true)
    {
        pass++;
        PRINTF("pass \r\n");
    }
    else
    {
        fail++;
        PRINTF("fail \r\n");
    }

    /* According to Release notes of els_pkc v1.3.0 this is failing and is kwnown issue*/
    //    PRINTF("PKC RSA-PSS verify SHA256:");
    //    if (mcuxClRsa_verify_pssverify_sha2_256_example() == true)
    //    {
    //        pass++;
    //        PRINTF("pass \r\n");
    //    }
    //    else
    //    {
    //        fail++;
    //        PRINTF("fail \r\n");
    //    }

    PRINTF("PKC ECC Curve25519:");
    if (mcuxClEcc_Mont_Curve25519_example() == true)
    {
        pass++;
        PRINTF("pass \r\n");
    }
    else
    {
        fail++;
        PRINTF("fail \r\n");
    }

    PRINTF("TLS Master session keys:");
    if (tls_master_key_session_keys() == true)
    {
        pass++;
        PRINTF("pass \r\n");
    }
    else
    {
        fail++;
        PRINTF("fail \r\n");
    }

    PRINTF("\r\n============================\r\n");
    PRINTF("RESULT: ");
    if (fail == 0)
    {
        PRINTF("All %d test PASS!!\r\n", pass);
    }
    else
    {
        PRINTF("%d / %d test PASSED, %d FAILED!!\r\n", pass, pass + fail, fail);
    }

    PRINTF("ELS example END \r\n");
    while (1)
    {
        ch = GETCHAR();
        PUTCHAR(ch);
    }
}
