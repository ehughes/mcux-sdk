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


project(erpc_two_way_rpc_rpmsg_rtos_cm33_core0)

set(MCUX_BUILD_TYPES debug release)

set(MCUX_SDK_PROJECT_NAME erpc_two_way_rpc_rpmsg_rtos_cm33_core0.elf)

if (NOT DEFINED SdkRootDirPath)
    SET(SdkRootDirPath ${ProjDirPath}/../../../../../..)
endif()

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common/erpc_error_handler.h"
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common/erpc_error_handler.cpp"
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common/erpc_two_way_rpc/service/erpc_two_way_rpc.erpc"
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common/erpc_two_way_rpc/service/erpc_two_way_rpc_Core0Interface.h"
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common/erpc_two_way_rpc/service/erpc_two_way_rpc_Core0Interface_client.cpp"
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common/erpc_two_way_rpc/service/erpc_two_way_rpc_Core1Interface.h"
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common/erpc_two_way_rpc/service/erpc_two_way_rpc_Core1Interface_server.h"
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common/erpc_two_way_rpc/service/erpc_two_way_rpc_Core1Interface_server.cpp"
"${ProjDirPath}/../main_core0.c"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_two_way_rpc_rpmsg_rtos/rpmsg_config.h"
"${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_two_way_rpc_rpmsg_rtos/erpc_config.h"
"${ProjDirPath}/../FreeRTOSConfig.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${ProjDirPath}/..
    ${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common
    ${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_common/erpc_two_way_rpc/service
    ${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_two_way_rpc_rpmsg_rtos
)

if(CMAKE_BUILD_TYPE STREQUAL debug)
    target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC ${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_two_way_rpc_rpmsg_rtos/cm33_core1/armgcc/debug)
endif(CMAKE_BUILD_TYPE STREQUAL debug)

if(CMAKE_BUILD_TYPE STREQUAL release)
    target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC ${SdkRootDirPath}/boards/mcxn9xxbrk/multicore_examples/erpc_two_way_rpc_rpmsg_rtos/cm33_core1/armgcc/release)
endif(CMAKE_BUILD_TYPE STREQUAL release)

set(CMAKE_MODULE_PATH
    ${SdkRootDirPath}/middleware/multicore
    ${SdkRootDirPath}/rtos/freertos/freertos-kernel
    ${SdkRootDirPath}/devices/MCXN947/utilities
    ${SdkRootDirPath}/devices/MCXN947/utilities/debug_console_lite
    ${SdkRootDirPath}/devices/MCXN947/drivers
    ${SdkRootDirPath}/devices/MCXN947/utilities/incbin
    ${SdkRootDirPath}/devices/MCXN947
    ${SdkRootDirPath}/components/uart
    ${SdkRootDirPath}/components/lists
    ${SdkRootDirPath}/CMSIS/Core/Include
)

# include modules
include(middleware_multicore_mcmgr_mcxnx4x_MCXN947_cm33_core0)

include(middleware_multicore_rpmsg_lite_mcxnx4x_freertos_MCXN947_cm33_core0)

include(middleware_multicore_rpmsg_lite_MCXN947_cm33_core0)

include(middleware_multicore_rpmsg_lite_freertos_MCXN947_cm33_core0)

include(middleware_freertos-kernel_cm33_nonsecure_port_MCXN947_cm33_core0)

include(utility_debug_console_lite_MCXN947_cm33_core0)

include(utility_assert_lite_MCXN947_cm33_core0)

include(driver_clock_MCXN947_cm33_core0)

include(middleware_multicore_erpc_eRPC_arbitrator_MCXN947_cm33_core0)

include(middleware_multicore_erpc_eRPC_rpmsg_lite_rtos_master_c_wrapper_MCXN947_cm33_core0)

include(middleware_multicore_erpc_eRPC_rpmsg_lite_rtos_transport_MCXN947_cm33_core0)

include(middleware_multicore_erpc_eRPC_port_freertos_MCXN947_cm33_core0)

include(middleware_multicore_mcmgr_MCXN947_cm33_core0)

include(middleware_freertos-kernel_MCXN947_cm33_core0)

include(middleware_freertos-kernel_heap_4_MCXN947_cm33_core0)

include(middleware_multicore_erpc_doc_MCXN947_cm33_core0)

include(utility_incbin_MCXN947_cm33_core0)

include(driver_common_MCXN947_cm33_core0)

include(device_MCXN947_CMSIS_MCXN947_cm33_core0)

include(device_MCXN947_startup_MCXN947_cm33_core0)

include(driver_lpuart_MCXN947_cm33_core0)

include(driver_port_MCXN947_cm33_core0)

include(driver_gpio_MCXN947_cm33_core0)

include(component_lpuart_adapter_MCXN947_cm33_core0)

include(component_lists_MCXN947_cm33_core0)

include(driver_mailbox_MCXN947_cm33_core0)

include(driver_reset_MCXN947_cm33_core0)

include(CMSIS_Include_core_cm_MCXN947_cm33_core0)

include(middleware_freertos-kernel_extension_MCXN947_cm33_core0)

include(driver_lpflexcomm_MCXN947_cm33_core0)

include(middleware_multicore_erpc_common_MCXN947_cm33_core0)

include(utilities_misc_utilities_MCXN947_cm33_core0)

include(device_MCXN947_system_MCXN947_cm33_core0)


IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)  
    SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")  
ENDIF()  

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


