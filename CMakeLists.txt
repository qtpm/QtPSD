cmake_minimum_required(VERSION 3.1.0)

# project global setting

project(qtpsd)

set(QTPSD_MAJOR_VERSION 1)
set(QTPSD_MINOR_VERSION 0)
set(QTPSD_PATCH_VERSION 0)
set(QTPSD_VERSION
 ${QTPSD_MAJOR_VERSION}.${QTPSD_MINOR_VERSION}.${QTPSD_PATCH_VERSION})

# compiler setting

set(CMAKE_CXX_STANDARD 11)

if(APPLE)
    set(CMAKE_MACOSX_RPATH ON)
    set(CMAKE_SKIP_BUILD_RPATH FALSE)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
    list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
    if("${isSystemDir}" STREQUAL "-1")
        set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
    endif()
endif()

# enable Qt

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
if(DEFINED ENV{QTDIR})
    set(CMAKE_PREFIX_PATH "$ENV{QTDIR}")
endif()
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)


# include extra settings

include("CMakeExtra.txt")

# build setting

include_directories("${PROJECT_SOURCE_DIR}/src")

add_library(qtpsd SHARED  ${PROJECT_SOURCE_DIR}/src/private/list/list.c ${PROJECT_SOURCE_DIR}/src/private/list/list_iterator.c ${PROJECT_SOURCE_DIR}/src/private/list/list_node.c ${PROJECT_SOURCE_DIR}/src/private/psd.c ${PROJECT_SOURCE_DIR}/src/qtpsd.cpp)
SET_TARGET_PROPERTIES(qtpsd PROPERTIES VERSION ${QTPSD_VERSION} SOVERSION ${QTPSD_MAJOR_VERSION})
qt5_use_modules(qtpsd Core Gui)


# enable tests

enable_testing()
find_package(Qt5Test REQUIRED)

add_executable(qtpsd_test ${PROJECT_SOURCE_DIR}/test/qtpsd_test.cpp ${PROJECT_SOURCE_DIR}/src/private/list/list.c ${PROJECT_SOURCE_DIR}/src/private/list/list_iterator.c ${PROJECT_SOURCE_DIR}/src/private/list/list_node.c ${PROJECT_SOURCE_DIR}/src/private/psd.c ${PROJECT_SOURCE_DIR}/src/qtpsd.cpp)
add_test(NAME qtpsd_test COMMAND qtpsd_test WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
qt5_use_modules(qtpsd_test Test Core Gui)


# install setting

INSTALL(TARGETS qtpsd LIBRARY DESTINATION lib)
INSTALL(FILES ${PROJECT_SOURCE_DIR}/src/qtpsd.h ${PROJECT_SOURCE_DIR}/src/qtpsd_global.h DESTINATION include/qtpsd)