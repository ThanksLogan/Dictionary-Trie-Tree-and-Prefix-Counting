# C++ Dictionary Data Structure and Prefix Counting

## Overview
This C++ project involves implementing a dictionary data structure using a trie (prefix tree) and a program to count the number of words starting with a specific prefix. It parses vocabulary from a file, builds a tree structure for efficient word storage and lookup, and then reads a test file to count the occurrences of words with certain prefixes.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., g++)
- Standard C++ libraries
- Make utility (optional for build automation)

### Installation and Compilation
1. Ensure g++ or a similar C++ compiler is installed on your machine.
2. Clone or download this repository to your local machine.
3. Use the provided Makefile for easy compilation:
```
make
```
This will create the executable `countprefix`.

### Running the Program
Run the program with two arguments: the vocabulary file and the test file.
```
./countprefix [vocabulary_file] [test_file]
```


## Code Description

### Files and Modules
- `dictionary.h` & `dictionary.cpp`: Implements the dictionary data structure using a trie.
- `countprefix.cpp`: Contains the main function to drive the program.
- `Makefile`: Script for compiling the program with the correct flags and dependencies.

### Key Components
- **Dictionary Data Structure**:
  - Implemented as a trie (prefix tree) for efficient word storage and lookup.
  - Supports operations like word addition and prefix-based searches.

- **Word Counting Logic**:
  - Reads a list of words from the vocabulary file and builds the dictionary.
  - Parses the test file to find and count the number of words starting with specified prefixes.

### Compilation Flags
- `-std=c++11`: Uses C++11 standard.
- `-Wall`: Enables all compiler's warning messages.
- `-g3`: Includes extra debugging information.

### Makefile Targets
- `$(PROGRAM)`: Compiles the main program.
- `clean`: Removes compiled objects and executable for cleanup.

## Testing
- The project includes test cases in the main function to demonstrate its functionality.
- It reads words from the vocabulary file, builds the dictionary, and counts word occurrences from the test file.

## Author

