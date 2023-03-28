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


project(host_msd_fatfs_freertos)

set(MCUX_BUILD_TYPES debug release)

set(MCUX_SDK_PROJECT_NAME host_msd_fatfs_freertos.elf)

if (NOT DEFINED SdkRootDirPath)
    SET(SdkRootDirPath ${ProjDirPath}/../../../../../../..)
endif()

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/../app.h"
"${ProjDirPath}/../app.c"
"${ProjDirPath}/../host_msd_fatfs.c"
"${ProjDirPath}/../ffconf.h"
"${ProjDirPath}/../host_msd_fatfs.h"
"${ProjDirPath}/../usb_host_config.h"
"${ProjDirPath}/../FreeRTOSConfig.h"
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
)

set(CMAKE_MODULE_PATH
    ${SdkRootDirPath}/middleware/usb
    ${SdkRootDirPath}/rtos/freertos/freertos-kernel
    ${SdkRootDirPath}/middleware/fatfs
    ${SdkRootDirPath}/devices/MCXN947/drivers
    ${SdkRootDirPath}/devices/MCXN947
    ${SdkRootDirPath}/devices/MCXN947/utilities
    ${SdkRootDirPath}/components/uart
    ${SdkRootDirPath}/components/serial_manager
    ${SdkRootDirPath}/components/lists
    ${SdkRootDirPath}/components/osa
    ${SdkRootDirPath}/CMSIS/Core/Include
)

# include modules
include(middleware_usb_host_khci_MCXN947_cm33_core0)

include(middleware_usb_host_ehci_MCXN947_cm33_core0)

include(middleware_usb_phy_MCXN947_cm33_core0)

include(middleware_freertos-kernel_heap_4_MCXN947_cm33_core0)

include(middleware_freertos-kernel_MCXN947_cm33_core0)

include(middleware_fatfs_MCXN947_cm33_core0)

include(middleware_fatfs_usb_MCXN947_cm33_core0)

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

include(middleware_freertos-kernel_cm33_nonsecure_port_MCXN947_cm33_core0)

include(component_serial_manager_MCXN947_cm33_core0)

include(component_lists_MCXN947_cm33_core0)

include(component_serial_manager_uart_MCXN947_cm33_core0)

include(middleware_usb_host_stack_MCXN947_cm33_core0)

include(component_osa_MCXN947_cm33_core0)

include(middleware_usb_host_common_header_MCXN947_cm33_core0)

include(driver_reset_MCXN947_cm33_core0)

include(CMSIS_Include_core_cm_MCXN947_cm33_core0)

include(middleware_usb_common_header_MCXN947_cm33_core0)

include(middleware_freertos-kernel_extension_MCXN947_cm33_core0)

include(middleware_usb_host_msd_MCXN947_cm33_core0)

include(utilities_misc_utilities_MCXN947_cm33_core0)

include(device_MCXN947_system_MCXN947_cm33_core0)

include(driver_lpflexcomm_MCXN947_cm33_core0)


IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)  
    SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")  
ENDIF()  

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


