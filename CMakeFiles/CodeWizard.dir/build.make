# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/adamj/QtProjects/CodeWizard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adamj/QtProjects/CodeWizard

# Include any dependencies generated for this target.
include CMakeFiles/CodeWizard.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CodeWizard.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CodeWizard.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CodeWizard.dir/flags.make

CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.o: CMakeFiles/CodeWizard.dir/flags.make
CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.o: CodeWizard_autogen/mocs_compilation.cpp
CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.o: CMakeFiles/CodeWizard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamj/QtProjects/CodeWizard/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.o -MF CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.o -c /home/adamj/QtProjects/CodeWizard/CodeWizard_autogen/mocs_compilation.cpp

CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/QtProjects/CodeWizard/CodeWizard_autogen/mocs_compilation.cpp > CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.i

CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/QtProjects/CodeWizard/CodeWizard_autogen/mocs_compilation.cpp -o CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.s

CMakeFiles/CodeWizard.dir/main.cpp.o: CMakeFiles/CodeWizard.dir/flags.make
CMakeFiles/CodeWizard.dir/main.cpp.o: main.cpp
CMakeFiles/CodeWizard.dir/main.cpp.o: CMakeFiles/CodeWizard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamj/QtProjects/CodeWizard/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CodeWizard.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeWizard.dir/main.cpp.o -MF CMakeFiles/CodeWizard.dir/main.cpp.o.d -o CMakeFiles/CodeWizard.dir/main.cpp.o -c /home/adamj/QtProjects/CodeWizard/main.cpp

CMakeFiles/CodeWizard.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeWizard.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/QtProjects/CodeWizard/main.cpp > CMakeFiles/CodeWizard.dir/main.cpp.i

CMakeFiles/CodeWizard.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeWizard.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/QtProjects/CodeWizard/main.cpp -o CMakeFiles/CodeWizard.dir/main.cpp.s

CMakeFiles/CodeWizard.dir/mainwindow.cpp.o: CMakeFiles/CodeWizard.dir/flags.make
CMakeFiles/CodeWizard.dir/mainwindow.cpp.o: mainwindow.cpp
CMakeFiles/CodeWizard.dir/mainwindow.cpp.o: CMakeFiles/CodeWizard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamj/QtProjects/CodeWizard/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CodeWizard.dir/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeWizard.dir/mainwindow.cpp.o -MF CMakeFiles/CodeWizard.dir/mainwindow.cpp.o.d -o CMakeFiles/CodeWizard.dir/mainwindow.cpp.o -c /home/adamj/QtProjects/CodeWizard/mainwindow.cpp

CMakeFiles/CodeWizard.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeWizard.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/QtProjects/CodeWizard/mainwindow.cpp > CMakeFiles/CodeWizard.dir/mainwindow.cpp.i

CMakeFiles/CodeWizard.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeWizard.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/QtProjects/CodeWizard/mainwindow.cpp -o CMakeFiles/CodeWizard.dir/mainwindow.cpp.s

CMakeFiles/CodeWizard.dir/mytextedit.cpp.o: CMakeFiles/CodeWizard.dir/flags.make
CMakeFiles/CodeWizard.dir/mytextedit.cpp.o: mytextedit.cpp
CMakeFiles/CodeWizard.dir/mytextedit.cpp.o: CMakeFiles/CodeWizard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamj/QtProjects/CodeWizard/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CodeWizard.dir/mytextedit.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeWizard.dir/mytextedit.cpp.o -MF CMakeFiles/CodeWizard.dir/mytextedit.cpp.o.d -o CMakeFiles/CodeWizard.dir/mytextedit.cpp.o -c /home/adamj/QtProjects/CodeWizard/mytextedit.cpp

CMakeFiles/CodeWizard.dir/mytextedit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeWizard.dir/mytextedit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/QtProjects/CodeWizard/mytextedit.cpp > CMakeFiles/CodeWizard.dir/mytextedit.cpp.i

CMakeFiles/CodeWizard.dir/mytextedit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeWizard.dir/mytextedit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/QtProjects/CodeWizard/mytextedit.cpp -o CMakeFiles/CodeWizard.dir/mytextedit.cpp.s

CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.o: CMakeFiles/CodeWizard.dir/flags.make
CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.o: syntaxhighlighter.cpp
CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.o: CMakeFiles/CodeWizard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamj/QtProjects/CodeWizard/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.o -MF CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.o.d -o CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.o -c /home/adamj/QtProjects/CodeWizard/syntaxhighlighter.cpp

CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/QtProjects/CodeWizard/syntaxhighlighter.cpp > CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.i

CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/QtProjects/CodeWizard/syntaxhighlighter.cpp -o CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.s

CMakeFiles/CodeWizard.dir/language.cpp.o: CMakeFiles/CodeWizard.dir/flags.make
CMakeFiles/CodeWizard.dir/language.cpp.o: language.cpp
CMakeFiles/CodeWizard.dir/language.cpp.o: CMakeFiles/CodeWizard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamj/QtProjects/CodeWizard/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CodeWizard.dir/language.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeWizard.dir/language.cpp.o -MF CMakeFiles/CodeWizard.dir/language.cpp.o.d -o CMakeFiles/CodeWizard.dir/language.cpp.o -c /home/adamj/QtProjects/CodeWizard/language.cpp

CMakeFiles/CodeWizard.dir/language.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeWizard.dir/language.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/QtProjects/CodeWizard/language.cpp > CMakeFiles/CodeWizard.dir/language.cpp.i

CMakeFiles/CodeWizard.dir/language.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeWizard.dir/language.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/QtProjects/CodeWizard/language.cpp -o CMakeFiles/CodeWizard.dir/language.cpp.s

