#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

double binary_search(int a, int b, double t) {
	double ans;
	if (a == 0) {
		ans = exp(pow(t, 1.0 / b));
	} else if (b == 0) {
		ans = pow(t, 1.0 / a);
	} else {
		for (int i = 2; i <= 10; ++i) {
			while (a % i == 0 && b % i == 0) {
				a /= i, b /= i, t = pow(t, 1.0 / i);
			}
		}

		double left = 1.0, right = max(2.0, t * 100), prev = 1.0e+10;
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
				if (n - prev < 2.0e-11) {
					break;
				}
			} else {
				if (prev - n < 2.0e-11) {
					break;
				}
			}
			prev = n;
		}
		ans = left;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		double t;
		scanf("%d %d %lf", &a, &b, &t);
		printf("%.10f\n", binary_search(a, b, t));
	}
	return 0;
}
