#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/vector.h"

// v must be allocated vector pointer
void vector_init(Vector *v, size_t size) {
	v->size = size;
	v->capacity = 0;
	v->len = 0;
	v->p = NULL;
}

void vector_resize(Vector *v, size_t new_len) {
	if (new_len <= v->capacity) {
		v->len = new_len;
		return;
	}
	v->len = new_len;
	v->capacity = new_len;
	v->p = realloc(v->p, v->capacity * v->size);
	assert(NULL != v->p);
}

void vector_deinit(Vector *v) {
	free(v->p);
}

void vector_reserve(Vector *v, size_t upcoming) {
	while (v->len + upcoming <= v->capacity) {
		return;
	}
	if (v->capacity == 0) {
		v->p = realloc(v->p, upcoming * v->size);
		assert(NULL != v->p);
		v->capacity = upcoming;
		return;
	}
	while (v->len + upcoming > v->capacity) {
		v->capacity *= 2;
	}
	v->p = realloc(v->p, v->capacity * v->size);
	assert(NULL != v->p);
}

void vector_pushback(Vector *v, void *elem) {
	vector_reserve(v, 1);
	void *offset = v->p + v->len * v->size;
	v->len += 1;
	memcpy(offset, elem, v->size);
}

void *vector_insert(Vector *v, size_t pos) {
	assert(pos <= v->len);
	vector_reserve(v, 1);
	// shift all elements after pos
	void *offset;
	for (offset = v->p + (v->len - 1) * v->size;
		offset >= v->p + pos * v->size;
		offset -= v->size
	) {
		memcpy(offset + v->size, offset, v->size);
	}
	v->len += 1;
	return (v->p + pos * v->size);
}

void vector_insert_value(Vector *v, void *elem, size_t pos) {
	void *p = vector_insert(v, pos);
	memcpy(p, elem, v->size);
}

bool vector_popback(Vector *v) {
	if (v->len == 0) {
		return false;
	}
	v->len -= 1;
	return true;
}

size_t vector_unwrap(Vector *v, void **p) {
	*p = v->p;
	return v->len;
}
