#ifndef LIBFT_MALLOC_MEMORY_H
#define LIBFT_MALLOC_MEMORY_H

#include <pthread.h>

#include "libft_malloc/zones.h"
#include "libft_malloc/larges.h"
#include "libft_malloc/allocation_histories.h"
#include "libft_malloc/debug_variables.h"

#define TINY_MAX_SIZE 256
#define SMALL_MAX_SIZE 4096

typedef struct memory_s
{
	zones_t *tinies;
	zones_t *smalls;
	larges_t *larges;
#ifdef ENABLE_DEBUG_VARIABLES
	debug_variables_t debug_variables;
	allocation_histories_t *histories;
	size_t allocations_count;
	size_t used_bytes_count;
#endif
} memory_t;

extern memory_t memory;
extern pthread_mutex_t memory_mutex;

#endif
