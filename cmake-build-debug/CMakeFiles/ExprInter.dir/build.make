# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/josephcriseno/Desktop/Project3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/josephcriseno/Desktop/Project3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ExprInter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ExprInter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ExprInter.dir/flags.make

CMakeFiles/ExprInter.dir/main.cpp.o: CMakeFiles/ExprInter.dir/flags.make
CMakeFiles/ExprInter.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ExprInter.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExprInter.dir/main.cpp.o -c /Users/josephcriseno/Desktop/Project3/main.cpp

CMakeFiles/ExprInter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josephcriseno/Desktop/Project3/main.cpp > CMakeFiles/ExprInter.dir/main.cpp.i

CMakeFiles/ExprInter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josephcriseno/Desktop/Project3/main.cpp -o CMakeFiles/ExprInter.dir/main.cpp.s

CMakeFiles/ExprInter.dir/Token.cpp.o: CMakeFiles/ExprInter.dir/flags.make
CMakeFiles/ExprInter.dir/Token.cpp.o: ../Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ExprInter.dir/Token.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExprInter.dir/Token.cpp.o -c /Users/josephcriseno/Desktop/Project3/Token.cpp

CMakeFiles/ExprInter.dir/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Token.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josephcriseno/Desktop/Project3/Token.cpp > CMakeFiles/ExprInter.dir/Token.cpp.i

CMakeFiles/ExprInter.dir/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Token.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josephcriseno/Desktop/Project3/Token.cpp -o CMakeFiles/ExprInter.dir/Token.cpp.s

CMakeFiles/ExprInter.dir/Tokenizer.cpp.o: CMakeFiles/ExprInter.dir/flags.make
CMakeFiles/ExprInter.dir/Tokenizer.cpp.o: ../Tokenizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ExprInter.dir/Tokenizer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExprInter.dir/Tokenizer.cpp.o -c /Users/josephcriseno/Desktop/Project3/Tokenizer.cpp

CMakeFiles/ExprInter.dir/Tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Tokenizer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josephcriseno/Desktop/Project3/Tokenizer.cpp > CMakeFiles/ExprInter.dir/Tokenizer.cpp.i

CMakeFiles/ExprInter.dir/Tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Tokenizer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josephcriseno/Desktop/Project3/Tokenizer.cpp -o CMakeFiles/ExprInter.dir/Tokenizer.cpp.s

CMakeFiles/ExprInter.dir/Parser.cpp.o: CMakeFiles/ExprInter.dir/flags.make
CMakeFiles/ExprInter.dir/Parser.cpp.o: ../Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ExprInter.dir/Parser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExprInter.dir/Parser.cpp.o -c /Users/josephcriseno/Desktop/Project3/Parser.cpp

CMakeFiles/ExprInter.dir/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Parser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josephcriseno/Desktop/Project3/Parser.cpp > CMakeFiles/ExprInter.dir/Parser.cpp.i

CMakeFiles/ExprInter.dir/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Parser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josephcriseno/Desktop/Project3/Parser.cpp -o CMakeFiles/ExprInter.dir/Parser.cpp.s

CMakeFiles/ExprInter.dir/ArithExpr.cpp.o: CMakeFiles/ExprInter.dir/flags.make
CMakeFiles/ExprInter.dir/ArithExpr.cpp.o: ../ArithExpr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ExprInter.dir/ArithExpr.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExprInter.dir/ArithExpr.cpp.o -c /Users/josephcriseno/Desktop/Project3/ArithExpr.cpp

CMakeFiles/ExprInter.dir/ArithExpr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/ArithExpr.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josephcriseno/Desktop/Project3/ArithExpr.cpp > CMakeFiles/ExprInter.dir/ArithExpr.cpp.i

CMakeFiles/ExprInter.dir/ArithExpr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/ArithExpr.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josephcriseno/Desktop/Project3/ArithExpr.cpp -o CMakeFiles/ExprInter.dir/ArithExpr.cpp.s

CMakeFiles/ExprInter.dir/SymTab.cpp.o: CMakeFiles/ExprInter.dir/flags.make
CMakeFiles/ExprInter.dir/SymTab.cpp.o: ../SymTab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ExprInter.dir/SymTab.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExprInter.dir/SymTab.cpp.o -c /Users/josephcriseno/Desktop/Project3/SymTab.cpp

CMakeFiles/ExprInter.dir/SymTab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/SymTab.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josephcriseno/Desktop/Project3/SymTab.cpp > CMakeFiles/ExprInter.dir/SymTab.cpp.i

