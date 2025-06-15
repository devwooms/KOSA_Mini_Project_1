cmake_minimum_required(VERSION 3.10)
project(myProject VERSION 1.0)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# view 폴더의 모든 소스 파일을 자동으로 찾기
file(GLOB_RECURSE VIEW_SOURCES
    "view/*.cpp"
    "view/*.h"
    "view/screens/*.cpp"
    "view/screens/*.h"
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

# 소스 파일 목록
set(SOURCES
    main.cpp
    util.cpp
    ${VIEW_SOURCES}
    ${MODEL_SOURCES}
    ${CONTROLLER_SOURCES}
)

# 헤더 파일 디렉토리
include_directories(${CMAKE_SOURCE_DIR})

# 실행 파일 생성
add_executable(${PROJECT_NAME} ${SOURCES}) 