# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/mainClient.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/mainClient.cpp.o: ../mainClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/mainClient.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/mainClient.cpp.o -c /home/clemente/projects/Troll-Killers/mainClient.cpp

CMakeFiles/Client.dir/mainClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/mainClient.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/mainClient.cpp > CMakeFiles/Client.dir/mainClient.cpp.i

CMakeFiles/Client.dir/mainClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/mainClient.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/mainClient.cpp -o CMakeFiles/Client.dir/mainClient.cpp.s

CMakeFiles/Client.dir/mainClient.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/mainClient.cpp.o.requires

CMakeFiles/Client.dir/mainClient.cpp.o.provides: CMakeFiles/Client.dir/mainClient.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/mainClient.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/mainClient.cpp.o.provides

CMakeFiles/Client.dir/mainClient.cpp.o.provides.build: CMakeFiles/Client.dir/mainClient.cpp.o


CMakeFiles/Client.dir/CMap.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/CMap.cpp.o: ../CMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/CMap.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/CMap.cpp.o -c /home/clemente/projects/Troll-Killers/CMap.cpp

CMakeFiles/Client.dir/CMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/CMap.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/CMap.cpp > CMakeFiles/Client.dir/CMap.cpp.i

CMakeFiles/Client.dir/CMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/CMap.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/CMap.cpp -o CMakeFiles/Client.dir/CMap.cpp.s

CMakeFiles/Client.dir/CMap.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/CMap.cpp.o.requires

CMakeFiles/Client.dir/CMap.cpp.o.provides: CMakeFiles/Client.dir/CMap.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/CMap.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/CMap.cpp.o.provides

CMakeFiles/Client.dir/CMap.cpp.o.provides.build: CMakeFiles/Client.dir/CMap.cpp.o


CMakeFiles/Client.dir/Map.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Map.cpp.o: ../Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Client.dir/Map.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Map.cpp.o -c /home/clemente/projects/Troll-Killers/Map.cpp

CMakeFiles/Client.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Map.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Map.cpp > CMakeFiles/Client.dir/Map.cpp.i

CMakeFiles/Client.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Map.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Map.cpp -o CMakeFiles/Client.dir/Map.cpp.s

CMakeFiles/Client.dir/Map.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Map.cpp.o.requires

CMakeFiles/Client.dir/Map.cpp.o.provides: CMakeFiles/Client.dir/Map.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Map.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Map.cpp.o.provides

CMakeFiles/Client.dir/Map.cpp.o.provides.build: CMakeFiles/Client.dir/Map.cpp.o


CMakeFiles/Client.dir/Client.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Client.dir/Client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Client.cpp.o -c /home/clemente/projects/Troll-Killers/Client.cpp

CMakeFiles/Client.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Client.cpp > CMakeFiles/Client.dir/Client.cpp.i

CMakeFiles/Client.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Client.cpp -o CMakeFiles/Client.dir/Client.cpp.s

CMakeFiles/Client.dir/Client.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Client.cpp.o.requires

CMakeFiles/Client.dir/Client.cpp.o.provides: CMakeFiles/Client.dir/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Client.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Client.cpp.o.provides

CMakeFiles/Client.dir/Client.cpp.o.provides.build: CMakeFiles/Client.dir/Client.cpp.o


CMakeFiles/Client.dir/Configuration.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Configuration.cpp.o: ../Configuration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Client.dir/Configuration.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Configuration.cpp.o -c /home/clemente/projects/Troll-Killers/Configuration.cpp

CMakeFiles/Client.dir/Configuration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Configuration.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Configuration.cpp > CMakeFiles/Client.dir/Configuration.cpp.i

CMakeFiles/Client.dir/Configuration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Configuration.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Configuration.cpp -o CMakeFiles/Client.dir/Configuration.cpp.s

CMakeFiles/Client.dir/Configuration.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Configuration.cpp.o.requires

CMakeFiles/Client.dir/Configuration.cpp.o.provides: CMakeFiles/Client.dir/Configuration.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Configuration.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Configuration.cpp.o.provides

CMakeFiles/Client.dir/Configuration.cpp.o.provides.build: CMakeFiles/Client.dir/Configuration.cpp.o


CMakeFiles/Client.dir/Connection.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Connection.cpp.o: ../Connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Client.dir/Connection.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Connection.cpp.o -c /home/clemente/projects/Troll-Killers/Connection.cpp

CMakeFiles/Client.dir/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Connection.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Connection.cpp > CMakeFiles/Client.dir/Connection.cpp.i

CMakeFiles/Client.dir/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Connection.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Connection.cpp -o CMakeFiles/Client.dir/Connection.cpp.s

CMakeFiles/Client.dir/Connection.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Connection.cpp.o.requires

CMakeFiles/Client.dir/Connection.cpp.o.provides: CMakeFiles/Client.dir/Connection.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Connection.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Connection.cpp.o.provides

CMakeFiles/Client.dir/Connection.cpp.o.provides.build: CMakeFiles/Client.dir/Connection.cpp.o


