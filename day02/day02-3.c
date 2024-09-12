#include<stdio.h>

int main() {

	for (int a = 0; a <= 99; a++) {
		if (a % 7 == 0 || a % (3 * 4) == 0) {
			printf("%d\n", a);
		}
	}

	return 0;
}