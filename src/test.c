#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/vector.h"

int main(void) {
	Vector v;
	vector_init(&v, sizeof(int));
	const int X1 = 123;
	printf("%zu %zu %zu\n", v.size, v.len, v.capacity);
	vector_pushback(&v, (uint8_t *)&X1);
	const int X2 = 456;
	vector_pushback(&v, (uint8_t *)&X2);
	int value = *(int *)vector_offset(&v, 1);
	printf("%d\n", value);
	printf("%zu %zu %zu\n", v.size, v.len, v.capacity);
	vector_deinit(&v);
}
