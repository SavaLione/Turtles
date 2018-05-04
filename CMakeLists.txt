# ----------------------------------------------------------------------------
#  Yenot
# ----------------------------------------------------------------------------
cmake_minimum_required (VERSION 2.6)

# Variables
# ===================================================
set ( YENOT_LOGO 1 CACHE BOOL "Show logo?")
set ( YENOT_INFORMATION 1 CACHE BOOL "Assembly Information")
set ( YENOT_INFORMATION_SOURCE 0 CACHE BOOL "Source Files")

# Logo
# ===================================================
if (YENOT_LOGO)
	set ( YENOT_LOGO_S " __     __              _   \n \\ \\   / /             | |  \n  \\ \\_/ /__ _ __   ___ | |_ \n   \\   / _ \\ '_ \\ / _ \\| __|\n    | |  __/ | | | (_) | |_ \n    |_|\\___|_| |_|\\___/ \\__|")
	message(STATUS "============================")
	message(STATUS ${YENOT_LOGO_S})
	if (NOT(YENOT_INFORMATION) AND NOT(YENOT_INFORMATION_SOURCE))
		message(STATUS "============================")
	endif()
endif()

# Linker settings
# ===================================================
set (PROJECT Yenot)

cmake_policy(SET CMP0015 NEW)

set_property( GLOBAL PROPERTY USE_FOLDERS ON )

set( CMAKE_SUPPRESS_REGENERATION true)
set( CMAKE_BUILD_TYPE RELEASE )
set( CMAKE_CONFIGURATION_TYPES "Release" )

# Lib
# ===================================================
set ( OPENCV_LIB "lib/opencv/include")
set ( OPENCV_LIB_LINK "lib/opencv/x64/vc15/lib")
set ( OPENCV_LIB_LINK_DLIB "lib/opencv/x64/vc15/lib/opencv_world341.lib")

include_directories(${OPENCV_LIB})
link_directories(${OPENCV_LIB_LINK})

#target_link_libraries (${OPENCV_LIB_LINK_DLIB})

# Core
# ===================================================
set(CORE_SOURCES
		src/core/Yenot.cpp
		src/core/Core.cpp
		src/core/Logger.cpp
)
set(CORE_HEADERS
		src/core/Yenot.h
		src/core/Core.h
		src/core/Logger.h
		
)
set (YENOT_CORE ${CORE_SOURCES} ${CORE_HEADERS})

# Information
# ===================================================
if (YENOT_INFORMATION)
	message(STATUS "==========[BILD]============")
	message(STATUS "Bild type:  " ${CMAKE_BUILD_TYPE})
	message(STATUS "Configuration type:  " ${CMAKE_BUILD_TYPE})
	message(STATUS "=========[CHECK]============")
	message(STATUS "[CMAKE_SUPPRESS_REGENERATION" ${USE_FOLDERS} "]\n"
			"[CMAKE_BUILD_TYPE " ${CMAKE_BUILD_TYPE} "]\n"
			"[CMAKE_CONFIGURATION_TYPES " ${CMAKE_CONFIGURATION_TYPES} "]"
	)
endif ()

if (YENOT_INFORMATION_SOURCE)
	message(STATUS "========[SOURCE]============")
	message(STATUS ${CORE_SOURCES} "\n" ${CORE_HEADERS} "\n" ${IO_SOURCES} "\n" ${IO_HEADERS})
endif()

# Preparation
# ===================================================
if (YENOT_INFORMATION OR YENOT_INFORMATION_SOURCE)
	message(STATUS "============================")
endif()
project (${PROJECT})
add_executable (${PROJECT} ${YENOT_CORE})

target_link_libraries(${PROJECT} ${CMAKE_SOURCE_DIR}/lib/opencv/x64/vc15/lib/opencv_world341.lib)

# Server
# ===================================================

set (PROJECT Server)

set(SERVER_SOURCES
		src/srv/YenotServer.cpp
)

set(SERVER_HEADERS
		src/srv/YenotServer.h
)

set(SERVER ${SERVER_SOURCES} ${SERVER_HEADERS})

project (${PROJECT})
add_executable (${PROJECT} ${SERVER})