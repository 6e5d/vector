#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "../include/vector.h"

// v must be allocated vector pointer
void vector_init(Vector* v, size_t size) {
	v->size = size;
	v->capacity = 0;
	v->len = 0;
	v->p = NULL;
}

void vector_resize(Vector* v, size_t new_len) {
	if (new_len <= v->capacity) {
		v->len = new_len;
		return;
	}
	v->len = new_len;
	v->capacity = new_len;
	v->p = realloc(v->p, v->capacity * v->size);
	assert(NULL != v->p);
}

void vector_deinit(Vector* v) {
	free(v->p);
}

void vector_pushback(Vector* v, void* elem) {
	if (v->capacity == 0) {
		v->p = realloc(v->p, v->size);
		assert(NULL != v->p);
		v->capacity = 1;
	} else if (v->len == v->capacity) {
		v->capacity *= 2;
		v->p = realloc(v->p, v->capacity * v->size);
		assert(NULL != v->p);
	}
	void* offset = v->p + v->len * v->size;
	v->len += 1;
	memcpy(offset, elem, v->size);
}

bool vector_popback(Vector* v) {
	if (v->len == 0) {
		return false;
	}
	v->len -= 1;
	return true;
}

size_t vector_unwrap(Vector* v, void** p) {
	*p = v->p;
	return v->len;
}
