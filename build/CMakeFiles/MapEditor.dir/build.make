# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/clemente/projects/Troll-Killers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clemente/projects/Troll-Killers/build

# Include any dependencies generated for this target.
include CMakeFiles/MapEditor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MapEditor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MapEditor.dir/flags.make

CMakeFiles/MapEditor.dir/editorMain.cpp.o: CMakeFiles/MapEditor.dir/flags.make
CMakeFiles/MapEditor.dir/editorMain.cpp.o: ../editorMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MapEditor.dir/editorMain.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MapEditor.dir/editorMain.cpp.o -c /home/clemente/projects/Troll-Killers/editorMain.cpp

CMakeFiles/MapEditor.dir/editorMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MapEditor.dir/editorMain.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/editorMain.cpp > CMakeFiles/MapEditor.dir/editorMain.cpp.i

CMakeFiles/MapEditor.dir/editorMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MapEditor.dir/editorMain.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/editorMain.cpp -o CMakeFiles/MapEditor.dir/editorMain.cpp.s

CMakeFiles/MapEditor.dir/editorMain.cpp.o.requires:

.PHONY : CMakeFiles/MapEditor.dir/editorMain.cpp.o.requires

CMakeFiles/MapEditor.dir/editorMain.cpp.o.provides: CMakeFiles/MapEditor.dir/editorMain.cpp.o.requires
	$(MAKE) -f CMakeFiles/MapEditor.dir/build.make CMakeFiles/MapEditor.dir/editorMain.cpp.o.provides.build
.PHONY : CMakeFiles/MapEditor.dir/editorMain.cpp.o.provides

CMakeFiles/MapEditor.dir/editorMain.cpp.o.provides.build: CMakeFiles/MapEditor.dir/editorMain.cpp.o


CMakeFiles/MapEditor.dir/MapEditor.cpp.o: CMakeFiles/MapEditor.dir/flags.make
CMakeFiles/MapEditor.dir/MapEditor.cpp.o: ../MapEditor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MapEditor.dir/MapEditor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MapEditor.dir/MapEditor.cpp.o -c /home/clemente/projects/Troll-Killers/MapEditor.cpp

CMakeFiles/MapEditor.dir/MapEditor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MapEditor.dir/MapEditor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/MapEditor.cpp > CMakeFiles/MapEditor.dir/MapEditor.cpp.i

CMakeFiles/MapEditor.dir/MapEditor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MapEditor.dir/MapEditor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/MapEditor.cpp -o CMakeFiles/MapEditor.dir/MapEditor.cpp.s

CMakeFiles/MapEditor.dir/MapEditor.cpp.o.requires:

.PHONY : CMakeFiles/MapEditor.dir/MapEditor.cpp.o.requires

CMakeFiles/MapEditor.dir/MapEditor.cpp.o.provides: CMakeFiles/MapEditor.dir/MapEditor.cpp.o.requires
	$(MAKE) -f CMakeFiles/MapEditor.dir/build.make CMakeFiles/MapEditor.dir/MapEditor.cpp.o.provides.build
.PHONY : CMakeFiles/MapEditor.dir/MapEditor.cpp.o.provides

CMakeFiles/MapEditor.dir/MapEditor.cpp.o.provides.build: CMakeFiles/MapEditor.dir/MapEditor.cpp.o


CMakeFiles/MapEditor.dir/Map.cpp.o: CMakeFiles/MapEditor.dir/flags.make
CMakeFiles/MapEditor.dir/Map.cpp.o: ../Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MapEditor.dir/Map.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MapEditor.dir/Map.cpp.o -c /home/clemente/projects/Troll-Killers/Map.cpp

CMakeFiles/MapEditor.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MapEditor.dir/Map.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Map.cpp > CMakeFiles/MapEditor.dir/Map.cpp.i

CMakeFiles/MapEditor.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MapEditor.dir/Map.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Map.cpp -o CMakeFiles/MapEditor.dir/Map.cpp.s

CMakeFiles/MapEditor.dir/Map.cpp.o.requires:

.PHONY : CMakeFiles/MapEditor.dir/Map.cpp.o.requires

CMakeFiles/MapEditor.dir/Map.cpp.o.provides: CMakeFiles/MapEditor.dir/Map.cpp.o.requires
	$(MAKE) -f CMakeFiles/MapEditor.dir/build.make CMakeFiles/MapEditor.dir/Map.cpp.o.provides.build
.PHONY : CMakeFiles/MapEditor.dir/Map.cpp.o.provides

CMakeFiles/MapEditor.dir/Map.cpp.o.provides.build: CMakeFiles/MapEditor.dir/Map.cpp.o


CMakeFiles/MapEditor.dir/CMap.cpp.o: CMakeFiles/MapEditor.dir/flags.make
CMakeFiles/MapEditor.dir/CMap.cpp.o: ../CMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MapEditor.dir/CMap.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MapEditor.dir/CMap.cpp.o -c /home/clemente/projects/Troll-Killers/CMap.cpp

