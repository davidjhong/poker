# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/build

# Include any dependencies generated for this target.
include CMakeFiles/savefileTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/savefileTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/savefileTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/savefileTest.dir/flags.make

CMakeFiles/savefileTest.dir/tests/savefile.cpp.o: CMakeFiles/savefileTest.dir/flags.make
CMakeFiles/savefileTest.dir/tests/savefile.cpp.o: ../tests/savefile.cpp
CMakeFiles/savefileTest.dir/tests/savefile.cpp.o: CMakeFiles/savefileTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/savefileTest.dir/tests/savefile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/savefileTest.dir/tests/savefile.cpp.o -MF CMakeFiles/savefileTest.dir/tests/savefile.cpp.o.d -o CMakeFiles/savefileTest.dir/tests/savefile.cpp.o -c /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/tests/savefile.cpp

CMakeFiles/savefileTest.dir/tests/savefile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/savefileTest.dir/tests/savefile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/tests/savefile.cpp > CMakeFiles/savefileTest.dir/tests/savefile.cpp.i

CMakeFiles/savefileTest.dir/tests/savefile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/savefileTest.dir/tests/savefile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/tests/savefile.cpp -o CMakeFiles/savefileTest.dir/tests/savefile.cpp.s

CMakeFiles/savefileTest.dir/src/Savefile.cpp.o: CMakeFiles/savefileTest.dir/flags.make
CMakeFiles/savefileTest.dir/src/Savefile.cpp.o: ../src/Savefile.cpp
CMakeFiles/savefileTest.dir/src/Savefile.cpp.o: CMakeFiles/savefileTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/savefileTest.dir/src/Savefile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/savefileTest.dir/src/Savefile.cpp.o -MF CMakeFiles/savefileTest.dir/src/Savefile.cpp.o.d -o CMakeFiles/savefileTest.dir/src/Savefile.cpp.o -c /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/src/Savefile.cpp

CMakeFiles/savefileTest.dir/src/Savefile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/savefileTest.dir/src/Savefile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/src/Savefile.cpp > CMakeFiles/savefileTest.dir/src/Savefile.cpp.i

CMakeFiles/savefileTest.dir/src/Savefile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/savefileTest.dir/src/Savefile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/src/Savefile.cpp -o CMakeFiles/savefileTest.dir/src/Savefile.cpp.s

# Object files for target savefileTest
savefileTest_OBJECTS = \
"CMakeFiles/savefileTest.dir/tests/savefile.cpp.o" \
"CMakeFiles/savefileTest.dir/src/Savefile.cpp.o"

# External object files for target savefileTest
savefileTest_EXTERNAL_OBJECTS =

savefileTest: CMakeFiles/savefileTest.dir/tests/savefile.cpp.o
savefileTest: CMakeFiles/savefileTest.dir/src/Savefile.cpp.o
savefileTest: CMakeFiles/savefileTest.dir/build.make
savefileTest: CMakeFiles/savefileTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable savefileTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/savefileTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/savefileTest.dir/build: savefileTest
.PHONY : CMakeFiles/savefileTest.dir/build

CMakeFiles/savefileTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/savefileTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/savefileTest.dir/clean

CMakeFiles/savefileTest.dir/depend:
	cd /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085 /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085 /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/build /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/build /home/csmajs/jan058/final-project-khe035-dhong050-jan058-ctang085/build/CMakeFiles/savefileTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/savefileTest.dir/depend
