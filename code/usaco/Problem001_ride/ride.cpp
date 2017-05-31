/*
ID:njuwz151
LANG:C++
TASK:ride
*/
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	FILE* fin = fopen("ride.in", "r");
	FILE* fout = fopen("ride.out", "w");
	
	char line1[8];
	char line2[8];
	for(int i = 0; i < 8; i++) {
		line1[i] = 0;
		line2[i] = 0;
	}
	 
	fscanf(fin, "%s", line1);
	fscanf(fin, "%s", line2);
	
	int result1 = 1;
	int result2 = 1;
	for(int i = 0; i < 6; i++) {
		if(line1[i] != 0 && line1[i] != '\n') {
			result1 *= (line1[i] - 'A' + 1);
		}
		if(line2[i] != 0 && line2[i] != '\n') {
			result2 *= (line2[i] - 'A' + 1);
		}
	}
	
	result1 %= 47;
	result2 %= 47;
	
	if(result1 == result2) {
		fprintf(fout, "GO\n");
	} else {
		fprintf(fout, "STAY\n");
	}
} 
