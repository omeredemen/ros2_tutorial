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
CMAKE_SOURCE_DIR = /home/omer/Desktop/dev_ws/src/sbus_demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/omer/Desktop/dev_ws/build/sbus_demo

# Include any dependencies generated for this target.
include CMakeFiles/sbus_demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sbus_demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sbus_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sbus_demo.dir/flags.make

CMakeFiles/sbus_demo.dir/src/sbus.cpp.o: CMakeFiles/sbus_demo.dir/flags.make
CMakeFiles/sbus_demo.dir/src/sbus.cpp.o: /home/omer/Desktop/dev_ws/src/sbus_demo/src/sbus.cpp
CMakeFiles/sbus_demo.dir/src/sbus.cpp.o: CMakeFiles/sbus_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/omer/Desktop/dev_ws/build/sbus_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sbus_demo.dir/src/sbus.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sbus_demo.dir/src/sbus.cpp.o -MF CMakeFiles/sbus_demo.dir/src/sbus.cpp.o.d -o CMakeFiles/sbus_demo.dir/src/sbus.cpp.o -c /home/omer/Desktop/dev_ws/src/sbus_demo/src/sbus.cpp

CMakeFiles/sbus_demo.dir/src/sbus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sbus_demo.dir/src/sbus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/omer/Desktop/dev_ws/src/sbus_demo/src/sbus.cpp > CMakeFiles/sbus_demo.dir/src/sbus.cpp.i

CMakeFiles/sbus_demo.dir/src/sbus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sbus_demo.dir/src/sbus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/omer/Desktop/dev_ws/src/sbus_demo/src/sbus.cpp -o CMakeFiles/sbus_demo.dir/src/sbus.cpp.s

# Object files for target sbus_demo
sbus_demo_OBJECTS = \
"CMakeFiles/sbus_demo.dir/src/sbus.cpp.o"

# External object files for target sbus_demo
sbus_demo_EXTERNAL_OBJECTS =

sbus_demo: CMakeFiles/sbus_demo.dir/src/sbus.cpp.o
sbus_demo: CMakeFiles/sbus_demo.dir/build.make
sbus_demo: /opt/ros/humble/lib/librclcpp.so
sbus_demo: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_c.so
sbus_demo: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_cpp.so
sbus_demo: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
sbus_demo: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
sbus_demo: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_cpp.so
sbus_demo: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_py.so
sbus_demo: /opt/ros/humble/lib/liblibstatistics_collector.so
sbus_demo: /opt/ros/humble/lib/librcl.so
sbus_demo: /opt/ros/humble/lib/librmw_implementation.so
sbus_demo: /opt/ros/humble/lib/libament_index_cpp.so
sbus_demo: /opt/ros/humble/lib/librcl_logging_spdlog.so
sbus_demo: /opt/ros/humble/lib/librcl_logging_interface.so
sbus_demo: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_c.so
sbus_demo: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
sbus_demo: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_cpp.so
sbus_demo: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
sbus_demo: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_cpp.so
sbus_demo: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_py.so
sbus_demo: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_c.so
sbus_demo: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_c.so
sbus_demo: /opt/ros/humble/lib/librcl_yaml_param_parser.so
sbus_demo: /opt/ros/humble/lib/libyaml.so
sbus_demo: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_c.so
sbus_demo: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_cpp.so
sbus_demo: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
sbus_demo: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
sbus_demo: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
sbus_demo: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_py.so
sbus_demo: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_c.so
sbus_demo: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_c.so
sbus_demo: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_c.so
sbus_demo: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_cpp.so
sbus_demo: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
sbus_demo: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
sbus_demo: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
sbus_demo: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_py.so
sbus_demo: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_c.so
sbus_demo: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_c.so
sbus_demo: /opt/ros/humble/lib/libtracetools.so
sbus_demo: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_c.so
sbus_demo: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_c.so
sbus_demo: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_cpp.so
sbus_demo: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_cpp.so
sbus_demo: /opt/ros/humble/lib/libfastcdr.so.1.0.24
sbus_demo: /opt/ros/humble/lib/librmw.so
sbus_demo: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
sbus_demo: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
sbus_demo: /opt/ros/humble/lib/librosidl_typesupport_introspection_cpp.so
sbus_demo: /opt/ros/humble/lib/librosidl_typesupport_introspection_c.so
sbus_demo: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
sbus_demo: /opt/ros/humble/lib/librosidl_typesupport_cpp.so
sbus_demo: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_c.so
sbus_demo: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_c.so
sbus_demo: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_py.so
sbus_demo: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
sbus_demo: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_c.so
sbus_demo: /opt/ros/humble/lib/librosidl_typesupport_c.so
sbus_demo: /opt/ros/humble/lib/librcpputils.so
sbus_demo: /opt/ros/humble/lib/librosidl_runtime_c.so
sbus_demo: /opt/ros/humble/lib/librcutils.so
sbus_demo: /usr/lib/x86_64-linux-gnu/libpython3.10.so
sbus_demo: CMakeFiles/sbus_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/omer/Desktop/dev_ws/build/sbus_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sbus_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sbus_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sbus_demo.dir/build: sbus_demo
.PHONY : CMakeFiles/sbus_demo.dir/build

CMakeFiles/sbus_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sbus_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sbus_demo.dir/clean

CMakeFiles/sbus_demo.dir/depend:
	cd /home/omer/Desktop/dev_ws/build/sbus_demo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/omer/Desktop/dev_ws/src/sbus_demo /home/omer/Desktop/dev_ws/src/sbus_demo /home/omer/Desktop/dev_ws/build/sbus_demo /home/omer/Desktop/dev_ws/build/sbus_demo /home/omer/Desktop/dev_ws/build/sbus_demo/CMakeFiles/sbus_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sbus_demo.dir/depend
