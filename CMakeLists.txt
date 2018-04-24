# ----------------------------------------------------------------------------
#  Yenot
#
#    comment
#      comment
#
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

set ( OPENCV_LIB_LINK_DLIB 
		"lib/opencv/x64/vc15/lib/opencv_aruco400.lib"
		"lib/opencv/x64/vc15/lib/opencv_bgsegm400.lib"
		"lib/opencv/x64/vc15/lib/opencv_bioinspired400.lib"
		"lib/opencv/x64/vc15/lib/opencv_calib3d400.lib"
		"lib/opencv/x64/vc15/lib/opencv_ccalib400.lib"
		"lib/opencv/x64/vc15/lib/opencv_core400.lib"
		"lib/opencv/x64/vc15/lib/opencv_datasets400.lib"
		"lib/opencv/x64/vc15/lib/opencv_dnn_objdetect400.lib"
		"lib/opencv/x64/vc15/lib/opencv_dnn400.lib"
		"lib/opencv/x64/vc15/lib/opencv_dpm400.lib"
		"lib/opencv/x64/vc15/lib/opencv_face400.lib"
		"lib/opencv/x64/vc15/lib/opencv_features2d400.lib"
		"lib/opencv/x64/vc15/lib/opencv_flann400.lib"
		"lib/opencv/x64/vc15/lib/opencv_fuzzy400.lib"
		"lib/opencv/x64/vc15/lib/opencv_hfs400.lib"
		"lib/opencv/x64/vc15/lib/opencv_highgui400.lib"
		"lib/opencv/x64/vc15/lib/opencv_img_hash400.lib"
		"lib/opencv/x64/vc15/lib/opencv_imgcodecs400.lib"
		"lib/opencv/x64/vc15/lib/opencv_imgproc400.lib"
		"lib/opencv/x64/vc15/lib/opencv_line_descriptor400.lib"
		"lib/opencv/x64/vc15/lib/opencv_ml400.lib"
		"lib/opencv/x64/vc15/lib/opencv_objdetect400.lib"
		"lib/opencv/x64/vc15/lib/opencv_optflow400.lib"
		"lib/opencv/x64/vc15/lib/opencv_phase_unwrapping400.lib"
		"lib/opencv/x64/vc15/lib/opencv_photo400.lib"
		"lib/opencv/x64/vc15/lib/opencv_plot400.lib"
		"lib/opencv/x64/vc15/lib/opencv_reg400.lib"
		"lib/opencv/x64/vc15/lib/opencv_rgbd400.lib"
		"lib/opencv/x64/vc15/lib/opencv_saliency400.lib"
		"lib/opencv/x64/vc15/lib/opencv_shape400.lib"
		"lib/opencv/x64/vc15/lib/opencv_stereo400.lib"
		"lib/opencv/x64/vc15/lib/opencv_stitching400.lib"
		"lib/opencv/x64/vc15/lib/opencv_structured_light400.lib"
		"lib/opencv/x64/vc15/lib/opencv_superres400.lib"
		"lib/opencv/x64/vc15/lib/opencv_surface_matching400.lib"
		"lib/opencv/x64/vc15/lib/opencv_text400.lib"
		"lib/opencv/x64/vc15/lib/opencv_tracking400.lib"
		"lib/opencv/x64/vc15/lib/opencv_ts400.lib"
		"lib/opencv/x64/vc15/lib/opencv_video400.lib"
		"lib/opencv/x64/vc15/lib/opencv_videoio400.lib"
		"lib/opencv/x64/vc15/lib/opencv_videostab400.lib"
		"lib/opencv/x64/vc15/lib/opencv_xfeatures2d400.lib"
		"lib/opencv/x64/vc15/lib/opencv_ximgproc400.lib"
		"lib/opencv/x64/vc15/lib/opencv_xobjdetect400.lib"
		"lib/opencv/x64/vc15/lib/opencv_xphoto400.lib"
)

include_directories(${OPENCV_LIB})
link_directories(${OPENCV_LIB_LINK})

#target_link_libraries (${OPENCV_LIB_LINK_DLIB})

# Core
# ===================================================
set(CORE_SOURCES
		src/core/Yenot.cpp
		src/core/Core.cpp
)
set(CORE_HEADERS
		src/core/Yenot.h
		src/core/Core.h
)
set (YENOT_CORE ${CORE_SOURCES} ${CORE_HEADERS})

# IO
# ===================================================
set(IO_SOURCES
		src/io/Logger.cpp
)

set(IO_HEADERS
		src/io/Logger.h
)

set (YENOT_IO ${IO_SOURCES} ${IO_HEADERS})

# Yenot sources
# ===================================================
set(YENOT_SOURCES
		${YENOT_CORE}
		${YENOT_IO}
)

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
add_executable (${PROJECT} ${YENOT_SOURCES})

target_link_libraries(${PROJECT} ${CMAKE_SOURCE_DIR}/lib/opencv/x64/vc15/lib/opencv_world341.lib)