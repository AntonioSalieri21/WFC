# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/salieri/Study/C++/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/salieri/Study/C++/Project/build

# Include any dependencies generated for this target.
include CMakeFiles/WFCGenerator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WFCGenerator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WFCGenerator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WFCGenerator.dir/flags.make

CMakeFiles/WFCGenerator.dir/main.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/main.cpp.o: /home/salieri/Study/C++/Project/main.cpp
CMakeFiles/WFCGenerator.dir/main.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Study/C++/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WFCGenerator.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/main.cpp.o -MF CMakeFiles/WFCGenerator.dir/main.cpp.o.d -o CMakeFiles/WFCGenerator.dir/main.cpp.o -c /home/salieri/Study/C++/Project/main.cpp

CMakeFiles/WFCGenerator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Study/C++/Project/main.cpp > CMakeFiles/WFCGenerator.dir/main.cpp.i

CMakeFiles/WFCGenerator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Study/C++/Project/main.cpp -o CMakeFiles/WFCGenerator.dir/main.cpp.s

CMakeFiles/WFCGenerator.dir/tile.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/tile.cpp.o: /home/salieri/Study/C++/Project/tile.cpp
CMakeFiles/WFCGenerator.dir/tile.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Study/C++/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WFCGenerator.dir/tile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/tile.cpp.o -MF CMakeFiles/WFCGenerator.dir/tile.cpp.o.d -o CMakeFiles/WFCGenerator.dir/tile.cpp.o -c /home/salieri/Study/C++/Project/tile.cpp

CMakeFiles/WFCGenerator.dir/tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Study/C++/Project/tile.cpp > CMakeFiles/WFCGenerator.dir/tile.cpp.i

CMakeFiles/WFCGenerator.dir/tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Study/C++/Project/tile.cpp -o CMakeFiles/WFCGenerator.dir/tile.cpp.s

CMakeFiles/WFCGenerator.dir/tileset.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/tileset.cpp.o: /home/salieri/Study/C++/Project/tileset.cpp
CMakeFiles/WFCGenerator.dir/tileset.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Study/C++/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WFCGenerator.dir/tileset.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/tileset.cpp.o -MF CMakeFiles/WFCGenerator.dir/tileset.cpp.o.d -o CMakeFiles/WFCGenerator.dir/tileset.cpp.o -c /home/salieri/Study/C++/Project/tileset.cpp

CMakeFiles/WFCGenerator.dir/tileset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/tileset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Study/C++/Project/tileset.cpp > CMakeFiles/WFCGenerator.dir/tileset.cpp.i

CMakeFiles/WFCGenerator.dir/tileset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/tileset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Study/C++/Project/tileset.cpp -o CMakeFiles/WFCGenerator.dir/tileset.cpp.s

CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o: /home/salieri/Study/C++/Project/tilesetconfig.cpp
CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Study/C++/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o -MF CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o.d -o CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o -c /home/salieri/Study/C++/Project/tilesetconfig.cpp

CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Study/C++/Project/tilesetconfig.cpp > CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.i

CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Study/C++/Project/tilesetconfig.cpp -o CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.s

CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o: /home/salieri/Study/C++/Project/wfc_generator.cpp
CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Study/C++/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o -MF CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o.d -o CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o -c /home/salieri/Study/C++/Project/wfc_generator.cpp

CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Study/C++/Project/wfc_generator.cpp > CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.i

CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Study/C++/Project/wfc_generator.cpp -o CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.s

CMakeFiles/WFCGenerator.dir/grid.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/grid.cpp.o: /home/salieri/Study/C++/Project/grid.cpp
CMakeFiles/WFCGenerator.dir/grid.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Study/C++/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WFCGenerator.dir/grid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/grid.cpp.o -MF CMakeFiles/WFCGenerator.dir/grid.cpp.o.d -o CMakeFiles/WFCGenerator.dir/grid.cpp.o -c /home/salieri/Study/C++/Project/grid.cpp

