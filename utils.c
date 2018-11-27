#include "corrector.h"

void *my_malloc(size_t size)
{
	void *new = malloc(sizeof(*new) * size);
	assert(new);
	return (new);
}