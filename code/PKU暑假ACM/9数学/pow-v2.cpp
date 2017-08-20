int Pow(int a, int b) {
	// 快速求a^b，复杂度log(b)
	int result = 1;
	int base = a;
	while(b) {
		if(b & 1) {
			result *= base;
		}
		base *= base;
		b >>= 1;
	}
	return result;
}
