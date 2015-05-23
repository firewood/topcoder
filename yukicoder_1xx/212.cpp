#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(16);
	int a[2][6] = {
		{ 2, 3, 5, 7, 11, 13 },
		{ 4, 6, 8, 9, 10, 12 }
	};
	int s1 = accumulate(a[0], a[0] + 6, 0);
	int s2 = accumulate(a[1], a[1] + 6, 0);
	string s;
	getline(cin, s);
	stringstream ss(s);
	int P, C;
	ss >> P >> C;
	long double ans = 1.0;
	for (int i = 0; i < P; ++i) {
		ans *= (s1 / 6.0);
	}
	for (int i = 0; i < C; ++i) {
		ans *= (s2 / 6.0);
	}
	cout << ans << endl;
	return 0;
}