CMakeFiles/Client.dir/CCharacter.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/CCharacter.cpp.o: ../CCharacter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Client.dir/CCharacter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/CCharacter.cpp.o -c /home/clemente/projects/Troll-Killers/CCharacter.cpp

CMakeFiles/Client.dir/CCharacter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/CCharacter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/CCharacter.cpp > CMakeFiles/Client.dir/CCharacter.cpp.i

CMakeFiles/Client.dir/CCharacter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/CCharacter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/CCharacter.cpp -o CMakeFiles/Client.dir/CCharacter.cpp.s

CMakeFiles/Client.dir/CCharacter.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/CCharacter.cpp.o.requires

CMakeFiles/Client.dir/CCharacter.cpp.o.provides: CMakeFiles/Client.dir/CCharacter.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/CCharacter.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/CCharacter.cpp.o.provides

CMakeFiles/Client.dir/CCharacter.cpp.o.provides.build: CMakeFiles/Client.dir/CCharacter.cpp.o


CMakeFiles/Client.dir/Weapons.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Weapons.cpp.o: ../Weapons.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Client.dir/Weapons.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Weapons.cpp.o -c /home/clemente/projects/Troll-Killers/Weapons.cpp

CMakeFiles/Client.dir/Weapons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Weapons.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Weapons.cpp > CMakeFiles/Client.dir/Weapons.cpp.i

CMakeFiles/Client.dir/Weapons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Weapons.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Weapons.cpp -o CMakeFiles/Client.dir/Weapons.cpp.s

CMakeFiles/Client.dir/Weapons.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Weapons.cpp.o.requires

CMakeFiles/Client.dir/Weapons.cpp.o.provides: CMakeFiles/Client.dir/Weapons.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Weapons.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Weapons.cpp.o.provides

CMakeFiles/Client.dir/Weapons.cpp.o.provides.build: CMakeFiles/Client.dir/Weapons.cpp.o


CMakeFiles/Client.dir/Rifle.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Rifle.cpp.o: ../Rifle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Client.dir/Rifle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Rifle.cpp.o -c /home/clemente/projects/Troll-Killers/Rifle.cpp

CMakeFiles/Client.dir/Rifle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Rifle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Rifle.cpp > CMakeFiles/Client.dir/Rifle.cpp.i

CMakeFiles/Client.dir/Rifle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Rifle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Rifle.cpp -o CMakeFiles/Client.dir/Rifle.cpp.s

CMakeFiles/Client.dir/Rifle.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Rifle.cpp.o.requires

CMakeFiles/Client.dir/Rifle.cpp.o.provides: CMakeFiles/Client.dir/Rifle.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Rifle.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Rifle.cpp.o.provides

CMakeFiles/Client.dir/Rifle.cpp.o.provides.build: CMakeFiles/Client.dir/Rifle.cpp.o


CMakeFiles/Client.dir/Pistol.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Pistol.cpp.o: ../Pistol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Client.dir/Pistol.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Pistol.cpp.o -c /home/clemente/projects/Troll-Killers/Pistol.cpp

CMakeFiles/Client.dir/Pistol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Pistol.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Pistol.cpp > CMakeFiles/Client.dir/Pistol.cpp.i

CMakeFiles/Client.dir/Pistol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Pistol.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Pistol.cpp -o CMakeFiles/Client.dir/Pistol.cpp.s

CMakeFiles/Client.dir/Pistol.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Pistol.cpp.o.requires

CMakeFiles/Client.dir/Pistol.cpp.o.provides: CMakeFiles/Client.dir/Pistol.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Pistol.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Pistol.cpp.o.provides

CMakeFiles/Client.dir/Pistol.cpp.o.provides.build: CMakeFiles/Client.dir/Pistol.cpp.o


CMakeFiles/Client.dir/Projectile.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Projectile.cpp.o: ../Projectile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Client.dir/Projectile.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Projectile.cpp.o -c /home/clemente/projects/Troll-Killers/Projectile.cpp

CMakeFiles/Client.dir/Projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Projectile.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Projectile.cpp > CMakeFiles/Client.dir/Projectile.cpp.i

CMakeFiles/Client.dir/Projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Projectile.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Projectile.cpp -o CMakeFiles/Client.dir/Projectile.cpp.s

CMakeFiles/Client.dir/Projectile.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Projectile.cpp.o.requires

CMakeFiles/Client.dir/Projectile.cpp.o.provides: CMakeFiles/Client.dir/Projectile.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Projectile.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Projectile.cpp.o.provides

CMakeFiles/Client.dir/Projectile.cpp.o.provides.build: CMakeFiles/Client.dir/Projectile.cpp.o


CMakeFiles/Client.dir/CProjectile.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/CProjectile.cpp.o: ../CProjectile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Client.dir/CProjectile.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/CProjectile.cpp.o -c /home/clemente/projects/Troll-Killers/CProjectile.cpp

CMakeFiles/Client.dir/CProjectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/CProjectile.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/CProjectile.cpp > CMakeFiles/Client.dir/CProjectile.cpp.i

