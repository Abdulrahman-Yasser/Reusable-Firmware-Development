# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/abdu/Study/Reusable-Firmware-Development/1_GeneralPurbose_IO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abdu/Study/Reusable-Firmware-Development/build

# Utility rule file for application.bin.

# Include any custom commands dependencies for this target.
include CMakeFiles/application.bin.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/application.bin.dir/progress.make

CMakeFiles/application.bin: application.axf

application.bin: CMakeFiles/application.bin
application.bin: CMakeFiles/application.bin.dir/build.make
	/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-objcopy -O binary application.axf application.bin
.PHONY : application.bin

# Rule to build all files generated by this target.
CMakeFiles/application.bin.dir/build: application.bin
.PHONY : CMakeFiles/application.bin.dir/build

CMakeFiles/application.bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/application.bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/application.bin.dir/clean

CMakeFiles/application.bin.dir/depend:
	cd /home/abdu/Study/Reusable-Firmware-Development/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abdu/Study/Reusable-Firmware-Development/1_GeneralPurbose_IO /home/abdu/Study/Reusable-Firmware-Development/1_GeneralPurbose_IO /home/abdu/Study/Reusable-Firmware-Development/build /home/abdu/Study/Reusable-Firmware-Development/build /home/abdu/Study/Reusable-Firmware-Development/build/CMakeFiles/application.bin.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/application.bin.dir/depend

