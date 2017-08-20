int PowMod(int a, int b, int c) {
	// 快速求a^b%c，要避免计算中间结果溢出
	int result = 1;
	int base = a % c;
	while(b) {
		if(b & 1) {
			result = (result * base) % c;
		}
		base = (base * base) % c;
		b >>= 1;
	}
	return result;
}

