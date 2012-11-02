// BEGIN CUT HERE
/*
// SRM 557 Div1 Medium (550)

問題
インキュベーターが少女と契約する。
少女は契約すると魔法少女となり、自分が守りたい少女を守る。
誰かに守られた少女もまた、自分が守りたい少女を守る。
守られていない魔法少女の最大人数を求める。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class Incubator {

	// From The Programming Contest Challendge Book
	IntVec G[100];
	int match[100];
	bool used[100];

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bool dfs(int v) {
		used[v] = true;
		int i;
		for (i = 0; i < (int)G[v].size(); ++i) {
			int u = G[v][i];
			int w = match[u];
			if (w < 0 || !used[w] && dfs(w)) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

public:
	int maxMagicalGirls(vector <string> love) {
		int sz = (int)love.size();

		// Warshall-Floyd Algorithm
		int p[50][50] = {};
		int i, j, k;
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < sz; ++j) {
				p[i][j] = love[i][j] == 'Y';
			}
		}
		for (k = 0; k < sz; ++k) {
			for (i = 0; i < sz; ++i) {
				for (j = 0; j < sz; ++j) {
					p[i][j] |= p[i][k] & p[k][j];
				}
			}
		}

		// Bipartite Matching
		for (i = 0; i < 100; ++i) {
			G[i].clear();
		}
		memset(match, -1, sizeof(match));
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < sz; ++j) {
				if (p[i][j]) {
					add_edge(i, 50+j);
				}
			}
		}
		int cnt = 0;
		for (i = 0; i < sz; ++i) {
			if (match[i] < 0) {
				memset(used, 0, sizeof(used));
				cnt += dfs(i);
			}
		}

		return sz - cnt;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NY","NN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYN", "NNY", "NNN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Y"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Incubator ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
