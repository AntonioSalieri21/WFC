# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/salieri/Documents/GitHub/WFC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/salieri/Documents/GitHub/WFC/build

# Include any dependencies generated for this target.
include CMakeFiles/WFCGenerator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WFCGenerator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WFCGenerator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WFCGenerator.dir/flags.make

CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.o: WFCGenerator_autogen/mocs_compilation.cpp
CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.o -MF CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.o -c /home/salieri/Documents/GitHub/WFC/build/WFCGenerator_autogen/mocs_compilation.cpp

CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/build/WFCGenerator_autogen/mocs_compilation.cpp > CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.i

CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/build/WFCGenerator_autogen/mocs_compilation.cpp -o CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.s

CMakeFiles/WFCGenerator.dir/main.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/main.cpp.o: /home/salieri/Documents/GitHub/WFC/main.cpp
CMakeFiles/WFCGenerator.dir/main.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WFCGenerator.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/main.cpp.o -MF CMakeFiles/WFCGenerator.dir/main.cpp.o.d -o CMakeFiles/WFCGenerator.dir/main.cpp.o -c /home/salieri/Documents/GitHub/WFC/main.cpp

CMakeFiles/WFCGenerator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/main.cpp > CMakeFiles/WFCGenerator.dir/main.cpp.i

CMakeFiles/WFCGenerator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/main.cpp -o CMakeFiles/WFCGenerator.dir/main.cpp.s

CMakeFiles/WFCGenerator.dir/tile.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/tile.cpp.o: /home/salieri/Documents/GitHub/WFC/tile.cpp
CMakeFiles/WFCGenerator.dir/tile.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WFCGenerator.dir/tile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/tile.cpp.o -MF CMakeFiles/WFCGenerator.dir/tile.cpp.o.d -o CMakeFiles/WFCGenerator.dir/tile.cpp.o -c /home/salieri/Documents/GitHub/WFC/tile.cpp

CMakeFiles/WFCGenerator.dir/tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/tile.cpp > CMakeFiles/WFCGenerator.dir/tile.cpp.i

CMakeFiles/WFCGenerator.dir/tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/tile.cpp -o CMakeFiles/WFCGenerator.dir/tile.cpp.s

CMakeFiles/WFCGenerator.dir/tileset.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/tileset.cpp.o: /home/salieri/Documents/GitHub/WFC/tileset.cpp
CMakeFiles/WFCGenerator.dir/tileset.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WFCGenerator.dir/tileset.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/tileset.cpp.o -MF CMakeFiles/WFCGenerator.dir/tileset.cpp.o.d -o CMakeFiles/WFCGenerator.dir/tileset.cpp.o -c /home/salieri/Documents/GitHub/WFC/tileset.cpp

CMakeFiles/WFCGenerator.dir/tileset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/tileset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/tileset.cpp > CMakeFiles/WFCGenerator.dir/tileset.cpp.i

CMakeFiles/WFCGenerator.dir/tileset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/tileset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/tileset.cpp -o CMakeFiles/WFCGenerator.dir/tileset.cpp.s

CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o: /home/salieri/Documents/GitHub/WFC/tilesetconfig.cpp
CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o -MF CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o.d -o CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o -c /home/salieri/Documents/GitHub/WFC/tilesetconfig.cpp

CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/tilesetconfig.cpp > CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.i

CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/tilesetconfig.cpp -o CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.s

CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o: /home/salieri/Documents/GitHub/WFC/wfc_generator.cpp
CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o -MF CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o.d -o CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o -c /home/salieri/Documents/GitHub/WFC/wfc_generator.cpp

CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/wfc_generator.cpp > CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.i

CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/wfc_generator.cpp -o CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.s

