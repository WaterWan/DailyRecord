/**
�Ӽ������㷨������һ�����ϣ�ö�����п��ܵ��Ӽ�
 
�������취 ��
һ��ѡ��һ��Ԫ�ط��뼯���� 
*/
#include <stdio.h>
#include <iostream>

using namespace std;
int A[1000];
/**
n: Ԫ���ܸ���
A: �����±�����
cur: ��ǰ�����±������ָ�� 
*/
void print_subset(int n, int* A, int cur) {
	for(int i = 0; i < cur; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	int s = cur ? A[cur - 1] + 1 : 0; // �ҳ���ǰ��С���Լ����Ԫ�� 
	for(int i = s; i < n; i++) {
		A[cur] = i;
		print_subset(n, A, cur + 1);
	}
} 

int main() {
	print_subset(10, A, 0);
}
