// Google Code Jam 2014 R2
// Problem B. Up and Down

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> IntVec;

int solve(IntVec &v)
{
	int ans = 0;
	int N = v.size();
	int left[1024];
	int right[1024];
	for (int i = 0; i < N; ++i) {
		int left = 0;
		for (int j = 0; j < i; ++j) {
			left += v[j] > v[i];
		}
		int right = 0;
		for (int j = i + 1; j < N; ++j) {
			right += v[j] > v[i];
		}
		ans += min(left, right);
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
		int N = 0;

		getline(cin, s);
		{
			stringstream ss(s);
			ss >> N;
		}

		IntVec v(N);
		getline(cin, s);
		{
			stringstream ss(s);
			for (int i = 0; i < N; ++i) {
				ss >> v[i];
			}
		}

		int ans = solve(v);
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}

