cmake_minimum_required(VERSION 3.0)

project(server LANGUAGES C)

set( project_sources
   main.c
   tcp_connection.c
   server.c
   InputParser.c
)

add_executable(server
  ${project_sources}
)

install(TARGETS server RUNTIME DESTINATION bin)
