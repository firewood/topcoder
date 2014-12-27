#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;

typedef vector<int> IntVec;

bool solve(const IntVec &v)
{
	int total = accumulate(v.begin(), v.end(), 0);
	if (total % 2) {
		return false;
	}
	int f[12000] = {};
	f[0] = 1;
	for (int w : v) {
		for (int i = 10000; i >= w; --i) {
			if (f[i - w]) {
				f[i] = 1;
			}
		}
	}
	return f[total / 2] > 0;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	IntVec v(N);
	for (int i = 0; i < N; ++i) {
		ss >> v[i];
	}
	cout << (solve(v) ? "possible" : "impossible") << endl;
	return 0;
}
