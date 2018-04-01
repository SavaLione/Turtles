# ----------------------------------------------------------------------------
#  projectname
#
#    comment
#      comment
#
# ----------------------------------------------------------------------------
cmake_minimum_required (VERSION 2.6)

# Linker settings
# ===================================================
set (PROJECT projectname)

set_property( GLOBAL PROPERTY USE_FOLDERS ON )

set( CMAKE_SUPPRESS_REGENERATION true)
set( CMAKE_BUILD_TYPE RELEASE )
set( CMAKE_CONFIGURATION_TYPES "Release;Debug" )

# Lib
# ===================================================
set ( OPENCV_LIB lib/opencv/include)
set ( OPENCV_LIB_LINK lib/opencv/x64/vc15/lib)
set ( OPENCV_LIB_LINK_DLIB lib/opencv/x64/vc15/lib/opencv_world341.lib)

include_directories(${OPENCV_LIB})
link_directories(${OPENCV_LIB_LINK})

target_link_libraries (${OPENCV_LIB_LINK_DLIB})

# Information
# ===================================================
message(STATUS "Bild type:  " ${CMAKE_BUILD_TYPE})
message(STATUS "Configuration type:  " ${CMAKE_BUILD_TYPE})
message(STATUS "---------[CHECK]-----------" )
message(STATUS "[CMAKE_SUPPRESS_REGENERATION " ${USE_FOLDERS} "]" "[CMAKE_BUILD_TYPE " ${CMAKE_BUILD_TYPE} "]" "[CMAKE_CONFIGURATION_TYPES " ${CMAKE_CONFIGURATION_TYPES} "]" )
message(STATUS "--------[PROJECT]----------" )

project (${PROJECT})

# Core
# ===================================================
set (CORE_SOURCES src/core/Main.cpp)

# Preparation
# ===================================================
add_executable (${PROJECT} ${CORE_SOURCES})

target_link_libraries(${PROJECT} ${CMAKE_SOURCE_DIR}/lib/opencv/x64/vc15/lib/opencv_world341.lib)