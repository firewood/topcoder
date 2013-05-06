// Google Code Jam 2013 Round 1A
// Problem B. Manage your Energy
// large

#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef priority_queue<II> IIQueue;
typedef long long LL;

LL solve(LL E, LL R, int N, IIQueue &q)
{
	int i, j;
	LL minimum[10000] = {};
	LL maximum[10000] = {};
	for (i = 0; i < N; ++i) {
		maximum[i] = E;
	}
	LL ans = 0;
	while (q.size() > 0) {
		II a = q.top();
		q.pop();
		LL gain = max(0LL, maximum[a.second] - minimum[a.second]);
		if (gain <= 0) continue;
		LL g = maximum[a.second] - R;
		for (i = a.second - 1; i >= 0 && g >= 0; --i, g -= R) {
			minimum[i] = max(minimum[i], g);
		}
		g = E - R;
		for (i = a.second + 1; i < N && g >= 0; ++i, g -= R) {
			maximum[i] = min(maximum[i], E - g);
		}
		ans += a.first * gain;
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

		IIQueue q;
		getline(cin, s);
		{
			stringstream ss(s);
			for (int i = 0; i < N; ++i) {
				int j = -1;
				ss >> j;
				q.push(II(j, i));
			}
		}

		LL ans = solve(E, R, N, q);
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}

	return 0;
}

