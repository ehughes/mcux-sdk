# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.10.0)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(dev_mtp_lite_bm)

set(MCUX_BUILD_TYPES debug release)

set(MCUX_SDK_PROJECT_NAME dev_mtp_lite_bm.elf)

if (NOT DEFINED SdkRootDirPath)
    SET(SdkRootDirPath ${ProjDirPath}/../../../../../../..)
endif()

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/../sdmmc_config.c"
"${ProjDirPath}/../sdmmc_config.h"
"${SdkRootDirPath}/boards/mcxn9xxbrk/usb_examples/usb_device_mtp_lite/bm/ffconf.h"
"${ProjDirPath}/../mtp.c"
"${ProjDirPath}/../mtp.h"
"${ProjDirPath}/../mtp_operation.c"
"${ProjDirPath}/../mtp_operation.h"
"${ProjDirPath}/../mtp_file_system_adapter.c"
"${ProjDirPath}/../mtp_file_system_adapter.h"
"${ProjDirPath}/../mtp_object_handle.c"
"${ProjDirPath}/../mtp_object_handle.h"
"${ProjDirPath}/../usb_device_descriptor.c"
"${ProjDirPath}/../usb_device_descriptor.h"
"${ProjDirPath}/../usb_device_ch9.c"
"${ProjDirPath}/../usb_device_ch9.h"
"${ProjDirPath}/../usb_device_mtp.c"
"${ProjDirPath}/../usb_device_mtp.h"
"${ProjDirPath}/../usb_device_mtp_operation.c"
"${ProjDirPath}/../usb_device_mtp_operation.h"
"${ProjDirPath}/../usb_device_config.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${SdkRootDirPath}/boards/mcxn9xxbrk
    ${SdkRootDirPath}/boards/mcxn9xxbrk/usb_examples/usb_device_mtp_lite/bm
    ${ProjDirPath}/..
)

set(CMAKE_MODULE_PATH
    ${SdkRootDirPath}/middleware/usb
    ${SdkRootDirPath}/devices/MCXN947/drivers
    ${SdkRootDirPath}/middleware/sdmmc
    ${SdkRootDirPath}/components/gpio
    ${SdkRootDirPath}/middleware/fatfs
    ${SdkRootDirPath}/middleware
    ${SdkRootDirPath}/devices/MCXN947
    ${SdkRootDirPath}/devices/MCXN947/utilities
    ${SdkRootDirPath}/components/uart
    ${SdkRootDirPath}/components/serial_manager
    ${SdkRootDirPath}/components/lists
    ${SdkRootDirPath}/components/osa
    ${SdkRootDirPath}/CMSIS/Core/Include
)

# include modules
include(middleware_usb_device_khci_MCXN947_cm33_core0)

include(middleware_usb_device_ehci_MCXN947_cm33_core0)

include(middleware_usb_phy_MCXN947_cm33_core0)

include(driver_usdhc_MCXN947_cm33_core0)

include(middleware_sdmmc_sd_MCXN947_cm33_core0)

include(middleware_sdmmc_common_MCXN947_cm33_core0)

include(middleware_sdmmc_host_usdhc_MCXN947_cm33_core0)

include(middleware_sdmmc_host_usdhc_interrupt_MCXN947_cm33_core0)

include(component_gpio_adapter_MCXN947_cm33_core0)

include(middleware_fatfs_MCXN947_cm33_core0)

include(middleware_fatfs_sd_MCXN947_cm33_core0)

include(middleware_baremetal_MCXN947_cm33_core0)

include(driver_clock_MCXN947_cm33_core0)

include(driver_common_MCXN947_cm33_core0)

include(device_MCXN947_CMSIS_MCXN947_cm33_core0)

include(device_MCXN947_startup_MCXN947_cm33_core0)

include(driver_lpuart_MCXN947_cm33_core0)

include(driver_port_MCXN947_cm33_core0)

include(driver_gpio_MCXN947_cm33_core0)

include(utility_assert_MCXN947_cm33_core0)

include(utility_debug_console_MCXN947_cm33_core0)

include(component_lpuart_adapter_MCXN947_cm33_core0)

include(component_serial_manager_MCXN947_cm33_core0)

include(component_lists_MCXN947_cm33_core0)

include(component_serial_manager_uart_MCXN947_cm33_core0)

include(middleware_usb_device_controller_driver_MCXN947_cm33_core0)

include(component_osa_MCXN947_cm33_core0)

include(middleware_usb_device_common_header_MCXN947_cm33_core0)

include(driver_reset_MCXN947_cm33_core0)

include(CMSIS_Include_core_cm_MCXN947_cm33_core0)

include(middleware_usb_common_header_MCXN947_cm33_core0)

include(middleware_sdmmc_osa_bm_MCXN947_cm33_core0)

include(component_osa_bm_MCXN947_cm33_core0)

include(utilities_misc_utilities_MCXN947_cm33_core0)

include(device_MCXN947_system_MCXN947_cm33_core0)

include(driver_lpflexcomm_MCXN947_cm33_core0)


IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)  
    SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")  
ENDIF()  

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


