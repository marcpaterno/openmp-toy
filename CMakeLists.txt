cmake_minimum_required(VERSION 3.21) # The current; why use old junk?
project(sample_openmp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)  # Why use old junk? (And compilers aren't up to 20)
set(CMAKE_CXX_STANDARD_REQUIRED on) # Because we're not kidding
set(CMAKE_CXX_EXTENSIONS off)  # Because non-portable code is evil

find_package(OpenMP REQUIRED) # Because we're not kidding


add_executable(hello hello.cc)
target_link_libraries(hello $<$<CONFIG:Release>:OpenMP::OpenMP_CXX>)
add_executable(pi pi.cc)
target_link_libraries(pi $<$<CONFIG:Release>:OpenMP::OpenMP_CXX>)
add_executable(single single.cc)
target_link_libraries(single $<$<CONFIG:Release>:OpenMP::OpenMP_CXX>)
