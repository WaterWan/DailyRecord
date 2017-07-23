#include <iostream>

using namespace std;

bool isPand(int hour, int minute) {
	return (hour % 10 == minute / 10) && (hour / 10 == minute % 10);
}


int main() {
	int hour;
	int minute;
	char c;
	cin >> hour >> c >> minute;
	int i = 0;
	while(!isPand(hour, minute)) {
		i++;
		minute++;
		if(minute >= 60) {
			minute = 0;
			hour++;
			if(hour >= 24) {
				hour = 0;
			}
		}
	}
	cout << i << endl;
}
