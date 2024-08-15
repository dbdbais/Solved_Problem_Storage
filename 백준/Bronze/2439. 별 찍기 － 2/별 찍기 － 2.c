#include<stdio.h>

int main() {
	int i, j, k, n;
		scanf("%d", &n);
	for (i = n - 1; i >= 0; i--) {
		for (j = i; j > 0; j--)
			printf(" ");
		for (k = 0; k <n-i; k++)
			printf("*");

		printf("\n");

	}
	return 0;

}