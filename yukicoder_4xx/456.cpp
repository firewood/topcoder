#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

double binary_search(int a, int b, double t) {
	double left = 1.0e-10, right = t, prev = 1.0e+10;
	if (b >= 1) {
		left = 1.0;
	}
	if (b == 0) {
		left = exp(log(t) / a);
	} else if (a == 0 && b == 1) {
		left = exp(t);
	} else {
		right = max(2.0, t * 100);

		for (int j = 0; j < 100; ++j) {
			double mid = (left + right) / 2;
			double x = 1, y = 1, z = log(mid);
			switch (a) {
			case 1: x = mid; break;
			case 2: x = mid * mid; break;
			case 3: x = mid * mid * mid; break;
			case 4: x = mid * mid; x *= x; break;
			case 5: x = mid * mid; x = mid * x * x; break;
			case 6: x = mid * mid; x = x * x * x; break;
			case 7: x = mid * mid; x = mid * x * x * x; break;
			case 8: x = mid * mid; x *= x; x *= x; break;
			case 9: x = mid * mid * mid; x = x * x * x; break;
			case 10: x = mid * mid * mid; x = mid * x * x * x; break;
			}
			switch (b) {
			case 1: y = z; break;
			case 2: y = z * z; break;
			case 3: y = z * z * z; break;
			case 4: y = z * z; y *= y; break;
			case 5: y = z * z; y = z * y * y; break;
			case 6: y = z * z; y = y * y * y; break;
			case 7: y = z * z; y = z * y * y * y; break;
			case 8: y = z * z; y *= y; y *= y; break;
			case 9: y = z * z * z; y = y * y * y; break;
			case 10: z *= z; y = z * z; y = z * y * y; break;
			}
			double n = x * y;
			if (n <= t) {
				left = mid;
			} else {
				right = mid;
			}
			if (n > prev) {
				if (n - prev < 1.0e-10) {
					break;
				}
			} else {
				if (prev - n < 1.0e-10) {
					break;
				}
			}
			prev = n;
		}
	}
	return left;
}

int main(int argc, char *argv[]) {
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		double t;
		cin >> a >> b >> t;
		printf("%.10f\n", binary_search(a, b, t));
	}
	return 0;
}
