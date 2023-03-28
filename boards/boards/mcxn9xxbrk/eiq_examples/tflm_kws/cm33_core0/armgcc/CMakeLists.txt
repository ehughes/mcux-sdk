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


project(tflm_kws)

set(MCUX_BUILD_TYPES release debug)

set(MCUX_SDK_PROJECT_NAME tflm_kws.elf)

if (NOT DEFINED SdkRootDirPath)
    SET(SdkRootDirPath ${ProjDirPath}/../../../../../..)
endif()

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${SdkRootDirPath}/middleware/eiq/common/demo_info.h"
"${SdkRootDirPath}/middleware/eiq/common/model/get_top_n.cpp"
"${SdkRootDirPath}/middleware/eiq/common/model/get_top_n.h"
"${SdkRootDirPath}/middleware/eiq/common/model/model.h"
"${SdkRootDirPath}/middleware/eiq/common/model/output_postproc.h"
"${SdkRootDirPath}/middleware/eiq/common/audio/audio.h"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/common/audio/kws_mfcc.cpp"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/common/audio/kws_mfcc.hpp"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/common/audio/mfcc.cpp"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/common/audio/mfcc.hpp"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/model.cpp"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/kws/output_postproc.cpp"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/kws/audio_data.h"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/kws/demo_config.h"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/common/demo_info.cpp"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/kws/labels.h"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/kws/main.cpp"
"${SdkRootDirPath}/middleware/eiq/common/timer.h"
"${SdkRootDirPath}/middleware/eiq/common/timer.c"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
"${SdkRootDirPath}/middleware/eiq/common/audio/audio_load.cpp"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/kws/npu/model_ds_cnn_ops_npu.cpp"
"${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/kws/npu/model_data.h"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../board_init.c"
"${ProjDirPath}/../board_init.h"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/kws
    ${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/common/audio
    ${SdkRootDirPath}/middleware/eiq/common/audio
    ${SdkRootDirPath}/middleware/eiq/common/model
    ${SdkRootDirPath}/middleware/eiq/common
    ${ProjDirPath}/..
    ${SdkRootDirPath}/middleware/eiq/tensorflow-lite/examples/kws/npu
)

set(CMAKE_MODULE_PATH
    ${SdkRootDirPath}/devices/MCXN947/utilities
    ${SdkRootDirPath}/devices/MCXN947/utilities/debug_console_lite
    ${SdkRootDirPath}/CMSIS/DSP
    ${SdkRootDirPath}/middleware/eiq/tensorflow-lite
    ${SdkRootDirPath}/components/lists
    ${SdkRootDirPath}/components/uart
    ${SdkRootDirPath}/devices/MCXN947/drivers
    ${SdkRootDirPath}/devices/MCXN947
    ${SdkRootDirPath}/middleware/eiq/tensorflow-lite/tensorflow/lite/micro/kernels/neutron
    ${SdkRootDirPath}/CMSIS/Core/Include
    ${SdkRootDirPath}/middleware/eiq
    ${SdkRootDirPath}/middleware/eiq/tensorflow-lite/third_party/cmsis
    ${SdkRootDirPath}/middleware/eiq/tensorflow-lite/third_party/neutron
)

# include modules
include(utility_debug_console_lite_MCXN947_cm33_core0)

include(utility_assert_lite_MCXN947_cm33_core0)

include(CMSIS_DSP_Source_MCXN947_cm33_core0)

include(middleware_eiq_tensorflow_lite_micro_MCXN947_cm33_core0)

include(component_lists_MCXN947_cm33_core0)

include(component_lpuart_adapter_MCXN947_cm33_core0)

include(driver_common_MCXN947_cm33_core0)

include(driver_lpuart_MCXN947_cm33_core0)

include(device_MCXN947_CMSIS_MCXN947_cm33_core0)

include(device_MCXN947_startup_MCXN947_cm33_core0)

include(driver_port_MCXN947_cm33_core0)

include(driver_clock_MCXN947_cm33_core0)

include(driver_gpio_MCXN947_cm33_core0)

include(middleware_eiq_tensorflow_lite_micro_cmsis_nn_MCXN947_cm33_core0)

include(middleware_eiq_tensorflow_lite_micro_neutron_MCXN947_cm33_core0)

include(driver_reset_MCXN947_cm33_core0)

include(CMSIS_Include_core_cm_MCXN947_cm33_core0)

include(driver_lpflexcomm_MCXN947_cm33_core0)

include(middleware_eiq_tensorflow_lite_micro_third_party_flatbuffers_MCXN947_cm33_core0)

include(middleware_eiq_tensorflow_lite_micro_third_party_gemmlowp_MCXN947_cm33_core0)

include(middleware_eiq_tensorflow_lite_micro_third_party_ruy_MCXN947_cm33_core0)

include(utilities_misc_utilities_MCXN947_cm33_core0)

include(device_MCXN947_system_MCXN947_cm33_core0)

include(middleware_eiq_tensorflow_lite_micro_third_party_cmsis_nn_MCXN947_cm33_core0)

include(middleware_eiq_tensorflow_lite_micro_third_party_neutron_lib_binary_MCXN947_cm33_core0)


IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)  
    SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")  
ENDIF()  

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

if(CMAKE_BUILD_TYPE STREQUAL release)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${ProjDirPath}/../../../../../../middleware/eiq/tensorflow-lite/third_party/neutron/libnd.a)
endif(CMAKE_BUILD_TYPE STREQUAL release)

if(CMAKE_BUILD_TYPE STREQUAL release)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${ProjDirPath}/../../../../../../middleware/eiq/tensorflow-lite/third_party/neutron/libnfw.a)
endif(CMAKE_BUILD_TYPE STREQUAL release)

if(CMAKE_BUILD_TYPE STREQUAL debug)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${ProjDirPath}/../../../../../../middleware/eiq/tensorflow-lite/third_party/neutron/libnd.a)
endif(CMAKE_BUILD_TYPE STREQUAL debug)

if(CMAKE_BUILD_TYPE STREQUAL debug)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${ProjDirPath}/../../../../../../middleware/eiq/tensorflow-lite/third_party/neutron/libnfw.a)
endif(CMAKE_BUILD_TYPE STREQUAL debug)

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


