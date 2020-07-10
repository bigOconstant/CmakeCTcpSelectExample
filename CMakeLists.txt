cmake_minimum_required(VERSION 3.0)

project(server LANGUAGES C)

set( project_sources
   main.c
   tcp_connection.c
   server.c
   InputParser.c
   KafkaMessage.c
)

add_subdirectory(libs/librdkafka)

add_executable(server
  ${project_sources}
)

target_link_libraries( server  rdkafka  )

install(TARGETS server RUNTIME DESTINATION bin)
