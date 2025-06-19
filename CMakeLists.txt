cmake_minimum_required(VERSION 3.10)
project(myProject VERSION 1.0)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# view 폴더의 모든 소스 파일을 자동으로 찾기
file(GLOB_RECURSE VIEW_SOURCES
    "view/*.cpp"
    "view/*.h"
)

# model 폴더의 모든 소스 파일을 자동으로 찾기
file(GLOB_RECURSE MODEL_SOURCES
    "model/*.cpp"
    "model/*.h"
)

# controller 폴더의 모든 소스 파일을 자동으로 찾기
file(GLOB_RECURSE CONTROLLER_SOURCES
    "controller/*.cpp"
    "controller/*.h"
)

# data 폴더의 모든 소스 파일을 자동으로 찾기
file(GLOB_RECURSE DATA_SOURCES
    "data/*.cpp"
    "data/*.h"
)

# 소스 파일 목록
set(SOURCES
    Main.cpp
    Util.cpp
    ${VIEW_SOURCES}
    ${MODEL_SOURCES}
    ${CONTROLLER_SOURCES}
    ${DATA_SOURCES}
)

# 헤더 파일 디렉토리
include_directories(${CMAKE_SOURCE_DIR})

# 실행 파일 생성
add_executable(${PROJECT_NAME} ${SOURCES})

# clang-format 자동 정렬 커스텀 명령 추가

# 전체 .cpp, .h 파일 수집
file(GLOB_RECURSE ALL_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.h"
)

# format 명령어 추가
add_custom_target(format
    COMMAND clang-format -i ${ALL_SOURCE_FILES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Formatting all .cpp and .h files with clang-format"
)
