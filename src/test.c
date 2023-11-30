#include "../include/vector.h"

int main(void) {
	Vector v;
	vector_init(&v, sizeof(int));
	const int data[] = {1, 2, 3, 4, 5, 6};
	printf("%zu %zu %zu\n", v.size, v.len, v.capacity);
	for (size_t idx = 0; idx < 6; idx += 1) {
		vector_pushback(&v, (uint8_t *)&data[idx]);
	}
	for (size_t idx = 0; idx < v.len; idx += 1) {
		printf("%d ", *(int*)vector_offset(&v, idx));
	}
	printf("\n");
	for (size_t idx = 0; idx < 6; idx += 1) {
		vector_insert_value(&v, (uint8_t *)&data[idx], 3);
	}
	vector_insert_value(&v, (uint8_t *)&data[0], 12);
	vector_insert_value(&v, (uint8_t *)&data[0], 13);
	for (size_t idx = 0; idx < v.len; idx += 1) {
		printf("%d ", *(int*)vector_offset(&v, idx));
	}
	printf("\n");
	vector_deinit(&v);
}
