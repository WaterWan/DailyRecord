int Pow(int a, int b) {
	// ������a^b�����Ӷ�log(b)
	if(b == 0) {
		return 1;
	} 
	if(b & 1) {
		return a * Pow(a, b - 1);
	} else {
		int t = Pow(a, b / 2);
		return t * t;
	}
} 
