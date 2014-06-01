// Google Code Jam 2014 R1B
// Problem C. The Bored Traveling Salesman

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
typedef vector<string> StrVec;
typedef vector<int> IntVec;
typedef set<int> IntSet;

struct Ticket {
	bool rt[8][8];
	Ticket() {
		memset(rt, 0, sizeof(rt));
	}
};

class Solver {
	int N;
	int M;
	StrVec zip;
	IntSet path[8];
	IntVec seq;

	bool dfs(int current, int next_index, Ticket ticket)
	{
		int next = seq[next_index];
		if (path[current].find(next) != path[current].end()) {
			if (next_index >= (N - 1)) {
				return true;
			}
			ticket.rt[next][current] = true;
			return dfs(next, next_index + 1, ticket);
		}
		for (int i = 0; i < N; ++i) {
			if (ticket.rt[current][i]) {
				ticket.rt[current][i] = false;
				if (dfs(i, next_index, ticket)) {
					return true;
				}
				ticket.rt[current][i] = true;
			}
		}
		return false;
	}

public:
	string solve(void)
	{
		N = 0, M = 0;
		string s;
		getline(cin, s);
		{
			stringstream ss(s);
			ss >> N >> M;
		}

		zip.clear();
		for (int i = 0; i < N; ++i) {
			getline(cin, s);
			zip.push_back(s);
		}
		for (int i = 0; i < M; ++i) {
			getline(cin, s);
			stringstream ss(s);
			int a = 0, b = 0;
			ss >> a >> b;
			--a, --b;
			path[a].insert(b);
			path[b].insert(a);
		}

		if (N <= 1) {
			return zip[0];
		}

		string ans;

		seq.resize(N);
		for (int i = 0; i < N; ++i) {
			seq[i] = i;
		}
		do {
			if (dfs(seq[0], 1, Ticket())) {
				string s;
				for (int i = 0; i < N; ++i) {
					s += zip[seq[i]];
				}
				if (ans.empty() || s < ans) {
					ans = s;
				}
			}
		} while (next_permutation(seq.begin(), seq.end()));

		return ans;
	}
};

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		Solver s;
		string ans = s.solve();
		printf("Case #%d: %s\n", t, ans.c_str());
	}

	return 0;
}

