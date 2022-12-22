cmake_minimum_required(VERSION 3.0.0)
project(VNyl VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(VNyl main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(VNyl
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)