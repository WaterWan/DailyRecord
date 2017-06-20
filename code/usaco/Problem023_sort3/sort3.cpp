/**
ID: njuwz151
TASK: sort3
LANG: C++
**/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
int n;
int number[maxn];
int expected[maxn];
int m_count[] = {0, 0, 0};
int swap_time = 0;
void search();

int main() {
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> number[i];
		m_count[number[i]-1]++;
	}
	for(int i = 0; i < m_count[0]; i++) {
		expected[i] = 1;
	}
	for(int i = m_count[0]; i < m_count[0] + m_count[1]; i++) {
		expected[i] = 2;
	}
	for(int i = m_count[0] + m_count[1]; i < n; i++) {
		expected[i] = 3;
	}
	search();
	cout << swap_time << endl;
} 

void search() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) {
				continue;
			}
			if(expected[i] == number[j] && expected[j] == number[i] && number[i] != number[j]) {
				swap(number[i], number[j]);
				swap_time++;	
			}
		}
	}
	int unpair = 0;
	for(int i = 0; i < n; i++) {
		if(expected[i]!=number[i]) {
			unpair++;
		}
	}
	swap_time += unpair / 3 * 2;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
