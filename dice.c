#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char** argv){
	if (argc < 2)
		return 0;
	int i;
	int count = strlen(argv[1]);
	char* amount;
	char* size;
	i = 0;
	while (i < count){
		if (argv[1][i] == 'd')
			break;
		i++;
	}
	if (i == count || i + 1 == count)
		return 0;
	int j;
	int int_amount, int_size;
	amount = (char*)malloc(i);
	size = (char*)malloc(count - i - 1);
	for (j = 0; j < i; j++)
		amount[j] = argv[1][j];
       	for (j = i + 1; j < count; j++)
		size[j - (i + 1)] = argv[1][j];
	int_amount = atoi(amount);
	int_size = atoi(size);
	if (int_amount == 0 || int_size == 0)
		return 0;
	free(amount);
	free(size);

	struct timeval inst;
	gettimeofday(&inst, NULL);
	srand(inst.tv_usec);

	int sum = 0;
	j = 0;
	for (i = 0; i < int_amount - 1; i++){
		j = rand() % int_size + 1;
		sum += j;
		printf("%d + ", j);
	}
	
	j = rand() % int_size + 1;
	sum += j;
	printf("%d = %d\n", j, sum);

	return 0;
}
