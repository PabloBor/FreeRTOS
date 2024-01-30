To compile using CMake you must execute the following 
command inside the build folder:

mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../gcc-arm-none-eabi.cmake ..

By default it is compiled in "release" mode, if you want
to change the mode configure the variable CMAKE_BUILD_TYPE 
within CMakeLists.txt

The commands have to be executed at the build folder level.

CMake contains the following commands:

"make" to compile the code
"clean" to delete the .elf file
"flash" to load the code onto the board
"erase" to delete the code from the board
