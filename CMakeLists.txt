cmake_minimum_required(VERSION 3.17.2)
project(SFML_TEST VERSION 0.1.0)
set(CXX_STANDARD 17)

# if windows
set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML/")

file(GLOB_RECURSE FILES files/*.cpp files/*.h files/*.hpp)
find_package(SFML 2.5.1 COMPONENTS graphics audio window system REQUIRED)

add_executable(${PROJECT_NAME} main.cpp ${FILES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-window sfml-system)