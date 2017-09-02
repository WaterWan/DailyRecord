/**
子集生成算法：给定一个集合，枚举所有可能的子集
 
增量构造法 ：
一次选出一个元素放入集合中 
*/
#include <stdio.h>
#include <iostream>

using namespace std;
int A[1000];
/**
n: 元素总个数
A: 集合下标数组
cur: 当前集合下标数组的指针 
*/
void print_subset(int n, int* A, int cur) {
	for(int i = 0; i < cur; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	int s = cur ? A[cur - 1] + 1 : 0; // 找出当前最小可以加入的元素 
	for(int i = s; i < n; i++) {
		A[cur] = i;
		print_subset(n, A, cur + 1);
	}
} 

int main() {
	print_subset(10, A, 0);
}
