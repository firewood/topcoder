// BEGIN CUT HERE
/*
SRM 795 Div1 Easy (300)

PROBLEM STATEMENT

There are N cities, numbered from 0 to N-1.
For each ordered pair of cities (u, v) you know the cost costs[u][v] of flying directly from u to v.
Each such flight takes one day.
Flight costs are not necessarily symmetric.


Suppose you are in city u and you want to get to city v.
You would like to use this opportunity to obtain a frequent flyer status.
In order to get the status, you have to travel on at least minDays consecutive days.
What is the minimum total cost c(u, v) of a flight schedule that gets you from u to v in minDays or more days?


Return the sum of all N*N values c(u, v).
Note that this includes trips that start and end in the same city.


DEFINITION
Class:AtLeastKDays
Method:sumOfMinCosts
Parameters:vector <string>, int
Returns:long long
Method signature:long long sumOfMinCosts(vector <string> costs, int minDays)


NOTES
-The diagonal of the array costs contains the character '-' denoting that staying in a city is not a valid form of traveling.
-Digits in costs represent the corresponding numerical values. For example, if costs[4][7] = '3', the flight from 4 to 7 has cost 3.


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-costs will contain exactly N elements.
-Each element of costs will contain exactly N characters.
-For each u, costs[u][u] will be '-'.
-Each other character in costs will be between '1' and '9', inclusive.
-minDays will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{"-12",
 "3-6",
 "45-"}
1

Returns: 34


We are traveling for at least one day.


For some pairs of cities the optimal solution is to take the direct flight and stop.
These are c(0,1) = 1, c(0,2) = 2, c(1,0) = 3, c(2,0) = 4, and c(2,1) = 5.


If we have to start and end in the same city, we need to fly for at least two days.
The optimal travel costs for these cases are c(0,0) = c(1,1) = 4 and c(2,2) = 6.


This leaves us with travel from 1 to 2. There is a direct flight that costs 6, but also a cheaper option: to fly from 1 to 0 and then from 0 to 2, paying only 3+2 = 5.
Thus, c(1,2) = 5.


The returned value is the sum of all c(u,v): 4+1+2+3+4+5+4+5+6 = 34.


1)
{"-111111111",
 "1-11111111",
 "11-1111111",
 "111-111111",
 "1111-11111",
 "11111-1111",
 "111111-111",
 "1111111-11",
 "11111111-1",
 "111111111-"}
1000000000

Returns: 100000000000

For each of the 10*10 pairs of vertices we can get from u to v in exactly 10^9 days while paying 1 for each ticket. Thus, each c(u, v) is 10^9 and therefore the final answer is 10^11.

2)
{"-12",
 "3-6",
 "45-"}
6

Returns: 122


The same costs as in example 0, but now we are traveling for at least 6 days.


One of the things worth noting is that c(0,1) = 13.
The optimal way of traveling from 0 to 1 in at least 6 days is to travel in 7 days, alternating between cities 0 and 1 the whole time.


Another thing worth noting is that c(0,2) = 14.
Again, optimal travel involves seven days, in which we travel as follows: 0-1-0-1-0-1-0-2.



*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

const LL INF = 1LL << 60;

struct Matrix {
	LL _n;
	LL e[50][50];
	Matrix(LL n) {
		_n = n;
		memset(e, 0x3f, sizeof(e));
	}
	Matrix mul(const Matrix& a) {
		Matrix r(_n);
		for (LL i = 0; i < _n; ++i) {
			for (LL j = 0; j < _n; ++j) {
				for (LL k = 0; k < _n; ++k) {
					r.e[i][j] = min(r.e[i][j], e[i][k] + a.e[k][j]);
				}
			}
		}
		return r;
	}
	Matrix pow(LL x) {
		Matrix r(_n), b = *this;
		for (LL i = 0; i < _n; ++i) {
			r.e[i][i] = 0;
		}
		for (; x > 0; x >>= 1) {
			if (x & 1) {
				r = r.mul(b);
			}
			b = b.mul(b);
		}
		return r;
	}
};

class AtLeastKDays {
public:
	long long sumOfMinCosts(vector <string> costs, int minDays) {
		LL n = costs.size();
		Matrix m(n);
		for (LL i = 0; i < n; ++i) {
			for (LL j = 0; j < n; ++j) {
				m.e[i][j] = i == j ? INF : (costs[i][j] - '0');
			}
		}
		Matrix t = m.pow(minDays);
		for (LL k = 0; k < n; ++k) {
			for (LL i = 0; i < n; ++i) {
				for (LL j = 0; j < n; ++j) {
					m.e[i][j] = min(m.e[i][j], m.e[i][k] + m.e[k][j]);
				}
			}
		}
		LL ans = 0;
		for (LL i = 0; i < n; ++i) {
			for (LL j = 0; j < n; ++j) {
				LL cost = t.e[i][j];
				for (LL k = 0; k < n; ++k) {
					cost = min(cost, t.e[i][k] + m.e[k][j]);
				}
				ans += cost;
			}
		}
		return ans;
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
			string Arr0[] = {"-12",
 "3-6",
 "45-"};
			int Arg1 = 1;
			long long Arg2 = 34LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, sumOfMinCosts(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"-111111111",
 "1-11111111",
 "11-1111111",
 "111-111111",
 "1111-11111",
 "11111-1111",
 "111111-111",
 "1111111-11",
 "11111111-1",
 "111111111-"};
			int Arg1 = 1000000000;
			long long Arg2 = 100000000000LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, sumOfMinCosts(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"-12",
 "3-6",
 "45-"};
			int Arg1 = 6;
			long long Arg2 = 122LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, sumOfMinCosts(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
 "-234529",
 "3-23461",
 "61-5976",
 "926-944",
 "1341-34",
 "92452-4",
 "449596-",
};
			int Arg1 = 100;
			long long Arg2 = 7441;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, sumOfMinCosts(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AtLeastKDays ___test;
	___test.run_test(-1);
}
// END CUT HERE
