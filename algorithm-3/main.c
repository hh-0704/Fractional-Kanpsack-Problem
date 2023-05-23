#include <stdio.h>

void print_K(int K[5][11]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			printf("%d\t", K[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void main(void) {
	int C = 10;
	int n = 4;
	int nw[4] = { 5, 4, 6, 3 };
	int nv[4] = { 10, 40, 30, 50 };

	int K[5][11] = { 0 };

	for (int i = 0; i < n; i++) {
		K[i][0] = 0;
	}

	print_K(K);
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			if (nw[i - 1] > j) {
				K[i][j] = K[i - 1][j];
				continue;
			}
			int not_in_value = K[i - 1][j];
			int temp_nw = j - nw[i - 1];
			if (temp_nw < 0) {
				temp_nw = 0;
			}
			int put_in_value = K[i - 1][temp_nw] + nv[i - 1];
			if (not_in_value > put_in_value) {
				K[i][j] = not_in_value;
			}
			else if (put_in_value > not_in_value) {
				K[i][j] = put_in_value;
				printf("행렬값 갱신\n");
				print_K(K);
			}
		}
	}
	printf("\n최종 결과 행렬\n");
	print_K(K);
}