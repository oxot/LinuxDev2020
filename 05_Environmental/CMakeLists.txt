cmake_minimum_required(VERSION 3.1)
project(rewin VERSION 0.1)
add_executable(rewin rewin.c)

find_package(Curses REQUIRED)
find_library(PCRE2_LIBRARY pcre2-8)

if(PCRE2_LIBRARY)
	message(STATUS "pcre2 OK")
endif()

option(WITHOUT_UTF "without_UTF" OFF)

target_link_libraries(rewin ${CURSES_LIBRARY} ${PCRE2_LIBRARY})

add_custom_target(cleanall)
add_custom_command(
	TARGET    cleanall
	COMMAND   git clean -fd
)