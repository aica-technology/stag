cmake_minimum_required(VERSION 3.2)
PROJECT(STag VERSION 0.0.0 LANGUAGES CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(OpenCV REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)

FILE(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

add_executable(stag_main ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(stag_main ${OpenCV_LIBS} ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
        DESTINATION lib)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION include)