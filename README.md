# hashmap

## Overview

A simple hash map implementation in C supporting string keys and generic `void*` values using separate chaining for collision resolution.

## Features

- Insert, Search, and Delete key-value pairs.
- Handles string keys with generic values (void*).
- Uses linked lists (chaining) to handle collisions.
- Simple djb2 string hash function.
- Memory management supported via freeHashMap().

## Getting Started

### Files

src/hashmap.h - Header file containing structs and function prototypes.
src/hashmap.c - Implementation of hash map functions.
src/main.c - Example usage of the hash map.

### Installation and Usage

1. **Clone the repository:**
    ```sh
    git clone https://github.com/bokshi-gh/hashmap
    cd hashmap
    ```

2. **Compile:**
    ```sh
    gcc -I./include src/main.c src/hashmap.c -o hashmap_example
    ```
    
3. **Run:**
    ```sh
    ./hashmap_example
    ```