CMakeFiles/WFCGenerator.dir/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/grid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Study/C++/Project/grid.cpp > CMakeFiles/WFCGenerator.dir/grid.cpp.i

CMakeFiles/WFCGenerator.dir/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/grid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Study/C++/Project/grid.cpp -o CMakeFiles/WFCGenerator.dir/grid.cpp.s

CMakeFiles/WFCGenerator.dir/cell.cpp.o: CMakeFiles/WFCGenerator.dir/flags.make
CMakeFiles/WFCGenerator.dir/cell.cpp.o: /home/salieri/Study/C++/Project/cell.cpp
CMakeFiles/WFCGenerator.dir/cell.cpp.o: CMakeFiles/WFCGenerator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salieri/Study/C++/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/WFCGenerator.dir/cell.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WFCGenerator.dir/cell.cpp.o -MF CMakeFiles/WFCGenerator.dir/cell.cpp.o.d -o CMakeFiles/WFCGenerator.dir/cell.cpp.o -c /home/salieri/Study/C++/Project/cell.cpp

CMakeFiles/WFCGenerator.dir/cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WFCGenerator.dir/cell.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salieri/Study/C++/Project/cell.cpp > CMakeFiles/WFCGenerator.dir/cell.cpp.i

CMakeFiles/WFCGenerator.dir/cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WFCGenerator.dir/cell.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salieri/Study/C++/Project/cell.cpp -o CMakeFiles/WFCGenerator.dir/cell.cpp.s

# Object files for target WFCGenerator
WFCGenerator_OBJECTS = \
"CMakeFiles/WFCGenerator.dir/main.cpp.o" \
"CMakeFiles/WFCGenerator.dir/tile.cpp.o" \
"CMakeFiles/WFCGenerator.dir/tileset.cpp.o" \
"CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o" \
"CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o" \
"CMakeFiles/WFCGenerator.dir/grid.cpp.o" \
"CMakeFiles/WFCGenerator.dir/cell.cpp.o"

# External object files for target WFCGenerator
WFCGenerator_EXTERNAL_OBJECTS =

