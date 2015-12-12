// BEGIN CUT HERE
/*
SRM 675 Div2 Medium (500)

PROBLEM STATEMENT
There are n cities, numbered from 0 to n-1.
It is possible to travel directly between any two cities.
Different pairs of cities may require different travel times.
You are given the travel times as a vector <string> dist with n elements, each consisting of n digits.
The digit dist[i][j] represents the time needed to travel between cities i and j in either direction.

You are also given an int k.
You have k magic potions.
The potion makes you twice as fast as you normally are.
Each time you travel (directly) from some city to some other city, you may take one of the potions.
If you do, that travel will only take half of what it normally would.
You are not allowed to take more than one potion at the same time.
You are not required to drink all potions you have.

Compute and return the smallest amount of time in which you can travel from city 0 to city 1.


DEFINITION
Class:ShortestPathWithMagic
Method:getTime
Parameters:vector <string>, int
Returns:double
Method signature:double getTime(vector <string> dist, int k)


NOTES
-The travel times given in dist don't have to satisfy the triangle inequality.
-Your return value must have a relative or absolute error less than 1e-9


CONSTRAINTS
-dist will contain between 2 and 50 elements, inclusive.
-Each string in dist will contain exactly |dist| characters.
-Each character in dist will be between '0' and '9', inclusive.
-For any valid i and j: dist[i][j] = dist[j][i].
-For any valid i: dist[i][i] = 0.
-k will be between 0 and 50, inclusive.


EXAMPLES

0)
{"094",
 "904",
 "440"}
1

Returns: 4.5

According to dist, you need:

9 units of time to travel between cities 0 and 1
4 units of time to travel between cities 0 and 2
4 units of time to travel between cities 1 and 2


You have a single magic potion.
The optimal solution is to drink the potion and to travel directly from city 0 to city 1.
This trip will take 9/2 = 4.5 units of time.


1)
{"094",
 "904",
 "440"}
2

Returns: 4.0

The normal travel times are the same as in Example 0, but now you have two magic potions.
This changes the optimal solution.
Now it is better to travel from 0 to 2 and then from 2 to 1.
For each segment of your trip you will drink one of the potions.
Thus, each segment will only take 4/2 = 2 units of time.


2)
{"094",
 "904",
 "440"}
50

Returns: 4.0

You are not allowed to use more than one potion at the same time.
The optimal solution remains the same as in Example 1, only now you will still have 48 magic potions when you reach city 1.


3)
{"094",
 "904",
 "440"}
0

Returns: 8.0


4)
{"076237",
 "708937",
 "680641",
 "296059",
 "334508",
 "771980"}
1

Returns: 3.5


5)
{"00",
 "00"}
50

Returns: 0.0

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
