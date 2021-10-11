cmake_minimum_required(VERSION 2.8)

project(n2.20)

set(n2.20_src main.cpp zip.cpp AT.cpp)
set(n2.20_hdr head.hpp zip.hpp AT.hpp)

add_executable(${PROJECT_NAME} ${n2.20_src} ${n2.20_hdr})

