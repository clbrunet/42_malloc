#ifndef LIBFT_MALLOC_H
#define LIBFT_MALLOC_H

#include <stdlib.h>

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void show_alloc_mem();
void show_alloc_mem_ex();
void show_alloc_stats();

#endif
