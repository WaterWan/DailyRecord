/**
ID: njuwz151
TASK: barn1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 200

using namespace std;

bool cmp(int m, int n);

int main() {
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	int m, s, c;
	int n[MAXN];
	int delta[MAXN];
	cin >> m >> s >> c;
	for(int i = 0; i < c; i++) {
		cin >> n[i];
	}
	if(m >= c) {
		cout << c << endl;
		return 0;
	}
	sort(n, n + c);
	/**
	* ��һ�鳤ľ����Ը������е�ţ��ҵ�m-1����϶����ô�Ͱ�ţ��ֳ���m��
	* Ҳ����˵ȥ��m-1�����Ŀ�϶�������ҵ���̵�ľ�� 
	*/
	for(int i = 1; i < c; i++) {
		delta[i-1] = n[i] - n[i-1] - 1;
	}
	sort(delta, delta + c - 1, cmp);

	int min = n[c-1] - n[0] + 1;
	for(int i = 0; i < m-1; i++) {
		min -= delta[i];
	}
	cout << min << endl;
	
}

bool cmp(int m, int n) {
	return m > n;
}


