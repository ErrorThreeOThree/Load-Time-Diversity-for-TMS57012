typedef unsigned long int uint32_t;

#define ARRAY_SIZE 100
#define EQ_ERROR_1 0x1F
#define EQ_ERROR_2 0x2F
#define EQ_ERROR_3 0x3F
#define EQ_ERROR_4 0x4F

#define SELECTION_SORT_ERROR_CODE 0xA
#define BUBBLE_SORT_ERROR_CODE 0xB
#define INSERTION_SORT_ERROR_CODE 0xC
#define NO_ERROR 0xFF
#define ARRAY_COPY 0xD

void array_copy(const uint32_t *src, uint32_t *dst, uint32_t size);
int array_eq(const uint32_t *a1, const uint32_t *a2, uint32_t size);
void bubble_sort(uint32_t *array, uint32_t size);
void print_array(const uint32_t *arr, uint32_t size);
void insertion_sort(uint32_t *array, uint32_t size);
void selection_sort(uint32_t *array, uint32_t size);
void sys_exit(uint32_t code, uint32_t error_code, uint32_t val_a, uint32_t val_b);

// CPU regs for switchting between ram and flash
int main() {
	uint32_t algo[ARRAY_SIZE], code;
	const uint32_t array[ARRAY_SIZE] = {89,26,37,24,34,29,1,47,97,30,27,48,73,16,67,61,74,20,84,53,46,10,69,93,31,87,13,23,82,99,38,4,100,92,85,43,58,78,88,54,72,64,95,18,6,65,39,14,76,40,59,36,79,96,2,15,80,62,63,90,52,71,17,50,86,91,33,98,42,11,68,9,19,28,12,51,56,66,21,44,35,57,55,75,3,7,77,81,5,22,41,25,60,45,83,70,94,32,49,8};
	const uint32_t solution[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};


	array_copy(&array[0], &algo[0], ARRAY_SIZE);
	code = array_eq(algo, array, ARRAY_SIZE);
	if (ARRAY_SIZE != code) {
		sys_exit(code, EQ_ERROR_1, algo[code], array[code]);
	}

	bubble_sort((uint32_t *) algo, ARRAY_SIZE);
	code = array_eq(algo, solution, ARRAY_SIZE);
	if (ARRAY_SIZE != code) {
		sys_exit(code, BUBBLE_SORT_ERROR_CODE, algo[code], solution[code]);
	}

	// Bubble sort over

	// start insertion sort
	array_copy(&array[0], &algo[0], ARRAY_SIZE);
	code = array_eq(algo, array, ARRAY_SIZE);
	if (ARRAY_SIZE != code) {
		sys_exit(code, EQ_ERROR_2, algo[code], array[code]);
	}

	insertion_sort(&algo[0], ARRAY_SIZE);
	code = array_eq(algo, solution, ARRAY_SIZE);
	if (ARRAY_SIZE != code) {
		sys_exit(code, INSERTION_SORT_ERROR_CODE, algo[code], solution[code]);
	}
	// end insertion sort

	// start selection sort
	array_copy(&array[0], &algo[0], ARRAY_SIZE);
	code = array_eq(algo, array, ARRAY_SIZE);
	if (ARRAY_SIZE != code) {
		sys_exit(code, EQ_ERROR_4, algo[code], array[code]);
	}

	selection_sort(&algo[0], ARRAY_SIZE);
	code = array_eq(algo, solution, ARRAY_SIZE);
	if (ARRAY_SIZE != code) {
		sys_exit(code, SELECTION_SORT_ERROR_CODE, algo[code], solution[code]);
	}

	sys_exit(0xFFFF, NO_ERROR, 0xABC, 0xABC);
}

void array_copy(const uint32_t *src, uint32_t *dst, uint32_t size) {
	int i;
	for (i = 0; i < size; i++) {
		dst[i] = src[i];
	}
}

void bubble_sort(uint32_t *array, uint32_t size) {
	uint32_t tmp, i, swapped;
	do {
		swapped = 0;
		for (i = 1; i < size; i++) {
			if (array[i-1] > array[i]) {
				tmp = array[i];
				array[i] = array[i-1];
				array[i-1] = tmp;
				swapped = 1;
			}
		}
		size--;
	} while (1 == swapped);
}

void insertion_sort(uint32_t *array, uint32_t size) {
	uint32_t x;
	int j, i;
	i = 1;
	while (i < size) {
		x = array[i];
		j = i - 1;
		while((j >= 0) && (array[j] > x)) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = x;
		i++;
	}
}

void selection_sort(uint32_t *array, uint32_t size) {
	uint32_t min, tmp, i, j;
	for (i = 0; i+1 < size+1; i++) {
		uint32_t min = i;
		for (j = i+1; j < size; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		tmp = array[min];
		array[min] = array[i];
		array[i] = tmp;
	}
}

int array_eq(const uint32_t *a1, const uint32_t *a2, uint32_t size) {
	int i;
	for (i = 0; i < size; i++) {
		if (a1[i] != a2[i])
			return i;
	}
	return size;
}

void sys_exit(uint32_t code, uint32_t error_code, uint32_t val_a, uint32_t val_b) {
	while (1);
}
