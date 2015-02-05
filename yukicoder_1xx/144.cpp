#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(16);
	int N;
	double p;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> N >> p;
	static double tbl[1000001];
	for (int i = 2; i <= N; ++i) {
		tbl[i] = 1.0;
	}
	double ans = 0;
	for (int i = 2; i <= N; ++i) {
		for (int j = i * 2; j <= N; j += i) {
			tbl[j] *= (1.0 - p);
		}
		ans += tbl[i];
	}
	cout << ans << endl;
	return 0;
}
