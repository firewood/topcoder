// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const double eps = 1e-8;

double A, B, C, D;

bool check(double r)
{
	double a = B * sin(r) + A * cos(r);
	double b = B * cos(r) + A * sin(r);
	return a - eps <= C && b - eps <= D;
}

int main(int argc, char *argv[])
{
	int N;
	string s;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> A >> B;
		if (A > B) {
			swap(A, B);
		}
	}
	getline(cin, s);
	N = atoi(s.c_str());
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		ss >> C >> D;
		if (C > D) {
			swap(C, D);
		}
		bool f = false;
		if (C >= A && D >= B) {
			f = true;
		} else {
			double low = 0, high = 3.14 / 4;
			while (low + eps < high) {
				double r = (low + high) / 2;
				double a = B * sin(r) + A * cos(r);
				if (a >= C) {
					high = r;
				} else {
					low = r;
				}
//				cout << a << "," << r << endl;
			}
			double x = high;

			low = 0, high = 3.14 / 4;
			while (low + eps < high) {
				double r = (low + high) / 2;
				double b = B * cos(r) + A * sin(r);
				if (b <= D) {
					high = r;
				} else {
					low = r;
				}
//				cout << b << "," << r << endl;
			}

			if (x-eps >= high) {
				f = true;
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}

	return 0;
}
