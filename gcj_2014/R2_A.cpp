// Google Code Jam 2014 R2
// Problem A. Data Packing

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> IntVec;

int solve(int X, IntVec &v)
{
	int ans = 0;
	int N = v.size();
	sort(v.rbegin(), v.rend());
	int used[10000] = {};
	for (int i = 0; i < N; ++i) {
		if (!used[i]) {
			++ans;
			used[i] = 1;
			int r = X - v[i];
			for (int j = i + 1; j < N; ++j) {
				if (!used[j] && v[j] <= r) {
					used[j] = 1;
					break;
				}
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		int N = 0, X = 0;

		getline(cin, s);
		{
			stringstream ss(s);
			ss >> N >> X;
		}

		IntVec v(N);
		getline(cin, s);
		{
			stringstream ss(s);
			for (int i = 0; i < N; ++i) {
				ss >> v[i];
			}
		}

		int ans = solve(X, v);
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}

