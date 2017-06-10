#include <iostream>
//#include <cstdio>

using namespace std;

int main() {
//	freopen("4A.in", "r", stdin);
	
	int w;
	cin >> w;
	
	if(w % 2 == 0 && w != 2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
} 
