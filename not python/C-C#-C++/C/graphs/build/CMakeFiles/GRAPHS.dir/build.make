# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/build"

# Include any dependencies generated for this target.
include CMakeFiles/GRAPHS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GRAPHS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GRAPHS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GRAPHS.dir/flags.make

CMakeFiles/GRAPHS.dir/src/main.c.o: CMakeFiles/GRAPHS.dir/flags.make
CMakeFiles/GRAPHS.dir/src/main.c.o: ../src/main.c
CMakeFiles/GRAPHS.dir/src/main.c.o: CMakeFiles/GRAPHS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GRAPHS.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GRAPHS.dir/src/main.c.o -MF CMakeFiles/GRAPHS.dir/src/main.c.o.d -o CMakeFiles/GRAPHS.dir/src/main.c.o -c "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/src/main.c"

CMakeFiles/GRAPHS.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GRAPHS.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/src/main.c" > CMakeFiles/GRAPHS.dir/src/main.c.i

CMakeFiles/GRAPHS.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GRAPHS.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/src/main.c" -o CMakeFiles/GRAPHS.dir/src/main.c.s

CMakeFiles/GRAPHS.dir/src/graphs.c.o: CMakeFiles/GRAPHS.dir/flags.make
CMakeFiles/GRAPHS.dir/src/graphs.c.o: ../src/graphs.c
CMakeFiles/GRAPHS.dir/src/graphs.c.o: CMakeFiles/GRAPHS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GRAPHS.dir/src/graphs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GRAPHS.dir/src/graphs.c.o -MF CMakeFiles/GRAPHS.dir/src/graphs.c.o.d -o CMakeFiles/GRAPHS.dir/src/graphs.c.o -c "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/src/graphs.c"

CMakeFiles/GRAPHS.dir/src/graphs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GRAPHS.dir/src/graphs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/src/graphs.c" > CMakeFiles/GRAPHS.dir/src/graphs.c.i

CMakeFiles/GRAPHS.dir/src/graphs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GRAPHS.dir/src/graphs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/src/graphs.c" -o CMakeFiles/GRAPHS.dir/src/graphs.c.s

# Object files for target GRAPHS
GRAPHS_OBJECTS = \
"CMakeFiles/GRAPHS.dir/src/main.c.o" \
"CMakeFiles/GRAPHS.dir/src/graphs.c.o"

# External object files for target GRAPHS
GRAPHS_EXTERNAL_OBJECTS =

GRAPHS: CMakeFiles/GRAPHS.dir/src/main.c.o
GRAPHS: CMakeFiles/GRAPHS.dir/src/graphs.c.o
GRAPHS: CMakeFiles/GRAPHS.dir/build.make
GRAPHS: CMakeFiles/GRAPHS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable GRAPHS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GRAPHS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GRAPHS.dir/build: GRAPHS
.PHONY : CMakeFiles/GRAPHS.dir/build

CMakeFiles/GRAPHS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GRAPHS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GRAPHS.dir/clean

CMakeFiles/GRAPHS.dir/depend:
	cd "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs" "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs" "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/build" "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/build" "/home/bruno/Documents/git/learning/not python/C-C#-C++/C/graphs/build/CMakeFiles/GRAPHS.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GRAPHS.dir/depend

