#include <stdio.h>
#include <stdlib.h>

typedef struct case_of_test {
	unsigned int size;
	char *string;
} case_of_test_t;

void check_chance() {
	case_of_test_t *test = malloc(sizeof(case_of_test_t));
	scanf("%d", &test->size);
	test->string = (char *)malloc(test->size * sizeof(char));
	scanf("%s", test->string);
	printf("size: %d\ntext: %s\n", test->size, test->string);
}

int main(int argc, char **argv) {
	unsigned int count;
	scanf("%d", &count);
	while (count --> 0)
		check_chance();
	return 0;
}