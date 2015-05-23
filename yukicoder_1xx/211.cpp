#include <iostream>
#include <algorithm>
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
	int count[201] = {};
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			count[a[0][i] * a[1][j]] += 1;
		}
	}
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	long double ans = count[N] / 36.0;
	cout << ans << endl;
	return 0;
}
