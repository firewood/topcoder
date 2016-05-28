// BEGIN CUT HERE
/*
SRM 675 Div2 Medium (500)

問題
-0～N-1までのN個の都市があり、都市間の移動コストが与えられる
-k個の魔法の薬があり、使うと移動コストが半分になる
-都市0から都市1への移動コストの最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef pair<double, II> DII;
typedef priority_queue<DII> Queue;

class ShortestPathWithMagic {
public:
	double getTime(vector <string> dist, int k) {
		int N = dist.size();
		k = min(10, min(k, N));

		double mc[50][50];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				mc[i][j] = -1e9;
			}
			mc[0][i] = 0;
		}

		Queue q;
		q.push(DII(0, II(0, k)));
		double ans = 0;
		while (q.size() > 0) {
			double cost = q.top().first;
			int n = q.top().second.first;
			int r = q.top().second.second;
			q.pop();
			if (n == 1) {
				ans = -cost;
				break;
			}
			for (int i = 0; i < N; ++i) {
				if (i != n) {
					double c = cost - (dist[n][i] - '0');
					if (c > mc[i][r]) {
						mc[i][r] = c;
						q.push(DII(c, II(i, r)));
					}
					if (r > 0) {
						c = cost - (dist[n][i] - '0') * 0.5;
						if (c > mc[i][r - 1]) {
							mc[i][r - 1] = c;
							q.push(DII(c, II(i, r - 1)));
						}
					}
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"094",
 "904",
 "440"};
			int Arg1 = 1;
			double Arg2 = 4.5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"094",
 "904",
 "440"};
			int Arg1 = 2;
			double Arg2 = 4.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"094",
 "904",
 "440"};
			int Arg1 = 50;
			double Arg2 = 4.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getTime(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"094",
 "904",
 "440"};
			int Arg1 = 0;
			double Arg2 = 8.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getTime(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"076237",
 "708937",
 "680641",
 "296059",
 "334508",
 "771980"};
			int Arg1 = 1;
			double Arg2 = 3.5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getTime(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"00",
 "00"};
			int Arg1 = 50;
			double Arg2 = 0.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "056998476599558689478", "502146030849262764588", "620919995209221769820", "919068146420804527896", "941603087557165394341", "869830545472333706527", "409105017021051001804", "739484109955552943666", "605675790163957329686", "582454091057902124824", "940257256505081454287", "999072153750950319670", "522813059909040388597", "562063555085404884572", "821453127210040383225", "677537093143383039138", "866290042251888301056", "949746139449843910876", "458835866826552108015", "782942068287972357107", "880617466470725866570" };
			int Arg1 = 9;
			double Arg2 = 2.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getTime(Arg0, Arg1));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ShortestPathWithMagic ___test;
	___test.run_test(-1);
}
// END CUT HERE
