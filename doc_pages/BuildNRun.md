
## CMake Setup

### Debug Build
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - MinGW Makefiles" LinkedList/

### Release Build
cmake -DCMAKE_BUILD_TYPE=Release -G "CodeBlocks - MinGW Makefiles" LinkedList/

## Build All Targets

### Debug Build
cmake --build LinkedList/cmake-build-debug --target all -- -j 9

### Release Build
cmake --build LinkedList/cmake-build-release --target all -- -j 9

## Run the tasks
Run the tasks from out/ directory in your command line
