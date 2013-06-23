// BEGIN CUT HERE
/*
SRM 582 Div1 Easy (250)

問題
-何人かの魔法少女と、それぞれの強さが与えられる
-何種類かのエイリアンと、その強さと数が与えられる
-魔法少女は、自分の強さ以下の敵は倒せる
-敵を1匹倒すごとに魔法少女の疲労が1増える
-疲労の最大値を最小化せよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef map<int, LL> ILLMap;

class SpaceWarDiv1 {

	IntVec g;
	ILLMap e;

	bool can(LL n) {
		int i = 0;
		LLVec t(g.size());
		ILLMap::const_iterator it;
		for (it = e.begin(); it != e.end(); ++it) {
			LL r = it->second;
			while (r > 0) {
				LL c = min(r, n - t[i]);
				if (g[i] < it->first || c <= 0) {
					++i;
					if (i >= (int)g.size()) {
						return false;
					}
					continue;
				}
				r -= c;
				t[i] += c;
			}
		}
		return true;
	}

public:
	long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount) {
		g = magicalGirlStrength;
		sort(g.begin(), g.end());
		e.clear();
		for (int i = 0; i < (int)enemyStrength.size(); ++i) {
			e[enemyStrength[i]] += enemyCount[i];
		}
		LL low = -1, high = 1LL<<62;
		while (low < high) {
			LL mid = (low + high) / 2;
			if (can(mid)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return low < (1LL<<62) ? low : -1;
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
			int Arr0[] = {2, 3, 5};
			int Arr1[] = {1, 3, 4};
			long Arr2[] = {2, 9, 4};
			long long Arg3 = 7LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minimalFatigue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 3, 5};
			int Arr1[] = {1, 1, 2};
			long Arr2[] = {2, 9, 4};
			long long Arg3 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minimalFatigue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {14, 6, 22};
			int Arr1[] = {8, 33};
			long Arr2[] = {9, 1};
			long long Arg3 = -1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minimalFatigue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417};
			int Arr1[] = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307};
			LL Arr2[] = {20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
 61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
 78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296};
			long long Arg3 = 75030497287405LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minimalFatigue(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SpaceWarDiv1 ___test;
	___test.run_test(0);
	___test.run_test(-1);
}
// END CUT HERE
