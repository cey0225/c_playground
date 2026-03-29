#include "../src/arena.h"
#include <stdio.h>
#include <string.h>

int main() {
    Arena arena;

    printf("--- Arena Allocator Test Suite ---\n\n");

    arena_init(&arena, 1024);
    printf("Arena initialized with 1024 bytes.\n");

    void *p1 = arena_alloc(&arena, 16);
    void *p2 = arena_alloc(&arena, 32);

    printf("p1 start address: %p\n", p1);
    printf("p2 start address: %p\n", p2);

    strcpy((char*)p1, "Hello Arena!");
    strcpy((char*)p2, "Memory management is my playground.");

    printf("\n[Content of p1]: %s\n", (char*)p1);
    printf("[Content of p2]: %s\n\n", (char*)p2);

    printf("Resetting the arena...\n");
    arena_reset(&arena);

    void *p3 = arena_alloc(&arena, 16);

    if (p1 == p3) {
        printf("Success! p3 and p1 addresses match. Reset works: %p\n\n", p3);
    } else {
        printf("Failure! Addresses don't match, something is broken.\n\n");
    }

    arena_free(&arena);
    printf("Arena freed.\n");

    return 0;
}