CMakeFiles/Client.dir/CProjectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/CProjectile.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/CProjectile.cpp -o CMakeFiles/Client.dir/CProjectile.cpp.s

CMakeFiles/Client.dir/CProjectile.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/CProjectile.cpp.o.requires

CMakeFiles/Client.dir/CProjectile.cpp.o.provides: CMakeFiles/Client.dir/CProjectile.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/CProjectile.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/CProjectile.cpp.o.provides

CMakeFiles/Client.dir/CProjectile.cpp.o.provides.build: CMakeFiles/Client.dir/CProjectile.cpp.o


CMakeFiles/Client.dir/Menu.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Menu.cpp.o: ../Menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Client.dir/Menu.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Menu.cpp.o -c /home/clemente/projects/Troll-Killers/Menu.cpp

CMakeFiles/Client.dir/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Menu.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/Menu.cpp > CMakeFiles/Client.dir/Menu.cpp.i

CMakeFiles/Client.dir/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Menu.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/Menu.cpp -o CMakeFiles/Client.dir/Menu.cpp.s

CMakeFiles/Client.dir/Menu.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Menu.cpp.o.requires

CMakeFiles/Client.dir/Menu.cpp.o.provides: CMakeFiles/Client.dir/Menu.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Menu.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Menu.cpp.o.provides

CMakeFiles/Client.dir/Menu.cpp.o.provides.build: CMakeFiles/Client.dir/Menu.cpp.o


CMakeFiles/Client.dir/MenuManager.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/MenuManager.cpp.o: ../MenuManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Client.dir/MenuManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/MenuManager.cpp.o -c /home/clemente/projects/Troll-Killers/MenuManager.cpp

CMakeFiles/Client.dir/MenuManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/MenuManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/projects/Troll-Killers/MenuManager.cpp > CMakeFiles/Client.dir/MenuManager.cpp.i

CMakeFiles/Client.dir/MenuManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/MenuManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/projects/Troll-Killers/MenuManager.cpp -o CMakeFiles/Client.dir/MenuManager.cpp.s

CMakeFiles/Client.dir/MenuManager.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/MenuManager.cpp.o.requires

CMakeFiles/Client.dir/MenuManager.cpp.o.provides: CMakeFiles/Client.dir/MenuManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/MenuManager.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/MenuManager.cpp.o.provides

CMakeFiles/Client.dir/MenuManager.cpp.o.provides.build: CMakeFiles/Client.dir/MenuManager.cpp.o


# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/mainClient.cpp.o" \
"CMakeFiles/Client.dir/CMap.cpp.o" \
"CMakeFiles/Client.dir/Map.cpp.o" \
"CMakeFiles/Client.dir/Client.cpp.o" \
"CMakeFiles/Client.dir/Configuration.cpp.o" \
"CMakeFiles/Client.dir/Connection.cpp.o" \
"CMakeFiles/Client.dir/CCharacter.cpp.o" \
"CMakeFiles/Client.dir/Weapons.cpp.o" \
"CMakeFiles/Client.dir/Rifle.cpp.o" \
"CMakeFiles/Client.dir/Pistol.cpp.o" \
"CMakeFiles/Client.dir/Projectile.cpp.o" \
"CMakeFiles/Client.dir/CProjectile.cpp.o" \
"CMakeFiles/Client.dir/Menu.cpp.o" \
"CMakeFiles/Client.dir/MenuManager.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/mainClient.cpp.o
Client: CMakeFiles/Client.dir/CMap.cpp.o
Client: CMakeFiles/Client.dir/Map.cpp.o
Client: CMakeFiles/Client.dir/Client.cpp.o
Client: CMakeFiles/Client.dir/Configuration.cpp.o
Client: CMakeFiles/Client.dir/Connection.cpp.o
Client: CMakeFiles/Client.dir/CCharacter.cpp.o
Client: CMakeFiles/Client.dir/Weapons.cpp.o
Client: CMakeFiles/Client.dir/Rifle.cpp.o
Client: CMakeFiles/Client.dir/Pistol.cpp.o
Client: CMakeFiles/Client.dir/Projectile.cpp.o
Client: CMakeFiles/Client.dir/CProjectile.cpp.o
Client: CMakeFiles/Client.dir/Menu.cpp.o
Client: CMakeFiles/Client.dir/MenuManager.cpp.o
Client: CMakeFiles/Client.dir/build.make
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clemente/projects/Troll-Killers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/mainClient.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/CMap.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Map.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Client.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Configuration.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Connection.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/CCharacter.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Weapons.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Rifle.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Pistol.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Projectile.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/CProjectile.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Menu.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/MenuManager.cpp.o.requires

.PHONY : CMakeFiles/Client.dir/requires

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd /home/clemente/projects/Troll-Killers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clemente/projects/Troll-Killers /home/clemente/projects/Troll-Killers /home/clemente/projects/Troll-Killers/build /home/clemente/projects/Troll-Killers/build /home/clemente/projects/Troll-Killers/build/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

