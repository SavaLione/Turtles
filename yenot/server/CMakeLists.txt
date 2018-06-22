project(${YENOT_SERVER_PROJECT})

################################
# Linker settings
################################

cmake_policy(SET CMP0015 NEW)
set_property( GLOBAL PROPERTY USE_FOLDERS ON )
set( CMAKE_SUPPRESS_REGENERATION true)
set( CMAKE_BUILD_TYPE RELEASE )
set( CMAKE_CONFIGURATION_TYPES "Release" )

################################
# Sources
################################
set(HEADERS_SERVER
		src/Yenot.h
		src/Core.h
		src/Logger.h
		src/Settings.h
)

set(SOURCES_SERVER
		src/Yenot.cpp
		src/Core.cpp
		src/Logger.cpp
		src/Settings.cpp
)

add_executable (${YENOT_SERVER_PROJECT} ${HEADERS_SERVER} ${SOURCES_SERVER})

################################
# Lib
################################
set(OPENCV_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/opencv/include" CACHE PATH "OpenCV lib include")
set(OPENCV_LIB "${CMAKE_SOURCE_DIR}/lib/opencv/x64/vc15/lib/opencv_world341.lib" CACHE FILEPATH "OpenCV *.lib file")

include_directories(${OPENCV_LIB_INCLUDE})
target_link_libraries(${YENOT_SERVER_PROJECT} ${OPENCV_LIB})