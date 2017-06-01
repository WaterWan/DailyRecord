/*
ID: njuwz151
TASK: friday
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
// sunday, monday, tuesday, wesnesday...
int days_in_13th[] = {0, 0, 0, 0, 0, 0, 0};

bool is_leap_year(int year);

void cal_day(int days);

int main(){
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	int days_in_leap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days_not_in_leap[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int start_year = 1900;
	int years;
	cin >> years;
	int year;
	int days = 13;
	int days_in_year[13];
	for(year = start_year; year < start_year + years; year++) {
		if(is_leap_year(year)) {
			memcpy(days_in_year, days_in_leap, sizeof(days_in_leap));
		} else {
			memcpy(days_in_year, days_not_in_leap, sizeof(days_not_in_leap));
		}
		for(int i = 0; i < 12; i++) {
			days += days_in_year[i];
			days %= 7;
			cal_day(days);
		}
		days += days_in_year[12];
	}
	cout << days_in_13th[6] << " ";
	for(int i = 0; i < 5; i++) {
		cout << days_in_13th[i] << " ";
	}
	cout << days_in_13th[5] << endl;
} 

bool is_leap_year(int year) {
	if(year % 400 == 0) {
		return true;
	}
	if(year % 100 != 0 && year % 4 == 0) {
		return true;
	}
	return false;
}

void cal_day(int days) {
	days_in_13th[days]++;
}
