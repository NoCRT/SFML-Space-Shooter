cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME "Space_Invader_Clone")
set(Feral_H "GameFiles/Header Files/")
set(Feral_S
        "GameFiles/Source Files/Asteroid.cpp"
        "GameFiles/Source Files/Entity.cpp"
        "GameFiles/Source Files/Ship.cpp"
        "GameFiles/Source Files/Laser.cpp"
        "GameFiles/Source Files/SoundManager.cpp"
        "GameFiles/Source Files/MusicManager.cpp"
        "GameFiles/Source Files/HudElement.cpp"
        )

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "SFML-2.5.1-32/lib/cmake/SFML/")

project(${PROJECT_NAME})

find_package(SFML 2.5.1 COMPONENTS graphics audio window system REQUIRED)

add_executable (${PROJECT_NAME} main.cpp ${Feral_H} ${Feral_S})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-window sfml-system)