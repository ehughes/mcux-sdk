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


project(dev_composite_cdc_msc_disk_lite_bm)

set(MCUX_BUILD_TYPES debug release)

set(MCUX_SDK_PROJECT_NAME dev_composite_cdc_msc_disk_lite_bm.elf)

if (NOT DEFINED SdkRootDirPath)
    SET(SdkRootDirPath ${ProjDirPath}/../../../../../../..)
endif()

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/../usb_disk_adapter.h"
"${ProjDirPath}/../usb_sdcard_adapter.c"
"${ProjDirPath}/../sdmmc_config.c"
"${ProjDirPath}/../sdmmc_config.h"
"${ProjDirPath}/../composite.c"
"${ProjDirPath}/../composite.h"
"${ProjDirPath}/../disk.c"
"${ProjDirPath}/../disk.h"
"${ProjDirPath}/../usb_device_descriptor.c"
"${ProjDirPath}/../usb_device_descriptor.h"
"${ProjDirPath}/../usb_device_cdc_acm.c"
"${ProjDirPath}/../usb_device_cdc_acm.h"
"${ProjDirPath}/../usb_device_ch9.c"
"${ProjDirPath}/../usb_device_ch9.h"
"${ProjDirPath}/../usb_device_msc.c"
"${ProjDirPath}/../usb_device_msc.h"
"${ProjDirPath}/../usb_device_msc_ufi.c"
"${ProjDirPath}/../usb_device_msc_ufi.h"
"${ProjDirPath}/../virtual_com.c"
"${ProjDirPath}/../virtual_com.h"
"${ProjDirPath}/../usb_device_config.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${ProjDirPath}/..
    ${SdkRootDirPath}/boards/mcxn9xxbrk
    ${SdkRootDirPath}/boards/mcxn9xxbrk/usb_examples/usb_device_composite_cdc_msc_disk_lite/bm
)

set(CMAKE_MODULE_PATH
    ${SdkRootDirPath}/middleware/usb
    ${SdkRootDirPath}/devices/MCXN947/drivers
    ${SdkRootDirPath}/middleware/sdmmc
    ${SdkRootDirPath}/devices/MCXN947/utilities
    ${SdkRootDirPath}/devices/MCXN947/utilities/debug_console_lite
    ${SdkRootDirPath}/components/gpio
    ${SdkRootDirPath}/middleware
    ${SdkRootDirPath}/devices/MCXN947
    ${SdkRootDirPath}/components/uart
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

include(utility_debug_console_lite_MCXN947_cm33_core0)

include(utility_assert_lite_MCXN947_cm33_core0)

include(component_gpio_adapter_MCXN947_cm33_core0)

include(middleware_baremetal_MCXN947_cm33_core0)

include(driver_clock_MCXN947_cm33_core0)

include(driver_common_MCXN947_cm33_core0)

include(device_MCXN947_CMSIS_MCXN947_cm33_core0)

include(device_MCXN947_startup_MCXN947_cm33_core0)

include(driver_lpuart_MCXN947_cm33_core0)

include(driver_port_MCXN947_cm33_core0)

include(driver_gpio_MCXN947_cm33_core0)

include(component_lpuart_adapter_MCXN947_cm33_core0)

include(component_lists_MCXN947_cm33_core0)

include(middleware_usb_device_controller_driver_MCXN947_cm33_core0)

include(component_osa_MCXN947_cm33_core0)

include(middleware_usb_device_common_header_MCXN947_cm33_core0)

include(driver_reset_MCXN947_cm33_core0)

include(CMSIS_Include_core_cm_MCXN947_cm33_core0)

include(middleware_usb_common_header_MCXN947_cm33_core0)

include(middleware_sdmmc_osa_bm_MCXN947_cm33_core0)

include(component_osa_bm_MCXN947_cm33_core0)

include(driver_lpflexcomm_MCXN947_cm33_core0)

include(utilities_misc_utilities_MCXN947_cm33_core0)

include(device_MCXN947_system_MCXN947_cm33_core0)


IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)  
    SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")  
ENDIF()  

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


