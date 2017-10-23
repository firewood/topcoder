// B.

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	long long n, a, e = 0, o = 0, p, ans;
	cin >> n >> a;
	e = (a % 2) ? 2 : 1;
	o = (a % 2) ? 1 : 2;
	for (int i = 1; i < n; ++i) {
		cin >> a;
		long long pe = e, po = o;
		e = (a % 2) ? (pe * 3 + po * 2) : (pe * 3 + po);
		o = (a % 2) ? po : (po * 2);
	}
	cout << e << endl;
	return 0;
}
