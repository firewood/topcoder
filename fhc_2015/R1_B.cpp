//
// Facebook Hacker Cup 2015 Round 1
// B. Autocomplete
//

/*
Constraints

1 <= T <= 100
1 <= N <= 100,000
The N words will have a total length of no more than 1,000,000 characters.
The words are made up of only lower-case alphabetic characters.
The words are pairwise distinct.

NOTE: The input file is about 10-20MB.
*/


#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

typedef map<int, int> IntMap;

#ifdef _DEBUG
static const int pool_size = 100000;
#else
static const int pool_size = 12000000;
#endif

static IntMap pool[pool_size];

class Solver {
	vector<string> v;
	int pi;
	int cnt;

public:
	Solver(const vector<string> &iv) : v(iv), pi(0), cnt(0) {
		for (int i = 0; i < pool_size; ++i) {
			pool[i].clear();
		}
	}
	void type(const char *s) {
		int parent = 0;
		int u, l = -1;
		while (l != 0 && *s) {
			u = *s++ * 256;
			l = *s++;
			IntMap &m = pool[parent];

			IntMap::const_iterator f = m.find(u + l);
			if (f != m.end()) {
				cnt += (1 + (l != 0));
				parent = f->second;
				continue;
			}

			IntMap::const_iterator a = m.lower_bound(u);
			int b = -1;
			if (a != m.end()) {
				b = a->first & ~255;
			}
			if (u != b) {
				++cnt;
			} else {
				cnt += (1 + (l != 0));
			}
			m[u + l] = ++pi;
			while (l != 0 && *s) {
				if (pi >= pool_size - 1) {
					cout << "OVERFLOW" << endl;
					exit(-1);
				}
				u = *s++ * 256;
				l = *s++;
				parent = pi;
				pool[parent][u + l] = ++pi;
			}
			return;
		}
	}
	int solve(void) {
		for (int i = 0; i < (int)v.size(); ++i) {
			type(v[i].c_str());
		}
		return cnt;
	}
};

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		int N = atoi(s.c_str());
		vector<string> v(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, v[i]);
		}
		Solver solver(v);
		int ans = solver.solve();
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}
	return 0;
}
