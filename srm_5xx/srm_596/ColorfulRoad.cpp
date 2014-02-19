// BEGIN CUT HERE
/*
SRM 596 Div2 Medium (500)

問題
-RかGかBの升目がある
-R→G→Bの順に進まなければならない
-移動コストは距離の二乗
-左端から右端に移動するコストの合計の最小値を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ColorfulRoad {
public:
	int getMin(string road) {
		int cost[20] = {};
		int next[256] = {};
		next['R'] = 'G';
		next['G'] = 'B';
		next['B'] = 'R';
		for (int i = 1; i < (int)road.length(); ++i) {
			cost[i] = 99999999;
		}
		cost[0] = 0;
		for (int i = 1; i < (int)road.length(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (next[road[j]] == road[i]) {
					cost[i] = min(cost[i], cost[j] + (i-j)*(i-j));
				}
			}
		}
		if (cost[road.length()-1] >= 99999999) {
			return -1;
		}
		return cost[road.length()-1];
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
			string Arg0 = "RGGGB";
			int Arg1 = 8;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RGBRGBRGB";
			int Arg1 = 8;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RBBGGGRR";
			int Arg1 = -1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RBRRBGGGBBBBR";
			int Arg1 = 50;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RG";
			int Arg1 = 1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RBRGBGBGGBGRGGG";
			int Arg1 = 52;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ColorfulRoad ___test;
	___test.run_test(-1);
}
// END CUT HERE