CMakeFiles/WFCGenerator.dir/grid.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/grid.cpp.o: /home/salieri/Documents/GitHub/WFC/grid.cpp
CMakeFiles/WFCGenerator.dir/grid.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/WFCGenerator.dir/grid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/grid.cpp.o -MF CMakeFiles/WFCGenerator.dir/grid.cpp.o.d -o CMakeFiles/WFCGenerator.dir/grid.cpp.o -c /home/salieri/Documents/GitHub/WFC/grid.cpp

CMakeFiles/WFCGenerator.dir/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/grid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/grid.cpp > CMakeFiles/WFCGenerator.dir/grid.cpp.i

CMakeFiles/WFCGenerator.dir/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/grid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/grid.cpp -o CMakeFiles/WFCGenerator.dir/grid.cpp.s

CMakeFiles/WFCGenerator.dir/cell.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/cell.cpp.o: /home/salieri/Documents/GitHub/WFC/cell.cpp
CMakeFiles/WFCGenerator.dir/cell.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/WFCGenerator.dir/cell.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/cell.cpp.o -MF CMakeFiles/WFCGenerator.dir/cell.cpp.o.d -o CMakeFiles/WFCGenerator.dir/cell.cpp.o -c /home/salieri/Documents/GitHub/WFC/cell.cpp

CMakeFiles/WFCGenerator.dir/cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/cell.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/cell.cpp > CMakeFiles/WFCGenerator.dir/cell.cpp.i

CMakeFiles/WFCGenerator.dir/cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/cell.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/cell.cpp -o CMakeFiles/WFCGenerator.dir/cell.cpp.s

CMakeFiles/WFCGenerator.dir/sides.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/sides.cpp.o: /home/salieri/Documents/GitHub/WFC/sides.cpp
CMakeFiles/WFCGenerator.dir/sides.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/WFCGenerator.dir/sides.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/sides.cpp.o -MF CMakeFiles/WFCGenerator.dir/sides.cpp.o.d -o CMakeFiles/WFCGenerator.dir/sides.cpp.o -c /home/salieri/Documents/GitHub/WFC/sides.cpp

CMakeFiles/WFCGenerator.dir/sides.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/sides.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/sides.cpp > CMakeFiles/WFCGenerator.dir/sides.cpp.i

CMakeFiles/WFCGenerator.dir/sides.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/sides.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/sides.cpp -o CMakeFiles/WFCGenerator.dir/sides.cpp.s

CMakeFiles/WFCGenerator.dir/image_generator.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/image_generator.cpp.o: /home/salieri/Documents/GitHub/WFC/image_generator.cpp
CMakeFiles/WFCGenerator.dir/image_generator.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/WFCGenerator.dir/image_generator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/image_generator.cpp.o -MF CMakeFiles/WFCGenerator.dir/image_generator.cpp.o.d -o CMakeFiles/WFCGenerator.dir/image_generator.cpp.o -c /home/salieri/Documents/GitHub/WFC/image_generator.cpp

CMakeFiles/WFCGenerator.dir/image_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/image_generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/image_generator.cpp > CMakeFiles/WFCGenerator.dir/image_generator.cpp.i

CMakeFiles/WFCGenerator.dir/image_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/image_generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/image_generator.cpp -o CMakeFiles/WFCGenerator.dir/image_generator.cpp.s

CMakeFiles/WFCGenerator.dir/tileinfo.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/tileinfo.cpp.o: /home/salieri/Documents/GitHub/WFC/tileinfo.cpp
CMakeFiles/WFCGenerator.dir/tileinfo.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/WFCGenerator.dir/tileinfo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/tileinfo.cpp.o -MF CMakeFiles/WFCGenerator.dir/tileinfo.cpp.o.d -o CMakeFiles/WFCGenerator.dir/tileinfo.cpp.o -c /home/salieri/Documents/GitHub/WFC/tileinfo.cpp

CMakeFiles/WFCGenerator.dir/tileinfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/tileinfo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/tileinfo.cpp > CMakeFiles/WFCGenerator.dir/tileinfo.cpp.i

