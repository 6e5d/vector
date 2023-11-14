#ifndef INCLUDEGUARD_VECTOR
#define INCLUDEGUARD_VECTOR

#include <stdbool.h>
#include <stddef.h>

typedef struct {
	size_t size;
	size_t capacity;
	size_t len;
	void* p;
} Vector;

void vector_init(Vector* v, size_t size);
void vector_resize(Vector* v, size_t new_len);
void vector_deinit(Vector* v);
void vector_pushback(Vector* v, void* elem);
bool vector_popback(Vector* v);
static inline void* vector_offset(Vector* v, size_t index) {
	return v->p + index * v->size;
}
size_t vector_unwrap(Vector* v, void** p);

#endif
