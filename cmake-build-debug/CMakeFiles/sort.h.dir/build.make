# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/erastusmurungi/Documents/GitHub/c-sorts

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sort.h.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sort.h.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort.h.dir/flags.make

CMakeFiles/sort.h.dir/bubblesort.c.o: CMakeFiles/sort.h.dir/flags.make
CMakeFiles/sort.h.dir/bubblesort.c.o: ../bubblesort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sort.h.dir/bubblesort.c.o"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.h.dir/bubblesort.c.o   -c /Users/erastusmurungi/Documents/GitHub/c-sorts/bubblesort.c

CMakeFiles/sort.h.dir/bubblesort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.h.dir/bubblesort.c.i"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/erastusmurungi/Documents/GitHub/c-sorts/bubblesort.c > CMakeFiles/sort.h.dir/bubblesort.c.i

CMakeFiles/sort.h.dir/bubblesort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.h.dir/bubblesort.c.s"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/erastusmurungi/Documents/GitHub/c-sorts/bubblesort.c -o CMakeFiles/sort.h.dir/bubblesort.c.s

CMakeFiles/sort.h.dir/main.c.o: CMakeFiles/sort.h.dir/flags.make
CMakeFiles/sort.h.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sort.h.dir/main.c.o"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.h.dir/main.c.o   -c /Users/erastusmurungi/Documents/GitHub/c-sorts/main.c

CMakeFiles/sort.h.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.h.dir/main.c.i"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/erastusmurungi/Documents/GitHub/c-sorts/main.c > CMakeFiles/sort.h.dir/main.c.i

CMakeFiles/sort.h.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.h.dir/main.c.s"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/erastusmurungi/Documents/GitHub/c-sorts/main.c -o CMakeFiles/sort.h.dir/main.c.s

CMakeFiles/sort.h.dir/quicksort.c.o: CMakeFiles/sort.h.dir/flags.make
CMakeFiles/sort.h.dir/quicksort.c.o: ../quicksort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/sort.h.dir/quicksort.c.o"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.h.dir/quicksort.c.o   -c /Users/erastusmurungi/Documents/GitHub/c-sorts/quicksort.c

CMakeFiles/sort.h.dir/quicksort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.h.dir/quicksort.c.i"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/erastusmurungi/Documents/GitHub/c-sorts/quicksort.c > CMakeFiles/sort.h.dir/quicksort.c.i

CMakeFiles/sort.h.dir/quicksort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.h.dir/quicksort.c.s"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/erastusmurungi/Documents/GitHub/c-sorts/quicksort.c -o CMakeFiles/sort.h.dir/quicksort.c.s

CMakeFiles/sort.h.dir/insertionsort.c.o: CMakeFiles/sort.h.dir/flags.make
CMakeFiles/sort.h.dir/insertionsort.c.o: ../insertionsort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/sort.h.dir/insertionsort.c.o"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.h.dir/insertionsort.c.o   -c /Users/erastusmurungi/Documents/GitHub/c-sorts/insertionsort.c

CMakeFiles/sort.h.dir/insertionsort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.h.dir/insertionsort.c.i"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/erastusmurungi/Documents/GitHub/c-sorts/insertionsort.c > CMakeFiles/sort.h.dir/insertionsort.c.i

CMakeFiles/sort.h.dir/insertionsort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.h.dir/insertionsort.c.s"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/erastusmurungi/Documents/GitHub/c-sorts/insertionsort.c -o CMakeFiles/sort.h.dir/insertionsort.c.s

CMakeFiles/sort.h.dir/mergesort.c.o: CMakeFiles/sort.h.dir/flags.make
CMakeFiles/sort.h.dir/mergesort.c.o: ../mergesort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/sort.h.dir/mergesort.c.o"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.h.dir/mergesort.c.o   -c /Users/erastusmurungi/Documents/GitHub/c-sorts/mergesort.c

CMakeFiles/sort.h.dir/mergesort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.h.dir/mergesort.c.i"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/erastusmurungi/Documents/GitHub/c-sorts/mergesort.c > CMakeFiles/sort.h.dir/mergesort.c.i

CMakeFiles/sort.h.dir/mergesort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.h.dir/mergesort.c.s"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/erastusmurungi/Documents/GitHub/c-sorts/mergesort.c -o CMakeFiles/sort.h.dir/mergesort.c.s

CMakeFiles/sort.h.dir/selectionsort.c.o: CMakeFiles/sort.h.dir/flags.make
CMakeFiles/sort.h.dir/selectionsort.c.o: ../selectionsort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/sort.h.dir/selectionsort.c.o"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.h.dir/selectionsort.c.o   -c /Users/erastusmurungi/Documents/GitHub/c-sorts/selectionsort.c

CMakeFiles/sort.h.dir/selectionsort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.h.dir/selectionsort.c.i"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/erastusmurungi/Documents/GitHub/c-sorts/selectionsort.c > CMakeFiles/sort.h.dir/selectionsort.c.i

CMakeFiles/sort.h.dir/selectionsort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.h.dir/selectionsort.c.s"
	/usr/local/Cellar/llvm/9.0.1/bin/clang-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/erastusmurungi/Documents/GitHub/c-sorts/selectionsort.c -o CMakeFiles/sort.h.dir/selectionsort.c.s

# Object files for target sort.h
sort_h_OBJECTS = \
"CMakeFiles/sort.h.dir/bubblesort.c.o" \
"CMakeFiles/sort.h.dir/main.c.o" \
"CMakeFiles/sort.h.dir/quicksort.c.o" \
"CMakeFiles/sort.h.dir/insertionsort.c.o" \
"CMakeFiles/sort.h.dir/mergesort.c.o" \
"CMakeFiles/sort.h.dir/selectionsort.c.o"

# External object files for target sort.h
sort_h_EXTERNAL_OBJECTS =

sort.h: CMakeFiles/sort.h.dir/bubblesort.c.o
sort.h: CMakeFiles/sort.h.dir/main.c.o
sort.h: CMakeFiles/sort.h.dir/quicksort.c.o
sort.h: CMakeFiles/sort.h.dir/insertionsort.c.o
sort.h: CMakeFiles/sort.h.dir/mergesort.c.o
sort.h: CMakeFiles/sort.h.dir/selectionsort.c.o
sort.h: CMakeFiles/sort.h.dir/build.make
sort.h: CMakeFiles/sort.h.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable sort.h"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sort.h.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort.h.dir/build: sort.h

.PHONY : CMakeFiles/sort.h.dir/build

CMakeFiles/sort.h.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sort.h.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sort.h.dir/clean

CMakeFiles/sort.h.dir/depend:
	cd /Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/erastusmurungi/Documents/GitHub/c-sorts /Users/erastusmurungi/Documents/GitHub/c-sorts /Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug /Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug /Users/erastusmurungi/Documents/GitHub/c-sorts/cmake-build-debug/CMakeFiles/sort.h.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sort.h.dir/depend
