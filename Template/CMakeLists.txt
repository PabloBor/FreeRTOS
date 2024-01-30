# copy the command inside the build folder:
# cmake -DCMAKE_TOOLCHAIN_FILE=../gcc-arm-none-eabi.cmake ..

# Template CMakeLists.txt configuration for STM32 MCUS
cmake_minimum_required(VERSION 3.12)
# ##############################################################################

# Set build type to Release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Edit your MCU information up to the next border
project(BLE_Project)
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/PROJECT)

set(MCU_FAMILY STM32F4xx)
set(MCU_MODEL STM32F446xx)
set(CPU_PARAMETERS
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard)

# set(STARTUP_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_stm32f446xx.s)
set(STARTUP_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup.c)
set(MCU_LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/Startup/linker_script.ld)
# ##############################################################################

set(EXECUTABLE ${CMAKE_PROJECT_NAME})

#Compiler configuration
enable_language(C ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

#OPENOCD
set(OPENOCD 
        openocd 
        -f interface/stlink.cfg 
        -f target/stm32f4x.cfg)



# ##############################################################################


# cppcheck
set(CPPCHECK cppcheck)

# cppflags
set(CPPFLAGS 
    --quiet 
    --enable=all
    --error-exitcode=1
    --inline-suppr)

################################################################################
# Headers 
#Includes Paths
set(CUBEMX_INCLUDE_DIRECTORIES
    # Core includes
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc

    # CMSIS Includes
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device_STM32F4xx/Include
    # HAL includes
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Inc
 
    # FreeRTOS includes
    ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/include
    ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/Source/portable/GCC/ARM_CM4F
    
    #Bluetooth Low Energy includes
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/hci/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/Nucleo/Inc
    )


# Sources
file(GLOB_RECURSE STM32CUBEMX_SOURCES
    # Core code
    ${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/keypad.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/usart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/syscalls.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/stm32f4xx_it.c

    # HAL sources
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/stm32f4xx_hal_timebase_tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c

    #For BLE
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c


    #CMSIS sources
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device_STM32F4xx/Source/system_stm32f4xx.c
    
    # FreeRTOS sources
    ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
    ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/Source/portable/MemMang/heap_4.c
    ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/Source/tasks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/Source/list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/Source/timers.c
    ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/Source/queue.c
    
    #Bluetooth Low Energy Sources
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/Nucleo/Src/stm32f4xx_nucleo_bus.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/hci/Src/hci_tl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/hci/Src/hci_tl_interface.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/hci/Src/bluenrg1_events_cb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/hci/Src/bluenrg1_events.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/hci/Src/bluenrg1_gap_aci.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/hci/Src/bluenrg1_gatt_aci.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/hci/Src/bluenrg1_hci_le.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/hci/Src/bluenrg1_hal_aci.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BLE/Src/ble_list.c

    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/service.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/app_bluenerg.c
    
    )

set(CPPINC ${STM32CUBEMX_SOURCES})

# Executable files
add_executable(${EXECUTABLE}
${STM32CUBEMX_SOURCES} 
#${PROJECT_SOURCES}
${STARTUP_SCRIPT})

# Embedded macros(defines)
target_compile_definitions(${EXECUTABLE} PRIVATE
    ${MCU_MODEL}
    USE_HAL_DRIVER)

# Add header directories (AFTER add_executable !!)
target_include_directories(${EXECUTABLE} PRIVATE
    ${CUBEMX_INCLUDE_DIRECTORIES})


# Compiler and linker options
target_compile_options(${EXECUTABLE} PRIVATE
    ${CPU_PARAMETERS}
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
    $<$<CONFIG:Debug>:-Og -g0 -ggdb>
    $<$<CONFIG:Release>:-Og -g0>)

target_link_options(${EXECUTABLE} PRIVATE
    -T${MCU_LINKER_SCRIPT}
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    --specs=nosys.specs
    -Wl,--start-group
    -lc
    -lm
    #-lstdc++
    -lgcc
    -Wl,--end-group
    -Wl,--print-memory-usage)

add_custom_target(flash
            COMMAND ${OPENOCD} -c "program BLE_Project.elf verify reset exit"
            COMMENT "Flashing...")

add_custom_target(erase
            COMMAND ${OPENOCD} -c "init; reset halt; stm32f2x mass_erase 0; exit"
            COMMENT "erased")

add_custom_target(clear
            COMMAND rm -rf ${CMAKE_CURRENT_SOURCE_DIR}/build/*
            COMMENT "All file clean"
)
add_custom_target(cppcheck
            COMMAND ${CPPCHECK} ${CPPFLAGS} ${CPPINC})