#include <stdio.h>

int main(void) {
	int arr[5] = {[1] = 10, [4] = 20};
	
	int i;
	for (i=0; i<5; i++)
		printf("[%d] %d \n", i+1, arr[i]);
}
