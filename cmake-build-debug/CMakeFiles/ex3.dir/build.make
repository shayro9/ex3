# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\michalmaya\Documents\GitHub\ex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\michalmaya\Documents\GitHub\ex3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ex3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ex3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex3.dir/flags.make

CMakeFiles/ex3.dir/QueueExampleTests.cpp.obj: CMakeFiles/ex3.dir/flags.make
CMakeFiles/ex3.dir/QueueExampleTests.cpp.obj: CMakeFiles/ex3.dir/includes_CXX.rsp
CMakeFiles/ex3.dir/QueueExampleTests.cpp.obj: ../QueueExampleTests.cpp
CMakeFiles/ex3.dir/QueueExampleTests.cpp.obj: CMakeFiles/ex3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\michalmaya\Documents\GitHub\ex3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex3.dir/QueueExampleTests.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ex3.dir/QueueExampleTests.cpp.obj -MF CMakeFiles\ex3.dir\QueueExampleTests.cpp.obj.d -o CMakeFiles\ex3.dir\QueueExampleTests.cpp.obj -c C:\Users\michalmaya\Documents\GitHub\ex3\QueueExampleTests.cpp

CMakeFiles/ex3.dir/QueueExampleTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex3.dir/QueueExampleTests.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\michalmaya\Documents\GitHub\ex3\QueueExampleTests.cpp > CMakeFiles\ex3.dir\QueueExampleTests.cpp.i

CMakeFiles/ex3.dir/QueueExampleTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex3.dir/QueueExampleTests.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\michalmaya\Documents\GitHub\ex3\QueueExampleTests.cpp -o CMakeFiles\ex3.dir\QueueExampleTests.cpp.s

CMakeFiles/ex3.dir/TestMain.cpp.obj: CMakeFiles/ex3.dir/flags.make
CMakeFiles/ex3.dir/TestMain.cpp.obj: CMakeFiles/ex3.dir/includes_CXX.rsp
CMakeFiles/ex3.dir/TestMain.cpp.obj: ../TestMain.cpp
CMakeFiles/ex3.dir/TestMain.cpp.obj: CMakeFiles/ex3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\michalmaya\Documents\GitHub\ex3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ex3.dir/TestMain.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ex3.dir/TestMain.cpp.obj -MF CMakeFiles\ex3.dir\TestMain.cpp.obj.d -o CMakeFiles\ex3.dir\TestMain.cpp.obj -c C:\Users\michalmaya\Documents\GitHub\ex3\TestMain.cpp

CMakeFiles/ex3.dir/TestMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex3.dir/TestMain.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\michalmaya\Documents\GitHub\ex3\TestMain.cpp > CMakeFiles\ex3.dir\TestMain.cpp.i

CMakeFiles/ex3.dir/TestMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex3.dir/TestMain.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\michalmaya\Documents\GitHub\ex3\TestMain.cpp -o CMakeFiles\ex3.dir\TestMain.cpp.s

# Object files for target ex3
ex3_OBJECTS = \
"CMakeFiles/ex3.dir/QueueExampleTests.cpp.obj" \
"CMakeFiles/ex3.dir/TestMain.cpp.obj"

# External object files for target ex3
ex3_EXTERNAL_OBJECTS =

ex3.exe: CMakeFiles/ex3.dir/QueueExampleTests.cpp.obj
ex3.exe: CMakeFiles/ex3.dir/TestMain.cpp.obj
ex3.exe: CMakeFiles/ex3.dir/build.make
ex3.exe: CMakeFiles/ex3.dir/linklibs.rsp
ex3.exe: CMakeFiles/ex3.dir/objects1.rsp
ex3.exe: CMakeFiles/ex3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\michalmaya\Documents\GitHub\ex3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ex3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex3.dir/build: ex3.exe
.PHONY : CMakeFiles/ex3.dir/build

CMakeFiles/ex3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex3.dir/clean

CMakeFiles/ex3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\michalmaya\Documents\GitHub\ex3 C:\Users\michalmaya\Documents\GitHub\ex3 C:\Users\michalmaya\Documents\GitHub\ex3\cmake-build-debug C:\Users\michalmaya\Documents\GitHub\ex3\cmake-build-debug C:\Users\michalmaya\Documents\GitHub\ex3\cmake-build-debug\CMakeFiles\ex3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex3.dir/depend

