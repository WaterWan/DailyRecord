#include <iostream>

using namespace std;

/**
**  a��1    ���������������յ� 
**  b��2    �������Լ����Լ�����ż����ֱ�Ӵ��� 
**  c��3    �ȶ�3�����ٶ�2���� 
**  d��4    ��һ������ͬһ������ 
*/
int main() {
	int n;
	int count[5] = {0, 0, 0, 0, 0};
	int s;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		count[s]++;
	}
	count[0] += count[4];
	// ��ʱϣ�����������е�3 
	if(count[3] > count[1]) { // ���3��1�࣬��ô�Ͱ�1�3���� 
		count[0] += count[3];
		count[3] = 0;
		count[1] = 0;
	} else {
		count[0] += count[3];
		count[1] -= count[3];
		count[3] = 0;
	}
	// ��ʱ���������е�2
	count[0] += count[2] / 2; 
	if(count[2] % 2 == 1) {
		count[0]++;	
		if(count[1] > 2) {
			count[1] -= 2;
		} else {
			count[1] = 0;
		}
	}
	count[2] = 0;  
	// ��ʱ���������е�1 
	count[0] += count[1] / 4;
	if(count[1] % 4) {
		count[0]++;
	}
	cout << count[0] << endl;
}
