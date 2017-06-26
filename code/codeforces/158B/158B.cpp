#include <iostream>

using namespace std;

/**
**  a个1    这明显是用来补空的 
**  b个2    首先是自己与自己处理，偶数就直接处理 
**  c个3    先对3处理，再对2处理 
**  d个4    这一定是在同一辆车的 
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
	// 此时希望处理完所有的3 
	if(count[3] > count[1]) { // 如果3比1多，那么就把1搭到3里面 
		count[0] += count[3];
		count[3] = 0;
		count[1] = 0;
	} else {
		count[0] += count[3];
		count[1] -= count[3];
		count[3] = 0;
	}
	// 此时处理完所有的2
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
	// 此时处理完所有的1 
	count[0] += count[1] / 4;
	if(count[1] % 4) {
		count[0]++;
	}
	cout << count[0] << endl;
}
