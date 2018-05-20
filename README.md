BSTree [![Build Status](https://travis-ci.org/amirnyy/BSTree.svg?branch=master)](https://travis-ci.org/amirnyy/BSTree)

Run tests
```ShellSession
$ cmake -H. -B_build  -DBUILD_TESTS=ON
$ cmake --build _build --target install
$ cmake --build _build --target test -- ARGS=--verbose
```
Run examples
```ShellSession
$ cmake -H. -B_build  -DCMAKE_INSTALL_PREFIX=install
$ cmake --build _build --target install
```
