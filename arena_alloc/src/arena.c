#include "arena.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void arena_init(Arena *a, size_t size) {
    a->buffer = (unsigned char *) malloc(size);

    if (a->buffer == NULL) {
        fprintf(stderr, "Error: Arena allocation failed (requested %zu bytes)\n", size);
        exit(1);
    }

    a->capacity = size;
    a->offset = 0;
}

void *arena_alloc(Arena *a, size_t size) {
    size_t align = _Alignof(max_align_t);
    size_t padding = (align - (a->offset % align)) % align;
    size_t aligned_offset = a->offset + padding;

    if (aligned_offset + size > a->capacity) {
        printf("Error: There isn't enough space in the arena.");
        return NULL;
    }

    void *ptr = a->buffer + aligned_offset;
    a->offset = aligned_offset + size;

    return ptr;
}

void arena_reset(Arena *a) {
    a->offset = 0;
}

void arena_free(Arena *a) {
    free(a->buffer);
    a->buffer = NULL;
    a->capacity = 0;
    a->offset = 0;
}
