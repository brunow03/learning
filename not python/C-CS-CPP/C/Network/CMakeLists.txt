cmake_minimum_required(VERSION 3.10)
project(NETWORKS)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INC_DIR "${CMAKE_SOURCE_DIR}/include")
include_directories(${INC_DIR})

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.c")

# unix_list.c
set(UNIX_LIST_SOURCES
	"${SRC_DIR}/unix_list.c"
)

# sock_init.c
set(SOCK_INIT_SOURCES
	"${SRC_DIR}/sock_init.c"
)

# time_console.c
set(TIME_CONSOLE_SOURCES
	"${SRC_DIR}/time_console.c"
)

# time_server.c
set(TIME_SERVER_SOURCES
	"${SRC_DIR}/time_server.c"
)

# time_server_ipv6.c
set(TIME_SERVER_IPV6_SOURCES
	"${SRC_DIR}/time_server_ipv6.c"
)

# tcp_serve_toupper_fork.c
set(TIME_SERVE_TOUPPER_FORK_SOURCES
	"${SRC_DIR}/tcp_serve_toupper_fork.c"
)

# tcp_client.c
set(TCP_CLIENT_SOURCES
	"${SRC_DIR}/tcp_client.c"
)

add_executable(RUN_UNIX_LIST ${UNIX_LIST_SOURCES})
add_executable(RUN_SOCK_INIT ${SOCK_INIT_SOURCES})
add_executable(RUN_TIME_CONSOLE ${TIME_CONSOLE_SOURCES})
add_executable(RUN_TIME_SERVER ${TIME_SERVER_SOURCES})
add_executable(RUN_TIME_SERVER_IPV6 ${TIME_SERVER_IPV6_SOURCES})
add_executable(RUN_TIME_SERVE_TOUPPER_FORK_SOURCES ${TIME_SERVE_TOUPPER_FORK_SOURCES})
add_executable(RUN_TCP_CLIENT_SOURCES ${TCP_CLIENT_SOURCES})

if(UNIX)
	message(STATUS ">>> HELLO, LINUX!")
	#target_link_libraries(PRIVATE pthread)
endif()

if(WIN32)
	message(STATUS ">>> HELLO, WINDOWS!")
	target_link_libraries(${} wsock32 ws2_32)
endif()

if(APPLE)
	message(STATUS ">>> HELLO, MAC!")
endif()


#if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
#   
#endif()