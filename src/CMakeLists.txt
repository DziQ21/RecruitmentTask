cmake_minimum_required(VERSION 3.10)
project(RecruitmentTask LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp")

add_executable(RecruitmentTask ${SOURCES})

target_compile_options(RecruitmentTask PRIVATE -Wall -Wextra -Werror -pedantic)