CMakeFiles/CodeWizard.dir/languageserverclient.cpp.o: CMakeFiles/CodeWizard.dir/flags.make
CMakeFiles/CodeWizard.dir/languageserverclient.cpp.o: languageserverclient.cpp
CMakeFiles/CodeWizard.dir/languageserverclient.cpp.o: CMakeFiles/CodeWizard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamj/QtProjects/CodeWizard/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CodeWizard.dir/languageserverclient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeWizard.dir/languageserverclient.cpp.o -MF CMakeFiles/CodeWizard.dir/languageserverclient.cpp.o.d -o CMakeFiles/CodeWizard.dir/languageserverclient.cpp.o -c /home/adamj/QtProjects/CodeWizard/languageserverclient.cpp

CMakeFiles/CodeWizard.dir/languageserverclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeWizard.dir/languageserverclient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/QtProjects/CodeWizard/languageserverclient.cpp > CMakeFiles/CodeWizard.dir/languageserverclient.cpp.i

CMakeFiles/CodeWizard.dir/languageserverclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeWizard.dir/languageserverclient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/QtProjects/CodeWizard/languageserverclient.cpp -o CMakeFiles/CodeWizard.dir/languageserverclient.cpp.s

CMakeFiles/CodeWizard.dir/recordinglight.cpp.o: CMakeFiles/CodeWizard.dir/flags.make
CMakeFiles/CodeWizard.dir/recordinglight.cpp.o: recordinglight.cpp
CMakeFiles/CodeWizard.dir/recordinglight.cpp.o: CMakeFiles/CodeWizard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamj/QtProjects/CodeWizard/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CodeWizard.dir/recordinglight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeWizard.dir/recordinglight.cpp.o -MF CMakeFiles/CodeWizard.dir/recordinglight.cpp.o.d -o CMakeFiles/CodeWizard.dir/recordinglight.cpp.o -c /home/adamj/QtProjects/CodeWizard/recordinglight.cpp

CMakeFiles/CodeWizard.dir/recordinglight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeWizard.dir/recordinglight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamj/QtProjects/CodeWizard/recordinglight.cpp > CMakeFiles/CodeWizard.dir/recordinglight.cpp.i

CMakeFiles/CodeWizard.dir/recordinglight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeWizard.dir/recordinglight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamj/QtProjects/CodeWizard/recordinglight.cpp -o CMakeFiles/CodeWizard.dir/recordinglight.cpp.s

# Object files for target CodeWizard
CodeWizard_OBJECTS = \
"CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/CodeWizard.dir/main.cpp.o" \
"CMakeFiles/CodeWizard.dir/mainwindow.cpp.o" \
"CMakeFiles/CodeWizard.dir/mytextedit.cpp.o" \
"CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.o" \
"CMakeFiles/CodeWizard.dir/language.cpp.o" \
"CMakeFiles/CodeWizard.dir/languageserverclient.cpp.o" \
"CMakeFiles/CodeWizard.dir/recordinglight.cpp.o"

# External object files for target CodeWizard
CodeWizard_EXTERNAL_OBJECTS = \
"/home/adamj/QtProjects/CodeWizard/app.o"

CodeWizard: CMakeFiles/CodeWizard.dir/CodeWizard_autogen/mocs_compilation.cpp.o
CodeWizard: CMakeFiles/CodeWizard.dir/main.cpp.o
CodeWizard: CMakeFiles/CodeWizard.dir/mainwindow.cpp.o
CodeWizard: CMakeFiles/CodeWizard.dir/mytextedit.cpp.o
CodeWizard: CMakeFiles/CodeWizard.dir/syntaxhighlighter.cpp.o
CodeWizard: CMakeFiles/CodeWizard.dir/language.cpp.o
CodeWizard: CMakeFiles/CodeWizard.dir/languageserverclient.cpp.o
CodeWizard: CMakeFiles/CodeWizard.dir/recordinglight.cpp.o
CodeWizard: app.o
CodeWizard: CMakeFiles/CodeWizard.dir/build.make
CodeWizard: extern/tree-sitter/libtree-sitter.a
CodeWizard: libtree-sitter-cpp.a
CodeWizard: libtree-sitter-python.a
CodeWizard: libtree-sitter-rust.a
CodeWizard: libtree-sitter-javascript.a
CodeWizard: libtree-sitter-typescript.a
CodeWizard: libtree-sitter-html.a
CodeWizard: libtree-sitter-lua.a
CodeWizard: libtree-sitter-glsl.a
CodeWizard: libtree-sitter-wgsl.a
CodeWizard: libtree-sitter-java.a
CodeWizard: libtree-sitter-go.a
CodeWizard: libtree-sitter-c.a
CodeWizard: libtree-sitter-c-sharp.a
CodeWizard: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
CodeWizard: /usr/lib/x86_64-linux-gnu/libQt6Core.so.6.2.4
CodeWizard: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
CodeWizard: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
CodeWizard: CMakeFiles/CodeWizard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adamj/QtProjects/CodeWizard/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable CodeWizard"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CodeWizard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CodeWizard.dir/build: CodeWizard
.PHONY : CMakeFiles/CodeWizard.dir/build

CMakeFiles/CodeWizard.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CodeWizard.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CodeWizard.dir/clean

CMakeFiles/CodeWizard.dir/depend:
	cd /home/adamj/QtProjects/CodeWizard && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adamj/QtProjects/CodeWizard /home/adamj/QtProjects/CodeWizard /home/adamj/QtProjects/CodeWizard /home/adamj/QtProjects/CodeWizard /home/adamj/QtProjects/CodeWizard/CMakeFiles/CodeWizard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CodeWizard.dir/depend

