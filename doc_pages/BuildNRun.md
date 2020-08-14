
@page subsystem1 CMake Instructions

@section subsystemsection1 Cmake Setup
### Debug Build
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - MinGW Makefiles" LinkedList/

### Release Build
cmake -DCMAKE_BUILD_TYPE=Release -G "CodeBlocks - MinGW Makefiles" LinkedList/

@section subsystemsection2 Build Targets/Executables

### Debug Build
cmake --build LinkedList/cmake-build-debug --target all -- -j 9

### Release Build
cmake --build LinkedList/cmake-build-release --target all -- -j 9

@section subsystemsection3 Run Targets/Executables
Run the tasks from out/ directory in your command line
