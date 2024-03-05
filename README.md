# LAB 4: Dynamic Arrays
_A simple implementation of dynamic arrays written in c++20._
***

**DCS-229A**: Data Structures and Algorithms
\
Aru Poleo Vargas

***



## HOW TO COMPILE

I provide integration with CMake and define the compiler as g++, but you
can edit the CMake file if you wish to use a different compiler. The compiler
used must be able to use the modules and views features of C++20. For more
information regarding the compatibility of different C++ compilers with modern
C++ features, please refer to https://en.cppreference.com/w/cpp/compiler_support/20.

To generate the makefile, simply run "cmake .." from within the build directory.
Afterwards, run make from within the build directory, and the binaries
will be generated inside build/bin.

This compiles in linux-based systems and should compile in *unix systems more broadly.
Relatively simple modifications must be made inside the CMakelists file to allow for 
windows compilation. For more information on this, see http://google.github.io/googletest/quickstart-cmake.html

## HOW TO RUN 

The makefile generates two binaries for your system. One is the output of unit tests
created using Gtest, and the other is an experiment that tests the efficiency
of different implementations of the array resizing.
