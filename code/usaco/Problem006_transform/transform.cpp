/**
ID: njuwz151
TASK: transform
LANG: C++
*/

#include <iostream>
#include <stdio.h>

using namespace std;
int n;
char input[10][10];
char trans[10][10];

typedef struct{
	bool (*func)(void);
} funcTable;

bool rotation90();

bool rotation180();

bool rotation270();

bool reflection();

bool combination();

bool noChange();

int main() {
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);

	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> trans[i][j];
		}
	}
	
	funcTable tab[6] = {{rotation90}, {rotation180}, {rotation270}, {reflection}, {combination}, {noChange}};
	
	for(int i = 0; i < 6; i++) {
		if(tab[i].func()) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << 7 << endl;
	return 0;
}

bool rotation90() {
	int m = n - 1;
	char result[10][10];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			result[i][j] = input[m - j][i];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(result[i][j] != trans[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool rotation180() {
	int m = n - 1;
	char temp1[10][10];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			temp1[i][j] = input[m - j][i];
		}
	}
	char result[10][10];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			result[i][j] = temp1[m - j][i];
		}
	}
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < n; j++) {
//			cout << result[i][j];
//		}
//		cout << endl;
//	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(result[i][j] != trans[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool rotation270() {
	int m = n - 1;
	char result[10][10];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			result[i][j] = input[j][m - i];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(result[i][j] != trans[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool reflection() {
	int m = n - 1;
	char result[10][10];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			result[i][j] = input[i][m - j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(result[i][j] != trans[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool combination() {
	bool ok = true;
	int m = n - 1;
	// reflection
	char temp[10][10];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			temp[i][j] = input[i][m - j];
		}
	}
	// rotation90
	char result[10][10];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			result[i][j] = temp[m - j][i];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(result[i][j] != trans[i][j]) {
				ok = false;
			}
		}
	}
	if(ok) {
		return true;
	}
	ok = true;
	
	// rotation180
	char temp1[10][10];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			temp1[i][j] = temp[m - j][i];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			result[i][j] = temp1[m - j][i];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(result[i][j] != trans[i][j]) {
				ok = false;
			}
		}
	}
	if(ok) {
		return true;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			result[i][j] = temp[j][m - i];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(result[i][j] != trans[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool noChange() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(input[i][j] != trans[i][j]) {
				return false;
			}
		}
	}
	return true;
}
