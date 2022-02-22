# Utils

A library containing common data structures/algorithms/etc. that I commonly use.


## Building from source

First clone the repository and cd into the directory made
```bash
$ git clone https://github.com/ClaytonKnittel/Utils.git
$ cd Utils
```
Then create a build directory and run CMake from within it
```bash
$ mkdir build && cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ make
$ make install
```

The utils library is installed at `${CMAKE_INSTALL_PREFIX}/lib`, and the header files at `${CMAKE_INSTALL_PREFIX}/include`.


### CMake options

| Option | Default Value | Description |
| ------ | ------------- | ----------- |
| BUILD_SHARED_LIBRARY | ON | When enabled, build libutils as a shared library, otherwise build as a static library. |
| ENABLE_TESTING | OFF | When enabled, build all unit tests. The unit tests can then be run from within the build directory with `make run_tests`. The library produced has extra assertions enabled and is linked against libcheck, so be sure to link agains a library build with ENABLE_TESTING=OFF for external usage. |
| ENABLE_AVX | ON | When enabled, use AVX instructions for improved performance. If this value is not supplied, AVX support is tested for on the matchine. |
