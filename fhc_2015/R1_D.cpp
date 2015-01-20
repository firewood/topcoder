//
// Facebook Hacker Cup 2015 Round 1
// D. Corporate Gifting
//

/*
Constraints

1 <= T <= 100
1 <= N <= 200,000

NOTE: The input file is about 10-20MB.
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> IntVec;

#define MAX_COLORS 16

struct Employee {
	IntVec subs;
	Employee() {
		memset(costs, 0x3f, sizeof(costs));
	}
	int costs[MAX_COLORS];
};
typedef vector<Employee> EmpVec;

void dfs(EmpVec &ev, int parent) {
	Employee &e = ev[parent];
	for (int i : e.subs) {
		dfs(ev, i);
	}
	for (int i = 0; i < MAX_COLORS; ++i) {
		int tot = i + 1;
		for (int j : e.subs) {
			int m = 1 << 24;
			Employee &sub = ev[j];
			for (int k = 0; k < MAX_COLORS; ++k) {
				if (i != k) {
					m = min(m, sub.costs[k]);
				}
			}
			tot += m;
		}
		e.costs[i] = tot;
	}
}

int solve(const vector<int> &v) {
	EmpVec ev(v.size());
	for (int i = 1; i < (int)v.size(); ++i) {
		int boss = v[i] - 1;
		ev[boss].subs.push_back(i);
	}
	dfs(ev, 0);
	return *min_element(ev[0].costs, ev[0].costs + MAX_COLORS);
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		int N = atoi(s.c_str());
		getline(cin, s);
		stringstream ss(s);
		vector<int> v(N);
		for (int i = 0; i < N; ++i) {
			ss >> v[i];
		}
		int ans = solve(v);
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}
	return 0;
}
