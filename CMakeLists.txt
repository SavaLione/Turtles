cmake_minimum_required (VERSION 2.6)

################################
# Variables
################################
set(YENOT_SERVER 1 CACHE BOOL "Server?")
set(YENOT_TEST 1 CACHE BOOL "Use test?")

if(YENOT_SERVER)
	set(YENOT_SERVER_PROJECT "YenotServer")
endif()

if(YENOT_TEST)
	set(YENOT_TEST_PROJECT "YenotTest")
endif()
################################
# Logo
################################
set(YENOT_LOGO_S " __     __              _   \n \\ \\   / /             | |  \n  \\ \\_/ /__ _ __   ___ | |_ \n   \\   / _ \\ '_ \\ / _ \\| __|\n    | |  __/ | | | (_) | |_ \n    |_|\\___|_| |_|\\___/ \\__|")
message(STATUS ${YENOT_LOGO_S})

################################
# Server
################################
if(YENOT_SERVER)
	add_subdirectory(yenot/server)
endif()

################################
# Tests
################################
if(YENOT_TEST)
	add_subdirectory(yenot/tests)
endif()