CMakeFiles/WFCGenerator.dir/tileinfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/tileinfo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/tileinfo.cpp -o CMakeFiles/WFCGenerator.dir/tileinfo.cpp.s

CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.o: /home/salieri/Documents/GitHub/WFC/GUI/mainwindow.cpp
CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.o -MF CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.o.d -o CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.o -c /home/salieri/Documents/GitHub/WFC/GUI/mainwindow.cpp

CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Documents/GitHub/WFC/GUI/mainwindow.cpp > CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.i

CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Documents/GitHub/WFC/GUI/mainwindow.cpp -o CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.s

# Object files for target WFCGenerator
WFCGenerator_OBJECTS = \
"CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/WFCGenerator.dir/main.cpp.o" \
"CMakeFiles/WFCGenerator.dir/tile.cpp.o" \
"CMakeFiles/WFCGenerator.dir/tileset.cpp.o" \
"CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o" \
"CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o" \
"CMakeFiles/WFCGenerator.dir/grid.cpp.o" \
"CMakeFiles/WFCGenerator.dir/cell.cpp.o" \
"CMakeFiles/WFCGenerator.dir/sides.cpp.o" \
"CMakeFiles/WFCGenerator.dir/image_generator.cpp.o" \
"CMakeFiles/WFCGenerator.dir/tileinfo.cpp.o" \
"CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.o"

# External object files for target WFCGenerator
WFCGenerator_EXTERNAL_OBJECTS =

WFCGenerator: CMakeFiles/WFCGenerator.dir/WFCGenerator_autogen/mocs_compilation.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/main.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/tile.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/tileset.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/grid.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/cell.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/sides.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/image_generator.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/tileinfo.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/GUI/mainwindow.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/build.make
WFCGenerator: /usr/lib64/libopencv_gapi.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_stitching.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_alphamat.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_aruco.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_bgsegm.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_bioinspired.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_ccalib.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_cvv.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_dnn_objdetect.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_dnn_superres.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_dpm.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_face.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_freetype.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_fuzzy.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_hdf.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_hfs.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_img_hash.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_intensity_transform.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_line_descriptor.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_mcc.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_quality.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_rapid.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_reg.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_rgbd.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_saliency.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_shape.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_stereo.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_structured_light.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_superres.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_surface_matching.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_tracking.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_videostab.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_viz.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_wechat_qrcode.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_xobjdetect.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_xphoto.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_highgui.so.4.8.1
WFCGenerator: /usr/lib64/libQt5Widgets.so.5.15.12
WFCGenerator: /usr/lib64/libQt5Gui.so.5.15.12
WFCGenerator: /usr/lib64/libQt5Core.so.5.15.12
WFCGenerator: /usr/lib64/libopencv_datasets.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_plot.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_text.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_ml.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_phase_unwrapping.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_optflow.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_ximgproc.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_video.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_videoio.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_imgcodecs.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_objdetect.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_calib3d.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_dnn.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_features2d.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_flann.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_photo.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_imgproc.so.4.8.1
WFCGenerator: /usr/lib64/libopencv_core.so.4.8.1
WFCGenerator: CMakeFiles/WFCGenerator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/salieri/Documents/GitHub/WFC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable WFCGenerator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WFCGenerator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WFCGenerator.dir/build: WFCGenerator
.PHONY : CMakeFiles/WFCGenerator.dir/build

CMakeFiles/WFCGenerator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WFCGenerator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WFCGenerator.dir/clean

CMakeFiles/WFCGenerator.dir/depend:
	cd /home/salieri/Documents/GitHub/WFC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/salieri/Documents/GitHub/WFC /home/salieri/Documents/GitHub/WFC /home/salieri/Documents/GitHub/WFC/build /home/salieri/Documents/GitHub/WFC/build /home/salieri/Documents/GitHub/WFC/build/CMakeFiles/WFCGenerator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/WFCGenerator.dir/depend

