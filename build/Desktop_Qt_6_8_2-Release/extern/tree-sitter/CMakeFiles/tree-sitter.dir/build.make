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
CMAKE_BINARY_DIR = /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release

# Include any dependencies generated for this target.
include extern/tree-sitter/CMakeFiles/tree-sitter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.make

# Include the progress variables for this target.
include extern/tree-sitter/CMakeFiles/tree-sitter.dir/progress.make

# Include the compile flags for this target's objects.
include extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make

extern/tree-sitter/tree-sitter_autogen/timestamp: /home/adamj/Qt/6.8.2/gcc_64/libexec/moc
extern/tree-sitter/tree-sitter_autogen/timestamp: /home/adamj/Qt/6.8.2/gcc_64/libexec/uic
extern/tree-sitter/tree-sitter_autogen/timestamp: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target tree-sitter"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /usr/bin/cmake -E cmake_autogen /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter/CMakeFiles/tree-sitter_autogen.dir/AutogenInfo.json Release
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /usr/bin/cmake -E touch /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter/tree-sitter_autogen/timestamp

extern/tree-sitter/CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make
extern/tree-sitter/CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.o: extern/tree-sitter/tree-sitter_autogen/mocs_compilation.cpp
extern/tree-sitter/CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object extern/tree-sitter/CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.o"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT extern/tree-sitter/CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.o -MF CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.o -c /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter/tree-sitter_autogen/mocs_compilation.cpp

extern/tree-sitter/CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.i"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter/tree-sitter_autogen/mocs_compilation.cpp > CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.i

extern/tree-sitter/CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.s"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter/tree-sitter_autogen/mocs_compilation.cpp -o CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.s

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lib.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lib.c.o: /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/lib.c
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lib.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lib.c.o"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lib.c.o -MF CMakeFiles/tree-sitter.dir/lib/src/lib.c.o.d -o CMakeFiles/tree-sitter.dir/lib/src/lib.c.o -c /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/lib.c

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/tree-sitter.dir/lib/src/lib.c.i"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/lib.c > CMakeFiles/tree-sitter.dir/lib/src/lib.c.i

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/tree-sitter.dir/lib/src/lib.c.s"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/lib.c -o CMakeFiles/tree-sitter.dir/lib/src/lib.c.s

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lexer.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lexer.c.o: /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/lexer.c
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lexer.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lexer.c.o"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lexer.c.o -MF CMakeFiles/tree-sitter.dir/lib/src/lexer.c.o.d -o CMakeFiles/tree-sitter.dir/lib/src/lexer.c.o -c /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/lexer.c

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/tree-sitter.dir/lib/src/lexer.c.i"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/lexer.c > CMakeFiles/tree-sitter.dir/lib/src/lexer.c.i

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/tree-sitter.dir/lib/src/lexer.c.s"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/lexer.c -o CMakeFiles/tree-sitter.dir/lib/src/lexer.c.s

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/tree.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/tree.c.o: /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/tree.c
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/tree.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/tree.c.o"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/tree.c.o -MF CMakeFiles/tree-sitter.dir/lib/src/tree.c.o.d -o CMakeFiles/tree-sitter.dir/lib/src/tree.c.o -c /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/tree.c

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/tree-sitter.dir/lib/src/tree.c.i"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/tree.c > CMakeFiles/tree-sitter.dir/lib/src/tree.c.i

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/tree-sitter.dir/lib/src/tree.c.s"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/tree.c -o CMakeFiles/tree-sitter.dir/lib/src/tree.c.s

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/node.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/node.c.o: /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/node.c
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/node.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/node.c.o"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/node.c.o -MF CMakeFiles/tree-sitter.dir/lib/src/node.c.o.d -o CMakeFiles/tree-sitter.dir/lib/src/node.c.o -c /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/node.c

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/tree-sitter.dir/lib/src/node.c.i"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/node.c > CMakeFiles/tree-sitter.dir/lib/src/node.c.i

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/tree-sitter.dir/lib/src/node.c.s"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/node.c -o CMakeFiles/tree-sitter.dir/lib/src/node.c.s

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/query.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/query.c.o: /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/query.c
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/query.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/query.c.o"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/query.c.o -MF CMakeFiles/tree-sitter.dir/lib/src/query.c.o.d -o CMakeFiles/tree-sitter.dir/lib/src/query.c.o -c /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/query.c

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/query.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/tree-sitter.dir/lib/src/query.c.i"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/query.c > CMakeFiles/tree-sitter.dir/lib/src/query.c.i

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/query.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/tree-sitter.dir/lib/src/query.c.s"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/query.c -o CMakeFiles/tree-sitter.dir/lib/src/query.c.s

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/stack.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/stack.c.o: /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/stack.c
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/stack.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/stack.c.o"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/stack.c.o -MF CMakeFiles/tree-sitter.dir/lib/src/stack.c.o.d -o CMakeFiles/tree-sitter.dir/lib/src/stack.c.o -c /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/stack.c

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/tree-sitter.dir/lib/src/stack.c.i"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/stack.c > CMakeFiles/tree-sitter.dir/lib/src/stack.c.i

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/tree-sitter.dir/lib/src/stack.c.s"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/stack.c -o CMakeFiles/tree-sitter.dir/lib/src/stack.c.s

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/language.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/language.c.o: /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/language.c
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/language.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/language.c.o"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/language.c.o -MF CMakeFiles/tree-sitter.dir/lib/src/language.c.o.d -o CMakeFiles/tree-sitter.dir/lib/src/language.c.o -c /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/language.c

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/language.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/tree-sitter.dir/lib/src/language.c.i"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/language.c > CMakeFiles/tree-sitter.dir/lib/src/language.c.i

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/language.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/tree-sitter.dir/lib/src/language.c.s"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/language.c -o CMakeFiles/tree-sitter.dir/lib/src/language.c.s

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/subtree.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/flags.make
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/subtree.c.o: /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/subtree.c
extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/subtree.c.o: extern/tree-sitter/CMakeFiles/tree-sitter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/subtree.c.o"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/subtree.c.o -MF CMakeFiles/tree-sitter.dir/lib/src/subtree.c.o.d -o CMakeFiles/tree-sitter.dir/lib/src/subtree.c.o -c /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/subtree.c

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/subtree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/tree-sitter.dir/lib/src/subtree.c.i"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/subtree.c > CMakeFiles/tree-sitter.dir/lib/src/subtree.c.i

extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/subtree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/tree-sitter.dir/lib/src/subtree.c.s"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter/lib/src/subtree.c -o CMakeFiles/tree-sitter.dir/lib/src/subtree.c.s

# Object files for target tree-sitter
tree__sitter_OBJECTS = \
"CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/tree-sitter.dir/lib/src/lib.c.o" \
"CMakeFiles/tree-sitter.dir/lib/src/lexer.c.o" \
"CMakeFiles/tree-sitter.dir/lib/src/tree.c.o" \
"CMakeFiles/tree-sitter.dir/lib/src/node.c.o" \
"CMakeFiles/tree-sitter.dir/lib/src/query.c.o" \
"CMakeFiles/tree-sitter.dir/lib/src/stack.c.o" \
"CMakeFiles/tree-sitter.dir/lib/src/language.c.o" \
"CMakeFiles/tree-sitter.dir/lib/src/subtree.c.o"

# External object files for target tree-sitter
tree__sitter_EXTERNAL_OBJECTS =

extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/tree-sitter_autogen/mocs_compilation.cpp.o
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lib.c.o
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/lexer.c.o
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/tree.c.o
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/node.c.o
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/query.c.o
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/stack.c.o
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/language.c.o
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/lib/src/subtree.c.o
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/build.make
extern/tree-sitter/libtree-sitter.a: extern/tree-sitter/CMakeFiles/tree-sitter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX static library libtree-sitter.a"
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && $(CMAKE_COMMAND) -P CMakeFiles/tree-sitter.dir/cmake_clean_target.cmake
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tree-sitter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/tree-sitter/CMakeFiles/tree-sitter.dir/build: extern/tree-sitter/libtree-sitter.a
.PHONY : extern/tree-sitter/CMakeFiles/tree-sitter.dir/build

extern/tree-sitter/CMakeFiles/tree-sitter.dir/clean:
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter && $(CMAKE_COMMAND) -P CMakeFiles/tree-sitter.dir/cmake_clean.cmake
.PHONY : extern/tree-sitter/CMakeFiles/tree-sitter.dir/clean

extern/tree-sitter/CMakeFiles/tree-sitter.dir/depend: extern/tree-sitter/tree-sitter_autogen/timestamp
	cd /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adamj/Documents/QtProjects/CodeWizard /home/adamj/Documents/QtProjects/CodeWizard/extern/tree-sitter /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter /home/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2-Release/extern/tree-sitter/CMakeFiles/tree-sitter.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : extern/tree-sitter/CMakeFiles/tree-sitter.dir/depend

