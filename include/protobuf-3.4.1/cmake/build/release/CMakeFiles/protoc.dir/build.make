# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake\build\release

# Include any dependencies generated for this target.
include CMakeFiles\protoc.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\protoc.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\protoc.dir\flags.make

CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj: CMakeFiles\protoc.dir\flags.make
CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj: D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake\build\release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/protoc.dir/D_/Libraries/workspace/cpp-asteroids/include/protobuf-3.4.1/src/google/protobuf/compiler/main.cc.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\amd64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj /FdCMakeFiles\protoc.dir\ /FS -c D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc
<<

CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/protoc.dir/D_/Libraries/workspace/cpp-asteroids/include/protobuf-3.4.1/src/google/protobuf/compiler/main.cc.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\amd64\cl.exe > CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc
<<

CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/protoc.dir/D_/Libraries/workspace/cpp-asteroids/include/protobuf-3.4.1/src/google/protobuf/compiler/main.cc.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\amd64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.s /c D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc
<<

CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj.requires:

.PHONY : CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj.requires

CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj.provides: CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj.requires
	$(MAKE) -f CMakeFiles\protoc.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj.provides.build
.PHONY : CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj.provides

CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj.provides.build: CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj


# Object files for target protoc
protoc_OBJECTS = \
"CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj"

# External object files for target protoc
protoc_EXTERNAL_OBJECTS =

protoc.exe: CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj
protoc.exe: CMakeFiles\protoc.dir\build.make
protoc.exe: libprotobuf.lib
protoc.exe: libprotoc.lib
protoc.exe: libprotobuf.lib
protoc.exe: CMakeFiles\protoc.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake\build\release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable protoc.exe"
	"C:\Program Files\CMake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\protoc.dir --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\amd64\link.exe /nologo @CMakeFiles\protoc.dir\objects1.rsp @<<
 /out:protoc.exe /implib:protoc.lib /pdb:D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake\build\release\protoc.pdb /version:0.0  /machine:x64 /INCREMENTAL:NO /subsystem:console libprotobuf.lib libprotoc.lib libprotobuf.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\protoc.dir\build: protoc.exe

.PHONY : CMakeFiles\protoc.dir\build

CMakeFiles\protoc.dir\requires: CMakeFiles\protoc.dir\D_\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\src\google\protobuf\compiler\main.cc.obj.requires

.PHONY : CMakeFiles\protoc.dir\requires

CMakeFiles\protoc.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\protoc.dir\cmake_clean.cmake
.PHONY : CMakeFiles\protoc.dir\clean

CMakeFiles\protoc.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake\build\release D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake\build\release D:\Libraries\workspace\cpp-asteroids\include\protobuf-3.4.1\cmake\build\release\CMakeFiles\protoc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\protoc.dir\depend

