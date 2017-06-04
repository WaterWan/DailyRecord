/*
ID: njuwz151
TASK: transform
LANG: C++
*/
#include <iostream>
#include <stdio.h>

#define MAXN 10

using namespace std;

typedef struct {
	int n;
	char content[MAXN][MAXN];
} Board;

typedef struct {
	int id;
	bool (*func)(Board before, Board after);
} funcEntry;

Board readBoard(int n);
bool boardCmp(Board b1, Board b2);
Board rotate(Board b);
Board reflect(Board b);

bool rotation90(Board before, Board after);
bool rotation180(Board before, Board after);
bool rotation270(Board before, Board after);
bool reflection(Board before, Board after);
bool combination(Board before, Board after);
bool noChange(Board before, Board after);
bool invalidTrans(Board before, Board after);

int main() {
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	int n;
	cin >> n;
	Board before = readBoard(n);
	Board after = readBoard(n);
	funcEntry funcTable[7] = {
								{1, rotation90},
								{2, rotation180},
								{3, rotation270},
								{4, reflection},
								{5, combination},
								{6, noChange},
								{7, invalidTrans}};
	for(int i = 0; i < 7; i++) {
		if(funcTable[i].func(before, after)) {
			cout << funcTable[i].id << endl;
			return 0;
		}
	}
}

Board readBoard(int n) {
	Board board;
	board.n = n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> board.content[i][j];
		}
	}
	return board;
}

bool boardCmp(Board b1, Board b2) {
	if(b1.n != b2.n) {
		return false;
	}
	int n = b1.n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(b1.content[i][j] != b2.content[i][j]) {
				return false;
			}
		}
	}
	return true;
}

Board rotate(Board b) {
	Board result;
	result.n = b.n;
	int n = b.n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			result.content[i][j] = b.content[n - 1 - j][i];
		}
	}
	return result;
}

Board reflect(Board b) {
	Board result;
	result.n = b.n;
	int n = b.n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			result.content[i][j] = b.content[i][n - 1 - j];
		}
	}
	return result;
}

bool rotation90(Board before, Board after) {
	return boardCmp(rotate(before), after);
}
bool rotation180(Board before, Board after) {
	return boardCmp(rotate(rotate(before)), after);
}
bool rotation270(Board before, Board after) {
	return boardCmp(rotate(rotate(rotate(before))), after);
}
bool reflection(Board before, Board after) {
	return boardCmp(reflect(before), after);
}
bool combination(Board before, Board after) {
	Board temp = reflect(before);
	return rotation90(temp, after) || rotation180(temp, after) || rotation270(temp, after);
}
bool noChange(Board before, Board after) {
	return boardCmp(before, after);
}
bool invalidTrans(Board before, Board after) {
	return true;
}
