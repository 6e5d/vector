typedef struct {
	size_t size;
	size_t capacity;
	size_t len;
	void *p;
} Vector();

void vector(init)(Vector() *v, size_t size);
void vector(resize)(Vector() *v, size_t new_len);
void vector(reserve)(Vector() *v, size_t upcoming);
void vector(deinit)(Vector() *v);
void vector(pushback)(Vector() *v, void *elem);
void *vector(insert)(Vector() *v, size_t pos);
void vector(insert_value)(Vector() *v, void *elem, size_t pos);
bool vector(popback)(Vector() *v);
void *vector(offset)(Vector() *v, size_t index);
size_t vector(unwrap)(Vector() *v, void **p);