WFCGenerator: CMakeFiles/WFCGenerator.dir/main.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/tile.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/tileset.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/tilesetconfig.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/wfc_generator.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/grid.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/cell.cpp.o
WFCGenerator: CMakeFiles/WFCGenerator.dir/build.make
WFCGenerator: /usr/lib/libopencv_gapi.so.4.9.0
WFCGenerator: /usr/lib/libopencv_stitching.so.4.9.0
WFCGenerator: /usr/lib/libopencv_alphamat.so.4.9.0
WFCGenerator: /usr/lib/libopencv_aruco.so.4.9.0
WFCGenerator: /usr/lib/libopencv_bgsegm.so.4.9.0
WFCGenerator: /usr/lib/libopencv_bioinspired.so.4.9.0
WFCGenerator: /usr/lib/libopencv_ccalib.so.4.9.0
WFCGenerator: /usr/lib/libopencv_cvv.so.4.9.0
WFCGenerator: /usr/lib/libopencv_dnn_objdetect.so.4.9.0
WFCGenerator: /usr/lib/libopencv_dnn_superres.so.4.9.0
WFCGenerator: /usr/lib/libopencv_dpm.so.4.9.0
WFCGenerator: /usr/lib/libopencv_face.so.4.9.0
WFCGenerator: /usr/lib/libopencv_freetype.so.4.9.0
WFCGenerator: /usr/lib/libopencv_fuzzy.so.4.9.0
WFCGenerator: /usr/lib/libopencv_hdf.so.4.9.0
WFCGenerator: /usr/lib/libopencv_hfs.so.4.9.0
WFCGenerator: /usr/lib/libopencv_img_hash.so.4.9.0
WFCGenerator: /usr/lib/libopencv_intensity_transform.so.4.9.0
WFCGenerator: /usr/lib/libopencv_line_descriptor.so.4.9.0
WFCGenerator: /usr/lib/libopencv_mcc.so.4.9.0
WFCGenerator: /usr/lib/libopencv_quality.so.4.9.0
WFCGenerator: /usr/lib/libopencv_rapid.so.4.9.0
WFCGenerator: /usr/lib/libopencv_reg.so.4.9.0
WFCGenerator: /usr/lib/libopencv_rgbd.so.4.9.0
WFCGenerator: /usr/lib/libopencv_saliency.so.4.9.0
WFCGenerator: /usr/lib/libopencv_stereo.so.4.9.0
WFCGenerator: /usr/lib/libopencv_structured_light.so.4.9.0
WFCGenerator: /usr/lib/libopencv_superres.so.4.9.0
WFCGenerator: /usr/lib/libopencv_surface_matching.so.4.9.0
WFCGenerator: /usr/lib/libopencv_tracking.so.4.9.0
WFCGenerator: /usr/lib/libopencv_videostab.so.4.9.0
WFCGenerator: /usr/lib/libopencv_viz.so.4.9.0
WFCGenerator: /usr/lib/libopencv_wechat_qrcode.so.4.9.0
WFCGenerator: /usr/lib/libopencv_xfeatures2d.so.4.9.0
WFCGenerator: /usr/lib/libopencv_xobjdetect.so.4.9.0
WFCGenerator: /usr/lib/libopencv_xphoto.so.4.9.0
WFCGenerator: /usr/lib/libopencv_shape.so.4.9.0
WFCGenerator: /usr/lib/libopencv_highgui.so.4.9.0
WFCGenerator: /usr/lib/libopencv_datasets.so.4.9.0
WFCGenerator: /usr/lib/libopencv_plot.so.4.9.0
WFCGenerator: /usr/lib/libopencv_text.so.4.9.0
WFCGenerator: /usr/lib/libopencv_ml.so.4.9.0
WFCGenerator: /usr/lib/libopencv_phase_unwrapping.so.4.9.0
WFCGenerator: /usr/lib/libopencv_optflow.so.4.9.0
WFCGenerator: /usr/lib/libopencv_ximgproc.so.4.9.0
WFCGenerator: /usr/lib/libopencv_video.so.4.9.0
WFCGenerator: /usr/lib/libopencv_videoio.so.4.9.0
WFCGenerator: /usr/lib/libopencv_imgcodecs.so.4.9.0
WFCGenerator: /usr/lib/libopencv_objdetect.so.4.9.0
WFCGenerator: /usr/lib/libopencv_calib3d.so.4.9.0
WFCGenerator: /usr/lib/libopencv_dnn.so.4.9.0
WFCGenerator: /usr/lib/libopencv_features2d.so.4.9.0
WFCGenerator: /usr/lib/libopencv_flann.so.4.9.0
WFCGenerator: /usr/lib/libopencv_photo.so.4.9.0
WFCGenerator: /usr/lib/libopencv_imgproc.so.4.9.0
WFCGenerator: /usr/lib/libopencv_core.so.4.9.0
WFCGenerator: CMakeFiles/WFCGenerator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/salieri/Study/C++/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable WFCGenerator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WFCGenerator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WFCGenerator.dir/build: WFCGenerator
.PHONY : CMakeFiles/WFCGenerator.dir/build

CMakeFiles/WFCGenerator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WFCGenerator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WFCGenerator.dir/clean

CMakeFiles/WFCGenerator.dir/depend:
	cd /home/salieri/Study/C++/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/salieri/Study/C++/Project /home/salieri/Study/C++/Project /home/salieri/Study/C++/Project/build /home/salieri/Study/C++/Project/build /home/salieri/Study/C++/Project/build/CMakeFiles/WFCGenerator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/WFCGenerator.dir/depend

