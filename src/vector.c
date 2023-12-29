#include "../include/vector.h"

// v must be allocated vector pointer
void vector(init)(Vector() *v, size_t size) {
	v->size = size;
	v->capacity = 0;
	v->len = 0;
	v->p = NULL;
}

void vector(resize)(Vector() *v, size_t new_len) {
	if (new_len <= v->capacity) {
		v->len = new_len;
		return;
	}
	v->len = new_len;
	v->capacity = new_len;
	v->p = realloc(v->p, v->capacity * v->size);
	assert(NULL != v->p);
}

void vector(deinit)(Vector() *v) {
	free(v->p);
}

void vector(reserve)(Vector() *v, size_t upcoming) {
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

void vector(pushback)(Vector() *v, void *elem) {
	vector(reserve)(v, 1);
	uint8_t *offset = (uint8_t*)v->p + v->len * v->size;
	v->len += 1;
	memcpy(offset, elem, v->size);
}

void *vector(insert)(Vector() *v, size_t pos) {
	assert(pos <= v->len);
	vector(reserve)(v, 1);
	// shift all elements after pos
	uint8_t *p0 = v->p;
	for (uint8_t *offset = p0 + (v->len - 1) * v->size;
		offset >= p0 + pos * v->size;
		offset -= v->size
	) {
		memcpy(offset + v->size, offset, v->size);
	}
	v->len += 1;
	return (p0 + pos * v->size);
}

void vector(insert_value)(Vector() *v, void *elem, size_t pos) {
	void *p = vector(insert)(v, pos);
	memcpy(p, elem, v->size);
}

bool vector(popback)(Vector() *v) {
	if (v->len == 0) {
		return false;
	}
	v->len -= 1;
	return true;
}
void *vector(offset)(Vector() *v, size_t index) {
	return (void *)((uint8_t*)v->p + index * v->size);
}

size_t vector(unwrap)(Vector() *v, void **p) {
	*p = v->p;
	return v->len;
}
