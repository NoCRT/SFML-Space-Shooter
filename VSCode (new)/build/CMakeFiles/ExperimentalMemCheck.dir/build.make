# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Aidan\Desktop\projects\asertoids clone cmake vscode"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Aidan\Desktop\projects\asertoids clone cmake vscode\build"

# Utility rule file for ExperimentalMemCheck.

# Include the progress variables for this target.
include CMakeFiles/ExperimentalMemCheck.dir/progress.make

CMakeFiles/ExperimentalMemCheck:
	"C:\Program Files\CMake\bin\ctest.exe" -D ExperimentalMemCheck

ExperimentalMemCheck: CMakeFiles/ExperimentalMemCheck
ExperimentalMemCheck: CMakeFiles/ExperimentalMemCheck.dir/build.make

.PHONY : ExperimentalMemCheck

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalMemCheck.dir/build: ExperimentalMemCheck

.PHONY : CMakeFiles/ExperimentalMemCheck.dir/build

CMakeFiles/ExperimentalMemCheck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ExperimentalMemCheck.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalMemCheck.dir/clean

CMakeFiles/ExperimentalMemCheck.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Aidan\Desktop\projects\asertoids clone cmake vscode" "C:\Users\Aidan\Desktop\projects\asertoids clone cmake vscode" "C:\Users\Aidan\Desktop\projects\asertoids clone cmake vscode\build" "C:\Users\Aidan\Desktop\projects\asertoids clone cmake vscode\build" "C:\Users\Aidan\Desktop\projects\asertoids clone cmake vscode\build\CMakeFiles\ExperimentalMemCheck.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ExperimentalMemCheck.dir/depend
