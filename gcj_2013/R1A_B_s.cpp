// Google Code Jam 2013 R1
// Problem B. Manage your Energy
// small

#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int act[100];

int solve(int E, int R, int N)
{
	int prev[11];
	memset(prev, -1, sizeof(prev));
	prev[E] = 0;
	int i, j, k;
	for (i = 0; i < N; ++i) {
		int next[11];
		memset(next, -1, sizeof(next));
		for (j = 1; j <= E; ++j) {
			if (prev[j] < 0) {
				continue;
			}
			for (k = 0; k <= j; ++k) {
				int ne = min(E, j - k + R);
				next[ne] = max(next[ne], prev[j] + act[i] * k);
			}
		}
		memcpy(prev, next, sizeof(prev));
	}

	int ans = 0;
	for (i = 0; i <= E; ++i) {
		ans = max(ans, prev[i]);
	}
	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		int E = 0, R = 0, N = 0;
		getline(cin, s);
		{
			stringstream ss(s);
			ss >> E >> R >> N;
		}

		getline(cin, s);
		{
			stringstream ss(s);
			for (int i = 0; i < N; ++i) {
				ss >> act[i];
			}
		}

		int ans = solve(E, R, N);
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}

	return 0;
}

