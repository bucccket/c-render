# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/bucccket/programs/C-console-render

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bucccket/programs/C-console-render/build

# Include any dependencies generated for this target.
include CMakeFiles/c-render.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c-render.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c-render.dir/flags.make

CMakeFiles/c-render.dir/src/app_main.c.o: CMakeFiles/c-render.dir/flags.make
CMakeFiles/c-render.dir/src/app_main.c.o: ../src/app_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bucccket/programs/C-console-render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/c-render.dir/src/app_main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/c-render.dir/src/app_main.c.o -c /home/bucccket/programs/C-console-render/src/app_main.c

CMakeFiles/c-render.dir/src/app_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/c-render.dir/src/app_main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bucccket/programs/C-console-render/src/app_main.c > CMakeFiles/c-render.dir/src/app_main.c.i

CMakeFiles/c-render.dir/src/app_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/c-render.dir/src/app_main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bucccket/programs/C-console-render/src/app_main.c -o CMakeFiles/c-render.dir/src/app_main.c.s

# Object files for target c-render
c__render_OBJECTS = \
"CMakeFiles/c-render.dir/src/app_main.c.o"

# External object files for target c-render
c__render_EXTERNAL_OBJECTS =

../bin/c-render: CMakeFiles/c-render.dir/src/app_main.c.o
../bin/c-render: CMakeFiles/c-render.dir/build.make
../bin/c-render: ../lib/libutils.a
../bin/c-render: ../lib/librender.a
../bin/c-render: /usr/lib/aarch64-linux-gnu/libcurses.so
../bin/c-render: CMakeFiles/c-render.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bucccket/programs/C-console-render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/c-render"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c-render.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c-render.dir/build: ../bin/c-render

.PHONY : CMakeFiles/c-render.dir/build

CMakeFiles/c-render.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c-render.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c-render.dir/clean

CMakeFiles/c-render.dir/depend:
	cd /home/bucccket/programs/C-console-render/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bucccket/programs/C-console-render /home/bucccket/programs/C-console-render /home/bucccket/programs/C-console-render/build /home/bucccket/programs/C-console-render/build /home/bucccket/programs/C-console-render/build/CMakeFiles/c-render.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c-render.dir/depend

