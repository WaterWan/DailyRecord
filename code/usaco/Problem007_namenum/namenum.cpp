/**
ID: njuwz151
TASK: namenum
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const char code[]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
char name[13],input[13];
int main() {
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	FILE* dict = fopen("dict.txt", "r");
	cin >> input;
	bool hasValid = false;
	while((fscanf(dict, "%s", name)) != EOF) {
		if(strlen(name) != strlen(input)) {
			continue;
		}
		for(int i = 0; i < strlen(name); i++) {
			if(code[name[i] - 'A'] != input[i]) {
				break;
			}
			if(i == strlen(name) - 1) {
				cout << name << endl;
				hasValid = true;
			}
		}
	}
	if(!hasValid) {
		cout << "NONE" << endl;
	}
}
