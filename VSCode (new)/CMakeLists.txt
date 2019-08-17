cmake_minimum_required(VERSION 3.0.0)
project(SFML_TEST VERSION 0.1.0)
set(CXX_STANDARD 17)

include(CTest)
enable_testing()

set(SFML_DIR "libs/SFML-2.5.1-32/lib/cmake/SFML/")
file(GLOB_RECURSE FILES files/*.cpp files/*.h files/*.hpp)
find_package(SFML 2.5.1 COMPONENTS graphics audio window system REQUIRED)

add_executable(${PROJECT_NAME} main.cpp ${FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-window sfml-system)