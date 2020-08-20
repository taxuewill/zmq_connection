cmake_minimum_required(VERSION 3.5)
project(zmq_study)

find_package(PkgConfig)

find_package(Threads)

pkg_check_modules(ZMQ libzmq)

include_directories( 
  include
  ${ZMQ_INCLUDE_DIRS})
#target_link_libraries (test1 ${CMAKE_THREAD_LIBS_INIT})

add_executable(Reqeust src/request_replay/RequestClient.cpp)
target_link_libraries(Reqeust ${ZMQ_LIBRARIES})


add_executable(Reply src/request_replay/ReplyServer.cpp)
target_link_libraries(Reply ${ZMQ_LIBRARIES})