# Minimal Arena Allocator

A minimal arena allocator written in C23 to understand the core concepts of memory management and avoid memory fragmentation.

## Prerequisites
You need a modern GCC compiler with C23 support and the `just` command runner.

## Build and Run
Run `just` in the root directory to compile the library, link the test file, and run the tests. Everything is output to the `build/` directory. Use `just clean` to remove build artifacts.

## Quick Start
```c
#include "arena.h"

int main() {
    Arena arena;
    
    // 1. Grab a large chunk from the OS
    arena_init(&arena, 1024);

    // 2. Allocate instantly
    void *ptr1 = arena_alloc(&arena, 16);
    void *ptr2 = arena_alloc(&arena, 32);

    // 3. Free everything at once
    arena_reset(&arena);

    // 4. Return memory to the OS
    arena_free(&arena);

    return 0;
}
