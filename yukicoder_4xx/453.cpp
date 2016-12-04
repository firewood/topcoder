#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

long double calc(long double C, long double D, long double A) {
	long double B = min((C - A * 21) / 8, (D - A * 7) / 20);
	return A * 1000 + B * 2000;
}

int main(int argc, char *argv[]) {
	cout.precision(16);
	long double C, D;
	cin >> C >> D;
	C *= 28, D *= 28;
	long double left = 0, right = min(C / 21, D / 7);
	for (int i = 0; i < 100; ++i) {
		if (calc(C, D, (left * 2 + right) / 3) > calc(C, D, (left + right * 2) / 3)) {
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	cout << calc(C, D, left) << endl;
	return 0;
}