CMakeFiles/MapEditor.dir/CMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MapEditor.dir/CMap.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/CMap.cpp > CMakeFiles/MapEditor.dir/CMap.cpp.i

CMakeFiles/MapEditor.dir/CMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MapEditor.dir/CMap.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/CMap.cpp -o CMakeFiles/MapEditor.dir/CMap.cpp.s

CMakeFiles/MapEditor.dir/CMap.cpp.o.requires:

.PHONY : CMakeFiles/MapEditor.dir/CMap.cpp.o.requires

CMakeFiles/MapEditor.dir/CMap.cpp.o.provides: CMakeFiles/MapEditor.dir/CMap.cpp.o.requires
	$(MAKE) -f CMakeFiles/MapEditor.dir/build.make CMakeFiles/MapEditor.dir/CMap.cpp.o.provides.build
.PHONY : CMakeFiles/MapEditor.dir/CMap.cpp.o.provides

CMakeFiles/MapEditor.dir/CMap.cpp.o.provides.build: CMakeFiles/MapEditor.dir/CMap.cpp.o


CMakeFiles/MapEditor.dir/Cursor.cpp.o: CMakeFiles/MapEditor.dir/flags.make
CMakeFiles/MapEditor.dir/Cursor.cpp.o: ../Cursor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MapEditor.dir/Cursor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MapEditor.dir/Cursor.cpp.o -c /home/clemente/projects/Troll-Killers/Cursor.cpp

CMakeFiles/MapEditor.dir/Cursor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MapEditor.dir/Cursor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Cursor.cpp > CMakeFiles/MapEditor.dir/Cursor.cpp.i

CMakeFiles/MapEditor.dir/Cursor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MapEditor.dir/Cursor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Cursor.cpp -o CMakeFiles/MapEditor.dir/Cursor.cpp.s

CMakeFiles/MapEditor.dir/Cursor.cpp.o.requires:

.PHONY : CMakeFiles/MapEditor.dir/Cursor.cpp.o.requires

CMakeFiles/MapEditor.dir/Cursor.cpp.o.provides: CMakeFiles/MapEditor.dir/Cursor.cpp.o.requires
	$(MAKE) -f CMakeFiles/MapEditor.dir/build.make CMakeFiles/MapEditor.dir/Cursor.cpp.o.provides.build
.PHONY : CMakeFiles/MapEditor.dir/Cursor.cpp.o.provides

CMakeFiles/MapEditor.dir/Cursor.cpp.o.provides.build: CMakeFiles/MapEditor.dir/Cursor.cpp.o


# Object files for target MapEditor
MapEditor_OBJECTS = \
"CMakeFiles/MapEditor.dir/editorMain.cpp.o" \
"CMakeFiles/MapEditor.dir/MapEditor.cpp.o" \
"CMakeFiles/MapEditor.dir/Map.cpp.o" \
"CMakeFiles/MapEditor.dir/CMap.cpp.o" \
"CMakeFiles/MapEditor.dir/Cursor.cpp.o"

# External object files for target MapEditor
MapEditor_EXTERNAL_OBJECTS =

MapEditor: CMakeFiles/MapEditor.dir/editorMain.cpp.o
MapEditor: CMakeFiles/MapEditor.dir/MapEditor.cpp.o
MapEditor: CMakeFiles/MapEditor.dir/Map.cpp.o
MapEditor: CMakeFiles/MapEditor.dir/CMap.cpp.o
MapEditor: CMakeFiles/MapEditor.dir/Cursor.cpp.o
MapEditor: CMakeFiles/MapEditor.dir/build.make
MapEditor: CMakeFiles/MapEditor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable MapEditor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MapEditor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MapEditor.dir/build: MapEditor

.PHONY : CMakeFiles/MapEditor.dir/build

CMakeFiles/MapEditor.dir/requires: CMakeFiles/MapEditor.dir/editorMain.cpp.o.requires
CMakeFiles/MapEditor.dir/requires: CMakeFiles/MapEditor.dir/MapEditor.cpp.o.requires
CMakeFiles/MapEditor.dir/requires: CMakeFiles/MapEditor.dir/Map.cpp.o.requires
CMakeFiles/MapEditor.dir/requires: CMakeFiles/MapEditor.dir/CMap.cpp.o.requires
CMakeFiles/MapEditor.dir/requires: CMakeFiles/MapEditor.dir/Cursor.cpp.o.requires

.PHONY : CMakeFiles/MapEditor.dir/requires

CMakeFiles/MapEditor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MapEditor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MapEditor.dir/clean

CMakeFiles/MapEditor.dir/depend:
	cd /home/clemente/projects/Troll-Killers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clemente/projects/Troll-Killers /home/clemente/projects/Troll-Killers /home/clemente/projects/Troll-Killers/build /home/clemente/projects/Troll-Killers/build /home/clemente/projects/Troll-Killers/build/CMakeFiles/MapEditor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MapEditor.dir/depend

