/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*  Standard C Included Files */
#include <string.h>
/*  SDK Included Files */
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_component_i3c.h"

#include "fsl_component_i3c_adapter.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_MASTER             I3C1
#define EXAMPLE_I2C_BAUDRATE       400000U
#define I3C_MASTER_CLOCK_FREQUENCY 1000000U
#define I3C_MASTER_SLAVE_ADDR_7BIT 0x1E


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
i3c_bus_t demo_i3cBus;
i3c_device_t demo_slaveDev;
/*******************************************************************************
 * Code
 ******************************************************************************/
i3c_master_adapter_resource_t demo_masterResource = {.base      = EXAMPLE_MASTER,
                                                     .transMode = kI3C_MasterTransferInterruptMode};
i3c_device_control_info_t i3cMasterCtlInfo        = {
    .funcs = (i3c_device_hw_ops_t *)&master_ops, .resource = &demo_masterResource, .isSecondary = true};


/*!
 * @brief Main function
 */
int main(void)
{
    /* attach FRO 12M to FLEXCOMM4 (debug console) */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1U);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /* Attach PLL0 clock to I3C, 150MHz / 6 = 25MHz. */
    CLOCK_SetClkDiv(kCLOCK_DivI3c1FClk, 6U);
    CLOCK_AttachClk(kPLL0_to_I3C1FCLK);

    CLOCK_SetClkDiv(kCLOCK_DivI3c0FClkStc, 1U);
    CLOCK_AttachClk(kI3C0FCLK_to_I3C0FCLKSTC);

    SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_MASK;
    CLOCK_SetClkDiv(kCLOCK_DivI3c1FClkS, 1U);
    CLOCK_AttachClk(kCLK_1M_to_I3C1FCLKS);

    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    demo_masterResource.clockInHz = I3C_MASTER_CLOCK_FREQUENCY;

    PRINTF("\r\nI3C bus slave example.\r\n");

    /* Create I3C bus, work as secondary master. */
    i3c_bus_config_t busConfig;
    I3C_BusGetDefaultBusConfig(&busConfig);
    I3C_BusCreate(&demo_i3cBus, &busConfig);
    i3c_device_information_t masterInfo;
    memset(&masterInfo, 0, sizeof(masterInfo));
    masterInfo.staticAddr = I3C_MASTER_SLAVE_ADDR_7BIT;
    masterInfo.bcr        = 0x60U;
    masterInfo.dcr        = 0x00U;
    masterInfo.vendorID   = 0x346U;

    extern i3c_device_control_info_t i3cMasterCtlInfo;
    I3C_BusMasterCreate(&demo_slaveDev, &demo_i3cBus, &masterInfo, &i3cMasterCtlInfo);

    PRINTF("\r\nI3C bus secondary master creates.\r\n");

    /* Wait for address assignment finish. */
    while (EXAMPLE_MASTER->SDYNADDR == 0U)
        ;

    PRINTF("\r\nI3C bus second master requires to be primary master.\r\n");

    /* Request mastership. */
    I3C_BusSlaveRequestMasterShip(&demo_slaveDev);

    /* Wait for mastership takeover. */
    while (demo_i3cBus.currentMaster != &demo_slaveDev)
        ;

    PRINTF("\r\nI3C bus mastership takeover.\r\n");

    i3c_device_information_t devInfo;
    uint8_t slaveAddr = 0xFF;

    for (list_element_handle_t listItem = demo_i3cBus.i3cDevList.head; listItem != NULL; listItem = listItem->next)
    {
        if ((i3c_device_t *)listItem == &demo_slaveDev)
        {
            continue;
        }
        else
        {
            slaveAddr = ((i3c_device_t *)listItem)->info.dynamicAddr;
            break;
        }
    }
    I3C_BusMasterGetDeviceInfo(&demo_slaveDev, slaveAddr, &devInfo);

    while (1)
    {
    }
}
