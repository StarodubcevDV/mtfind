# mtfind

Finding mask matches in file using pthreads.

## How to run project in devcontainer
1. Install devcontainer extension from VSCode extension store.
2. Run devcontainer from existing Dockerfile.

## Build

Project can be compiled using Cmake. Build artifcats will be stored in build folder.

## Test system

Ubuntu 20.04.2   
Thread model: posix   
gcc version 9.4.0   


## Example

Input file content:   
```
I've paid my dues
Time after time.
I've done my sentence
But committed no crime.
And bad mistakes ?
I've made a few.
I've had my share of sand kicked in my face
But I've come through.
```

Command to run:   
```
build/mtfind tests/example_data/test_data.txt "?ad"
```

Result:   
```
3
5 5 bad
6 6 mad
7 6 had
```