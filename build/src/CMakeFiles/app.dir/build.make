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
include src/CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/app.dir/flags.make

src/CMakeFiles/app.dir/app_main.c.o: src/CMakeFiles/app.dir/flags.make
src/CMakeFiles/app.dir/app_main.c.o: ../src/app_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bucccket/programs/C-console-render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/app.dir/app_main.c.o"
	cd /home/bucccket/programs/C-console-render/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/app_main.c.o -c /home/bucccket/programs/C-console-render/src/app_main.c

src/CMakeFiles/app.dir/app_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/app_main.c.i"
	cd /home/bucccket/programs/C-console-render/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bucccket/programs/C-console-render/src/app_main.c > CMakeFiles/app.dir/app_main.c.i

src/CMakeFiles/app.dir/app_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/app_main.c.s"
	cd /home/bucccket/programs/C-console-render/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bucccket/programs/C-console-render/src/app_main.c -o CMakeFiles/app.dir/app_main.c.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/app_main.c.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

src/app: src/CMakeFiles/app.dir/app_main.c.o
src/app: src/CMakeFiles/app.dir/build.make
src/app: src/CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bucccket/programs/C-console-render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable app"
	cd /home/bucccket/programs/C-console-render/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/app.dir/build: src/app

.PHONY : src/CMakeFiles/app.dir/build

src/CMakeFiles/app.dir/clean:
	cd /home/bucccket/programs/C-console-render/build/src && $(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/app.dir/clean

src/CMakeFiles/app.dir/depend:
	cd /home/bucccket/programs/C-console-render/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bucccket/programs/C-console-render /home/bucccket/programs/C-console-render/src /home/bucccket/programs/C-console-render/build /home/bucccket/programs/C-console-render/build/src /home/bucccket/programs/C-console-render/build/src/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/app.dir/depend
