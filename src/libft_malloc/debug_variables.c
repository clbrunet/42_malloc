#include <stdlib.h>
#include <assert.h>

#include "libft_malloc/debug_variables.h"
#include "libft_malloc/utils/print.h"
#include "libft_malloc/utils/string.h"

#ifdef ENABLE_DEBUG_VARIABLES

void setDebugVariables(debug_variables_t *debug_variables)
{
	assert(debug_variables != NULL);

	char *perturb_env_value = getenv("MALLOC_PERTURB_");
	if (perturb_env_value != NULL) {
		debug_variables->perturb_byte = stringToUChar(perturb_env_value);
	} else {
		debug_variables->perturb_byte = 0;
	}

	char *fail_at_env_value = getenv("MALLOC_FAIL_AT_");
	if (fail_at_env_value != NULL) {
		debug_variables->fail_at = stringToULong(fail_at_env_value);
	} else {
		debug_variables->fail_at = 0;
	}

	char *max_bytes_env_value = getenv("MALLOC_MAX_BYTES_");
	if (max_bytes_env_value != NULL) {
		debug_variables->max_bytes = stringToULong(max_bytes_env_value);
	} else {
		debug_variables->max_bytes = 0;
	}


	char *enable_history_value = getenv("MALLOC_ENABLE_HISTORY_");
	if (enable_history_value != NULL) {
		if (stringToULong(enable_history_value) == 0) {
			debug_variables->enable_history = false;
		} else {
			debug_variables->enable_history = true;
		}
	} else {
		debug_variables->enable_history = false;
	}

	debug_variables->is_initialized = true;
}

#endif
