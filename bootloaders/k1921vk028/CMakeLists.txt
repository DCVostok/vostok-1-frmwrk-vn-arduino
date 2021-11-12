#-- Service --------------------------------------------------------------------
SET(CMAKE_TOOLCHAIN_FILE ./gcc_cm4f.cmake)
ENABLE_LANGUAGE(ASM)
CMAKE_MINIMUM_REQUIRED(VERSION 3.8.0)
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    MESSAGE(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt." )
ENDIF()
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#-- Project name ---------------------------------------------------------------
PROJECT(boot028)

#-- Defines --------------------------------------------------------------------
ADD_DEFINITIONS(-DK1921VK028)
ADD_DEFINITIONS(-D__NO_SYSTEM_INIT)
ADD_DEFINITIONS(-DUART_NUMBER=0)

#-- Project paths --------------------------------------------------------------
SET(APP_PATH                app)
SET(PLATFORM_PATH           platform)
SET(CMSIS_CORE_INC_PATH     ${PLATFORM_PATH}/CMSIS/Core/Include)
SET(DEVICE_SRC_PATH         ${PLATFORM_PATH}/Device/NIIET/K1921VK028/Source/GCC)
SET(DEVICE_INC_PATH         ${PLATFORM_PATH}/Device/NIIET/K1921VK028/Include)


#-- Include dirs ---------------------------------------------------------------
INCLUDE_DIRECTORIES(${APP_PATH})
INCLUDE_DIRECTORIES(${CMSIS_CORE_INC_PATH})
INCLUDE_DIRECTORIES(${DEVICE_INC_PATH})

#-- Sources list ---------------------------------------------------------------
#FILE(GLOB_RECURSE APP_SRC ${APP_PATH}/*.c)
#LIST(APPEND APP_SRC ${DEVICE_SRC_PATH}/startup_K1921VK028.S)

LIST(APPEND APP_SRC ${DEVICE_SRC_PATH}/startup_K1921VK028.S)
FILE(GLOB_RECURSE APP_SRC_C ${APP_PATH}/*.c)
LIST(APPEND APP_SRC ${APP_SRC_C})


#-- Linker script --------------------------------------------------------------
SET(LDSCRIPT ${CMAKE_SOURCE_DIR}/${DEVICE_SRC_PATH}/K1921VK028.ld)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${LDSCRIPT} -Wl,-Map=${CMAKE_BINARY_DIR}/${PROJECT_NAME}.map -Wl,--print-memory-usage")

#-- Project linking ------------------------------------------------------------
ADD_EXECUTABLE(${PROJECT_NAME}.elf ${APP_SRC})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}.elf)

#-- Custom commands ------------------------------------------------------------
ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} "-Oihex" ${PROJECT_NAME}.elf ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.hex
        COMMAND ${CMAKE_OBJCOPY} "-Obinary" ${PROJECT_NAME}.elf ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.bin
        COMMAND ${CMAKE_OBJDUMP} "-DS" ${PROJECT_NAME}.elf > ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.dasm
        COMMAND ${CMAKE_SIZE} ${PROJECT_NAME}.elf
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.bin ../init/${PROJECT_NAME}.bin)
