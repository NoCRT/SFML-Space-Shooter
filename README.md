# Asteroid Clone v0.1.1

## game main TODO:
* 1 - create functional game
* 2 - upgrade functionality with systems like a component system && general expandability
* 3 - polish existing systems and add a gui library like sfGUI

## Component System Examples (TODO):
* Keyboard Handler             retrieves keyboard states
* Gamepad Handler              retrieves gamepad states
* Entity Handler               retrieves states and functions of each entity
* Window Manager   (singleton)
* Entity Manager   (singleton) contains input and entity handler for each entity added. acts as entity factory
* Audio Manager    (singleton) used to create sounds and play music. music is put into vector when playing, removed when finished
* System Manager   (singleton) contains all managers

## TODO
TODO KEY: ^= complete, #= working on, *= optional / no use at the moment, \= todo at later date
### OLD STUFF (12 December 2018)
* [*]	Create states for laser
* [*]	Laser updates differently depending on state
* [*]	States - expire(reset location and hide sprite), renew(refire after reset)
* [*]	Set delay inbetween firing
* [*]	Create asteroids class
* [*]	Have asteroids generate between window width bounds 
* [*]	Have laser collision with asteroids
* [*] Stop hitbox from staying after asteroid is hit
* [*]	Create sound effects for events EG: lives being removed, lasers being shot, asteroid being destroyed, general space background music
* [*] Create sound manager to play _sound effects (laser fire, asteroid destruction ect)
* [*]	Set lives for game over
* [*] Set lasers to respawn at proper position
* [*]	Set game speed to be exluded from frame rate (sf::clock and render times / frame times)

### NEW STUFF (07 August 2019)
[*] Reorganise project files for easier maintenance
[*] Give player invul frames after hitting an asteroid
[*] Make player opaque during invul frames
[*] Improved drawing (fps increase from 90 to 120 (around 25% increase) - debugHub  |   increase from 120 to 180 - no debugHud
[*] Improved drawing
[*] Detie couning and calculating from from framerate. Prevents respawn timers from being slowed or increased by framerate 
[*] Redo laser delay so it only resets when the space bar is set. (allows for user to not fire and then be ready to fire when the need to rather than wait for delay to pass)

[]   Create managers for entities to manage various looping functions like update. (removes the need for multiple update cycles, allows collision to be moved to each class by filtering existing entities
[]	Create canCollide variable and function in entity class (move from player to entity)
[] Scale graphics with window size. (use viewports and cameras)

[] Make sound and music manager use a dynamic storage type to cut out sound stops when new sound is played
[] Create ship momentum to recreate ambient movment in space
[] Incorporate laserDelay and other timers into classes (clean up main.cpp)
[] Create algorithm that detects if a laser will hit an asteroid (to preload values to allow stop lasers from being expired at same time)
[] Create different laser sets (dual, quad ect)
[] Create collision detection that allows for better hitbox registration
[] Set asteroids to spawn at all window points (top, bottom, left, right)
[] Create shader for laser
[] Clean up main.cpp code
[] Create hud class for easy hud elements creation
[] Create menu system in command window for pre game setup (use arguments to opt in eg:: game -y)
[] Begin incorporating component system EG: entity manager
[] Create logic update timer to allow for framerate to not affect game speed // updates only occur at 16.6 ms
[] Optimise code

## Extra Information
provided sfml library will not work with linux
built using vscode: 
- minGW-64 i686(32 bit) 8.1.0 win32
- CMake version 3.15.2
