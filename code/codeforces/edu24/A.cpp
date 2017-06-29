#include <iostream>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long dip, cer, not_winner;
	dip = n / (2 * (k + 1));
	cer = dip * k;
	not_winner = n - dip - cer;
	cout << dip << " " << cer << " " << not_winner << endl;
	return 0;
}
