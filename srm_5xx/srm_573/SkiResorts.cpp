// BEGIN CUT HERE
/*
SRM 573 Div1 Medium (450)

問題
-スキーリゾートに場所0から場所N-1までのN個の場所がある
-同じ高さか、より低い場所へのみ移動できる
-任意の場所を工事して高さを変更できる
-場所0からスタートして場所N-1に行けるようにするための最小のコストを求める

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;
typedef pair<LL, II> LII;
typedef priority_queue<LII> LIIQueue;
typedef vector<int> IntVec;

class SkiResorts {

public:
	long long minCost(vector <string> road, vector <int> altitude) {
		int sz = (int)road.size();

		// generate alt table
		IntVec alt = altitude;
		sort(alt.begin(), alt.end());
		unique(alt.begin(), alt.end());

		LL mincost[64][64];
		memset(mincost, 0x3f, sizeof(mincost));

		LIIQueue q;
		int i, j;
		for (i = 0; i < (int)alt.size(); ++i) {
			LL cost = abs(alt[i] - altitude[0]);
			mincost[0][i] = cost;
			q.push(LII(-cost, II(0, alt[i])));
		}

		// dijkstra
		while (q.size() > 0) {
			LII current = q.top();
			q.pop();
			int from = current.second.first;
			if (from == (sz-1)) {
				return -current.first;
			}
			for (i = 0; i < (int)alt.size(); ++i) {
				if (alt[i] > current.second.second) {
					break;
				}
				for (j = 0; j < sz; ++j) {
					if (road[from][j] == 'Y') {
						LL cost = -current.first + abs(alt[i] - altitude[j]);
						if (cost < mincost[j][i]) {
							mincost[j][i] = cost;
							q.push(LII(-cost, II(j, alt[i])));
						}
					}
				}
			}
		}

		return -1;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYN",
 "YNY",
 "NYN"};
			int Arr1[] = {30, 20, 10};
			long long Arg2 = 0LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minCost(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NY",
 "YN"};
			int Arr1[] = {10, 20};
			long long Arg2 = 10LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minCost(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYN",
 "YNN",
 "NNN"};
			int Arr1[] = {573, 573, 573};
			long long Arg2 = -1LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minCost(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"};
			int Arr1[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
			long long Arg2 = 12LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minCost(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SkiResorts ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
