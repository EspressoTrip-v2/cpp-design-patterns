# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Section_5_ProtoType.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Section_5_ProtoType.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Section_5_ProtoType.dir\flags.make

CMakeFiles\Section_5_ProtoType.dir\main.cpp.obj: CMakeFiles\Section_5_ProtoType.dir\flags.make
CMakeFiles\Section_5_ProtoType.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Section_5_ProtoType.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Section_5_ProtoType.dir\main.cpp.obj /FdCMakeFiles\Section_5_ProtoType.dir\ /FS -c "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\main.cpp"
<<

CMakeFiles\Section_5_ProtoType.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Section_5_ProtoType.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Section_5_ProtoType.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\main.cpp"
<<

CMakeFiles\Section_5_ProtoType.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Section_5_ProtoType.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Section_5_ProtoType.dir\main.cpp.s /c "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\main.cpp"
<<

# Object files for target Section_5_ProtoType
Section_5_ProtoType_OBJECTS = \
"CMakeFiles\Section_5_ProtoType.dir\main.cpp.obj"

# External object files for target Section_5_ProtoType
Section_5_ProtoType_EXTERNAL_OBJECTS =

Section_5_ProtoType.exe: CMakeFiles\Section_5_ProtoType.dir\main.cpp.obj
Section_5_ProtoType.exe: CMakeFiles\Section_5_ProtoType.dir\build.make
Section_5_ProtoType.exe: CMakeFiles\Section_5_ProtoType.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Section_5_ProtoType.exe"
	"C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Section_5_ProtoType.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Section_5_ProtoType.dir\objects1.rsp @<<
 /out:Section_5_ProtoType.exe /implib:Section_5_ProtoType.lib /pdb:"B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\cmake-build-debug\Section_5_ProtoType.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Section_5_ProtoType.dir\build: Section_5_ProtoType.exe

.PHONY : CMakeFiles\Section_5_ProtoType.dir\build

CMakeFiles\Section_5_ProtoType.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Section_5_ProtoType.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Section_5_ProtoType.dir\clean

CMakeFiles\Section_5_ProtoType.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType" "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType" "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\cmake-build-debug" "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\cmake-build-debug" "B:\Coding Languages\C++\Standard C++\Design Patterns C++\DP Code\Section 5 ProtoType\cmake-build-debug\CMakeFiles\Section_5_ProtoType.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Section_5_ProtoType.dir\depend
