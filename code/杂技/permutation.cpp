#include <iostream>
#include <cstdio>
using namespace std;
int A[1000];
void print_permutation(int n, int* A, int cur) {
	if(cur == n) {
		for(int i = 0; i < n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1; i <= n; i++) {
		int ok = 1;
		for(int j = 0; j < cur; j++) {
			if(A[j] == i) {
				ok = 0;
			}
		}
		if(ok) {
			A[cur] = i;
			print_permutation(n, A, cur+1);
		}
	}
}

int main() {
	print_permutation(4, A, 0);
}
