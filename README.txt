Feral Engine v0.1
custom SFML library / engine for basic 2d game creation

engine steps:
1 - functional game (basics are done but polishing and QOL additions to be made)
2 - Component system based off game
3 - GUI for component system

Component Systems:
Keyboard Handler             retrieves keyboard states
Gamepad Handler              retrieves gamepad states
Entity Handler               retrieves states and functions of each entity
Window Manager   (singleton)
Entity Manager   (singleton) contains input and entity handler for each entity added. acts as entity factory
Audio Manager    (singleton) used to create sounds and play music. music is put into vector when playing, removed when finished
System Manager   (singleton) contains all managers

default pos = top left corner
EG: xBounds = sprite - width

TODO KEY: ^= complete, #= working on, *= not needed / no use at the moment, \= todo at later date
^	Create states for laser
^	Laser updates differently depending on state
^	States - expire(reset location and hide sprite), renew(refire after reset)
^	Set delay inbetween firing
^	Create asteroids class
^	Have asteroids generate between window width bounds 
^	Have laser collision with asteroids
^   Stop hitbox from staying after asteroid is hit
^	Create timer for creation of asteroid
^	Create sound effects for events EG: lives being removed, lasers being shot, asteroid being destroyed, general space background music
^   Create sound manager to play _sound effects (laser fire, asteroid destruction ect)
^	Set lives for game over
#	Create canCollide variable and function in entity class
*	Use C++ rand for better random generation (tried before but wansn't functional)
#   Allow player to move anywhere within the window bounds
\   Make sound and music manager dynamic to cut out sound stops
\   Create player drift to recreate ambient movment in space
\	Incorporate laserDelay and other timers into classes (clean up main.cpp)
\   Recreate laser delay so it only resets when the space bar is set. (allows for user to not fire and then be ready to fire when the need to rather than wait for delay to pass)
\   Set lasers to respawn at proper position
\   Create algorithm that detects if a laser will hit an asteroid (to preload values to allow stop lasers from being expired at same time)
\   Create different laser sets (dual, quad ect)
\   Create collision detection that allows for better hitbox registration
\   Set asteroids to spawn at all window points (top, bottom, left, right)
\   Create shader for laser

\	Create asteroid and laser exclusive functions in main entity class
\	Set game speed to be exluded from frame rate (sf::clock and render times / frame times)
\	Clean up main.cpp code
\	Create hud class for easy hud elements creation
\	Allow updates to be functions that can be passed in to each different iteration of that class (interface / interpreter)
\	Create menu system in command window for pre game setup
\	Begin incorporating component system EG: entity manager
\   Create logic update timer to allow for framerate to not affect game speed // updates only occur at 16.6 ms
\   Optimise code