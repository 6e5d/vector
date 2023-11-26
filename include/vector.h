#ifndef INCLUDEGUARD_VECTOR_VECTORH
#define INCLUDEGUARD_VECTOR_VECTORH

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
	size_t size;
	size_t capacity;
	size_t len;
	void *p;
} Vector;

void vector_init(Vector *v, size_t size);
void vector_resize(Vector *v, size_t new_len);
void vector_reserve(Vector *v, size_t upcoming);
void vector_deinit(Vector *v);
void vector_pushback(Vector *v, void *elem);
void *vector_insert(Vector *v, size_t pos);
void vector_insert_value(Vector *v, void *elem, size_t pos);
bool vector_popback(Vector *v);
static inline void *vector_offset(Vector *v, size_t index) {
	return (void *)((uint8_t*)v->p + index * v->size);
}
size_t vector_unwrap(Vector *v, void **p);

#endif
