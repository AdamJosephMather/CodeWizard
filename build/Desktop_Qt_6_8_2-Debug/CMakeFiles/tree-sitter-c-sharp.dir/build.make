# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/adamj/Documents/QtProjects/CodeWizard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug

# Include any dependencies generated for this target.
include CMakeFiles/tree-sitter-c-sharp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tree-sitter-c-sharp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tree-sitter-c-sharp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree-sitter-c-sharp.dir/flags.make

CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.o: CMakeFiles/tree-sitter-c-sharp.dir/flags.make
CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.o: tree-sitter-c-sharp_autogen/mocs_compilation.cpp
CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.o: CMakeFiles/tree-sitter-c-sharp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.o -MF CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.o -c /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug/tree-sitter-c-sharp_autogen/mocs_compilation.cpp

CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug/tree-sitter-c-sharp_autogen/mocs_compilation.cpp > CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.i

CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug/tree-sitter-c-sharp_autogen/mocs_compilation.cpp -o CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.s

# Object files for target tree-sitter-c-sharp
tree__sitter__c__sharp_OBJECTS = \
"CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.o"

# External object files for target tree-sitter-c-sharp
tree__sitter__c__sharp_EXTERNAL_OBJECTS =

libtree-sitter-c-sharp.a: CMakeFiles/tree-sitter-c-sharp.dir/tree-sitter-c-sharp_autogen/mocs_compilation.cpp.o
libtree-sitter-c-sharp.a: CMakeFiles/tree-sitter-c-sharp.dir/build.make
libtree-sitter-c-sharp.a: CMakeFiles/tree-sitter-c-sharp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtree-sitter-c-sharp.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tree-sitter-c-sharp.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tree-sitter-c-sharp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree-sitter-c-sharp.dir/build: libtree-sitter-c-sharp.a
.PHONY : CMakeFiles/tree-sitter-c-sharp.dir/build

CMakeFiles/tree-sitter-c-sharp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tree-sitter-c-sharp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tree-sitter-c-sharp.dir/clean

CMakeFiles/tree-sitter-c-sharp.dir/depend:
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adamj/Documents/QtProjects/CodeWizard /home/adamj/Documents/QtProjects/CodeWizard /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Debug/CMakeFiles/tree-sitter-c-sharp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tree-sitter-c-sharp.dir/depend

