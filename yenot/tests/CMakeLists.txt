project(${YENOT_TEST_PROJECT})

################################
# Variables
################################
set(TEST_SERVER 1 CACHE BOOL "Test server?")

################################
# Linker settings
################################
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

cmake_policy(SET CMP0015 NEW)
set_property( GLOBAL PROPERTY USE_FOLDERS ON )
set( CMAKE_SUPPRESS_REGENERATION true)
set( CMAKE_BUILD_TYPE RELEASE )
set( CMAKE_CONFIGURATION_TYPES "Release" )

################################
# Sources
################################
set(SOURCES_TEST
		src/Test.cpp
)

if(TEST_SERVER)
	set(TEST_SERVER_INCLUDE "${CMAKE_SOURCE_DIR}/yenot/server/src" CACHE PATH "YenotServer include")
	include_directories(${TEST_SERVER_INCLUDE})
	set(SOURCES_TEST_SERVER
		src/server/Core.cpp
		src/server/Logger.cpp
		src/server/Settings.cpp
	)
endif()

if(TEST_SERVER)
add_executable (${YENOT_TEST_PROJECT} ${SOURCES_TEST} ${SOURCES_TEST_SERVER})
else()
add_executable (${YENOT_TEST_PROJECT} ${SOURCES_TEST})
endif()

################################
# Lib
################################
set(GTEST_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/gtest/include" CACHE PATH "GoogleTest lib include")

set(GTEST_LIB "${CMAKE_SOURCE_DIR}/lib/gtest/gtest.lib" CACHE FILEPATH "GoogleTest *.lib file")
set(GTEST_LIB_MAIN "${CMAKE_SOURCE_DIR}/lib/gtest/gtest_main.lib" CACHE FILEPATH "GoogleTest *.lib file")

set(GMOCK_LIB "${CMAKE_SOURCE_DIR}/lib/gtest/gmock.lib" CACHE FILEPATH "GoogleMock *.lib file")
set(GMOCK_LIB_MAIN "${CMAKE_SOURCE_DIR}/lib/gtest/gmock_main.lib" CACHE FILEPATH "GoogleMock *.lib file")

include_directories(${GTEST_LIB_INCLUDE})

target_link_libraries(${YENOT_TEST_PROJECT} ${GTEST_LIB})
target_link_libraries(${YENOT_TEST_PROJECT} ${GTEST_LIB_MAIN})
target_link_libraries(${YENOT_TEST_PROJECT} ${GMOCK_LIB})
target_link_libraries(${YENOT_TEST_PROJECT} ${GMOCK_LIB_MAIN})

if(TEST_SERVER)
	include_directories(${OPENCV_LIB_INCLUDE})
	target_link_libraries(${YENOT_TEST_PROJECT} ${OPENCV_LIB})
endif()