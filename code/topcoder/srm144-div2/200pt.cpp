#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Time {
	public :
	string whatTime(int seconds) {
		string result = "";
		int h = seconds / 3600;
		seconds -= 3600 * h;
		int m = seconds / 60;
		seconds -= 60 * m;
		result += itos(h);
		result += ":";
		result += itos(m);
		result += ":";
		result += itos(seconds);
		return result;
	}
	string itos(const int n) {
		stringstream ss;
		ss << n;
		return ss.str();
	}
};
