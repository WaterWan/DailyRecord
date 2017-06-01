/*
ID: njuwz151
TASK: beads
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int count_start(string s, int len);
int count_end(string s, int len);

int main() {
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	int number;
	cin >> number;
	string beads;
	cin >> beads;
	int max_number = 0;
	int temp_number = 0;
	for(int i = 0; i < number; i++) {
		string bead_line;
		for(int j = i; j < number; j++) {
			bead_line += beads[j];
		}
		for(int j = 0; j < i; j++) {
			bead_line += beads[j];
		}
		temp_number = count_start(bead_line, number) + count_end(bead_line, number);
		if(temp_number > number) {
			temp_number = number;
		}
		if(temp_number > max_number) {
			max_number = temp_number;
		}
	}
	cout << max_number << endl;
	return 0;
	
}

int count_start(string s, int len) {
	char c = s[0];
	if(c != 'w') {
		for(int i = 0; i < len; i++) {
			if(s[i] != c && s[i] != 'w') {
				return i;
			}
		}
	} else {
		int max = 0;
		c = 'b';
		for(int i = 0; i < len; i++) {
			if(s[i] != c && s[i] != 'w') {
				max = i;
				break;
			}
			if(i == len - 1) {
				max = len;	
			}
			
			
		}
		c = 'r';
		for(int i = 0; i < len; i++) {
			if(s[i] != c && s[i] != 'w') {
				if(i > max) {
					max = i;
				}
				break;
			}
			if(i == len - 1) {
				max = len;
			}
			
		}
		return max;
	}

	return len;
}

int count_end(string s, int len) {
	char c = s[len - 1];
	if(c != 'w') {
		for(int i = len - 1; i >= 0; i--) {
			if(s[i] != c && s[i] != 'w') {
				return len - 1 - i;
			}
		}
	} else {
		int max = 0;
		c = 'b';
		for(int i = len - 1; i >= 0; i--) {
			if(s[i] != c && s[i] != 'w') {
				max = len - 1 - i;
				break;
			}
			if(i == 0) {
				max = len;
			}
			
		}
		c = 'r';
		for(int i = len - 1; i >= 0; i--) {
			if(s[i] != c && s[i] != 'w') {
				if(i > max) {
					if(len - 1 - i > max) {
						max = len - 1 - i;
					}
				}
				break;
			}
			if(i == 0) {
				max = len;			
			}

		}
		return max;
	}

	return len;
}