CMakeFiles/ExprInter.dir/SymTab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/SymTab.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josephcriseno/Desktop/Project3/SymTab.cpp -o CMakeFiles/ExprInter.dir/SymTab.cpp.s

CMakeFiles/ExprInter.dir/Statements.cpp.o: CMakeFiles/ExprInter.dir/flags.make
CMakeFiles/ExprInter.dir/Statements.cpp.o: ../Statements.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ExprInter.dir/Statements.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExprInter.dir/Statements.cpp.o -c /Users/josephcriseno/Desktop/Project3/Statements.cpp

CMakeFiles/ExprInter.dir/Statements.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Statements.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josephcriseno/Desktop/Project3/Statements.cpp > CMakeFiles/ExprInter.dir/Statements.cpp.i

CMakeFiles/ExprInter.dir/Statements.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Statements.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josephcriseno/Desktop/Project3/Statements.cpp -o CMakeFiles/ExprInter.dir/Statements.cpp.s

CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.o: CMakeFiles/ExprInter.dir/flags.make
CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.o: ../TypeDescriptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.o -c /Users/josephcriseno/Desktop/Project3/TypeDescriptor.cpp

CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josephcriseno/Desktop/Project3/TypeDescriptor.cpp > CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.i

CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josephcriseno/Desktop/Project3/TypeDescriptor.cpp -o CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.s

CMakeFiles/ExprInter.dir/Functions.cpp.o: CMakeFiles/ExprInter.dir/flags.make
CMakeFiles/ExprInter.dir/Functions.cpp.o: ../Functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ExprInter.dir/Functions.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ExprInter.dir/Functions.cpp.o -c /Users/josephcriseno/Desktop/Project3/Functions.cpp

CMakeFiles/ExprInter.dir/Functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Functions.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josephcriseno/Desktop/Project3/Functions.cpp > CMakeFiles/ExprInter.dir/Functions.cpp.i

CMakeFiles/ExprInter.dir/Functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Functions.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josephcriseno/Desktop/Project3/Functions.cpp -o CMakeFiles/ExprInter.dir/Functions.cpp.s

# Object files for target ExprInter
ExprInter_OBJECTS = \
"CMakeFiles/ExprInter.dir/main.cpp.o" \
"CMakeFiles/ExprInter.dir/Token.cpp.o" \
"CMakeFiles/ExprInter.dir/Tokenizer.cpp.o" \
"CMakeFiles/ExprInter.dir/Parser.cpp.o" \
"CMakeFiles/ExprInter.dir/ArithExpr.cpp.o" \
"CMakeFiles/ExprInter.dir/SymTab.cpp.o" \
"CMakeFiles/ExprInter.dir/Statements.cpp.o" \
"CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.o" \
"CMakeFiles/ExprInter.dir/Functions.cpp.o"

# External object files for target ExprInter
ExprInter_EXTERNAL_OBJECTS =

ExprInter: CMakeFiles/ExprInter.dir/main.cpp.o
ExprInter: CMakeFiles/ExprInter.dir/Token.cpp.o
ExprInter: CMakeFiles/ExprInter.dir/Tokenizer.cpp.o
ExprInter: CMakeFiles/ExprInter.dir/Parser.cpp.o
ExprInter: CMakeFiles/ExprInter.dir/ArithExpr.cpp.o
ExprInter: CMakeFiles/ExprInter.dir/SymTab.cpp.o
ExprInter: CMakeFiles/ExprInter.dir/Statements.cpp.o
ExprInter: CMakeFiles/ExprInter.dir/TypeDescriptor.cpp.o
ExprInter: CMakeFiles/ExprInter.dir/Functions.cpp.o
ExprInter: CMakeFiles/ExprInter.dir/build.make
ExprInter: CMakeFiles/ExprInter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ExprInter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ExprInter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ExprInter.dir/build: ExprInter

.PHONY : CMakeFiles/ExprInter.dir/build

CMakeFiles/ExprInter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExprInter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExprInter.dir/clean

CMakeFiles/ExprInter.dir/depend:
	cd /Users/josephcriseno/Desktop/Project3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/josephcriseno/Desktop/Project3 /Users/josephcriseno/Desktop/Project3 /Users/josephcriseno/Desktop/Project3/cmake-build-debug /Users/josephcriseno/Desktop/Project3/cmake-build-debug /Users/josephcriseno/Desktop/Project3/cmake-build-debug/CMakeFiles/ExprInter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ExprInter.dir/depend

