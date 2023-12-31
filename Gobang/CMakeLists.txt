cmake_minimum_required(VERSION 3.2)
project(Gobang)
find_package(raylib CONFIG REQUIRED)
add_executable(Gobang Resource/main.cpp
        Resource/evaluate.cpp
        Header/evaluate.h
        Resource/generator.cpp
        Header/generator.h
        Resource/scrap.cpp
        Header/scrap.h
        Resource/search.cpp
        Header/search.h
        Resource/ui.cpp
        Header/ui.h
        Resource/variable.cpp
        Header/variable.h
        Resource/hash.cpp
        Header/hash.h)

target_link_libraries(${PROJECT_NAME} raylib)