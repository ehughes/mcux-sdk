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


project(els_pkc_asymmetric)

set(MCUX_BUILD_TYPES debug release)

set(MCUX_SDK_PROJECT_NAME els_pkc_asymmetric.elf)

if (NOT DEFINED SdkRootDirPath)
    SET(SdkRootDirPath ${ProjDirPath}/../../../../../..)
endif()

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/../els_pkc_asymmetric.c"
"${ProjDirPath}/../els_pkc_asymmetric.h"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${ProjDirPath}/..
)

set(CMAKE_MODULE_PATH
    ${SdkRootDirPath}/devices/MCXN947/utilities
    ${SdkRootDirPath}/devices/MCXN947/utilities/debug_console_lite
    ${SdkRootDirPath}/components/els_pkc
    ${SdkRootDirPath}/devices/MCXN947/drivers
    ${SdkRootDirPath}/devices/MCXN947
    ${SdkRootDirPath}/components/uart
    ${SdkRootDirPath}/components/lists
    ${SdkRootDirPath}/CMSIS/Core/Include
)

# include modules
include(utility_debug_console_lite_MCXN947_cm33_core0)

include(utility_assert_lite_MCXN947_cm33_core0)

include(component_els_pkc_MCXN947_cm33_core0)

include(component_els_pkc_test_MCXN947_cm33_core0)

include(driver_common_MCXN947_cm33_core0)

include(driver_clock_MCXN947_cm33_core0)

include(driver_power_MCXN947_cm33_core0)

include(device_MCXN947_CMSIS_MCXN947_cm33_core0)

include(device_MCXN947_startup_MCXN947_cm33_core0)

include(driver_lpuart_MCXN947_cm33_core0)

include(driver_port_MCXN947_cm33_core0)

include(driver_gpio_MCXN947_cm33_core0)

include(component_lpuart_adapter_MCXN947_cm33_core0)

include(component_lists_MCXN947_cm33_core0)

include(driver_reset_MCXN947_cm33_core0)

include(CMSIS_Include_core_cm_MCXN947_cm33_core0)

include(driver_lpflexcomm_MCXN947_cm33_core0)

include(component_els_pkc_platform_mcxn_MCXN947_cm33_core0)

include(component_els_MCXN947_cm33_core0)

include(component_els_hash_MCXN947_cm33_core0)

include(component_els_pkc_session_MCXN947_cm33_core0)

include(component_els_pkc_flow_protection_MCXN947_cm33_core0)

include(component_els_pkc_secure_counter_MCXN947_cm33_core0)

include(component_els_pkc_pre_processor_MCXN947_cm33_core0)

include(component_els_pkc_memory_MCXN947_cm33_core0)

include(component_els_pkc_param_integrity_MCXN947_cm33_core0)

include(component_els_pkc_common_MCXN947_cm33_core0)

include(component_els_pkc_key_MCXN947_cm33_core0)

include(component_els_pkc_mac_MCXN947_cm33_core0)

include(component_els_aes_MCXN947_cm33_core0)

include(component_els_prng_MCXN947_cm33_core0)

include(component_pkc_MCXN947_cm33_core0)

include(component_els_pkc_ecc_MCXN947_cm33_core0)

include(component_els_pkc_math_MCXN947_cm33_core0)

include(component_els_pkc_rsa_MCXN947_cm33_core0)

include(component_els_pkc_random_MCXN947_cm33_core0)

include(component_els_pkc_core_MCXN947_cm33_core0)

include(component_els_pkc_padding_MCXN947_cm33_core0)

include(component_els_cipher_MCXN947_cm33_core0)

include(component_els_ciphermodes_MCXN947_cm33_core0)

include(component_els_aead_MCXN947_cm33_core0)

include(component_els_aeadmodes_MCXN947_cm33_core0)

include(component_els_pkc_random_modes_MCXN947_cm33_core0)

include(component_els_pkc_trng_MCXN947_cm33_core0)

include(component_els_pkc_macmodes_MCXN947_cm33_core0)

include(component_els_oscca_sm3_MCXN947_cm33_core0)

include(utilities_misc_utilities_MCXN947_cm33_core0)

include(device_MCXN947_system_MCXN947_cm33_core0)


IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)  
    SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")  
ENDIF()  

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


