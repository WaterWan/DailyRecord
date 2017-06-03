/**
ID: njuwz151
TASK: milk2
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
bool cmp(int a, int b) {
	return a < b;
}

int main() {
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	int number;
	cin >> number;
	int *start = new int[number];
	int *end = new int[number];
	int *milking = new int[number];
	int *idle = new int[number];
	for(int i = 0; i < number; i++) {
		cin >> start[i] >> end[i];
		milking[i] = 0;
		idle[i] = 0;
	}
	sort(start, start + number, cmp);
	sort(end, end + number, cmp);

	milking[0] = end[0] - start[0];
	for(int i = 0; i < number; i++) {
		if(i < number - 1 && end[i] < start[i+1]) {
			idle[i] = start[i+1] - end[i];
		}
	}
	for(int i = 0; i < number; i++) {
		if(i < number - 1 && end[i] >= start[i+1]) {
			start[i+1] = start[i];
		}
		milking[i] = end[i] - start[i];
	}
	sort(milking, milking + number, cmp);
	sort(idle, idle + number, cmp);
	cout << milking[number - 1] << " " << idle[number - 1] << endl;
} 
