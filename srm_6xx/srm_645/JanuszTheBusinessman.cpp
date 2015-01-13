// BEGIN CUT HERE
/*
SRM 645 Div1 Easy (250)

PROBLEM STATEMENT
Janusz owns a hotel.
He has already received some reservations for the upcoming year.
The days in the year are numbered 1 through 365.
For each valid i, there is a guest who will arrive on day arrivals[i] and depart on day departures[i].

Janusz can give some guests a special promotion.
Any guest that gets the special promotion will leave a good review.
Additionally, all guests that meet a guest with promotion will also leave a good review.
(Here we assume that two guests meet if and only if they are in the hotel on the same day, including the situation when one of them departs on the same day the other one arrives.)

Janusz wants to make sure that all his guests leave good reviews.
You are given the vector <int>s arrivals and departures.
Return the smallest possible number of special promotions sufficient to make sure that all guests leave good reviews.


DEFINITION
Class:JanuszTheBusinessman
Method:makeGuestsReturn
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int makeGuestsReturn(vector <int> arrivals, vector <int> departures)


CONSTRAINTS
-arrivals and departures will have the same number of elements.
-arrivals will have between 2 and 50 elements, inclusive.
-Each element of arrivals and departures will be between 1 and 365, inclusive.
-For each valid i arrivals[i] will be less than departures[i].


EXAMPLES

0)
{2, 10, 6}	
{6, 11, 9}

Returns: 2

One promotion is not enough.
One optimal solution is to give promotions to the guest who arrives on day 2 and to the guest who arrives on day 10.
The third guest will meet the first guest on day 6.


1)
{2, 10, 23, 34, 45, 123, 1}
{25, 12, 40, 50, 48, 187, 365}

Returns: 1

One guest is going to stay for the whole season so Janusz can give the promotion only to him.


2)
{8, 12, 20, 30, 54, 54, 68, 75}
{13, 31, 30, 53, 55, 70, 80, 76}

Returns: 3


3)
{124, 328, 135, 234, 347, 124, 39, 99, 116, 148}
{237, 335, 146, 246, 353, 213, 197, 215, 334, 223}

Returns: 2


4)
{154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6}
{159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13}

Returns: 14

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class JanuszTheBusinessman {
public:

	int makeGuestsReturn(vector <int> arrivals, vector <int> departures) {
		int used[64] = {};
		int N = (int)arrivals.size();
		int ans = 0;
		while (true) {
			int left = 1000;
			for (int i = 0; i < N; ++i) {
				if (!used[i]) {
					left = min(left, departures[i]);
				}
			}
			if (left >= 1000) {
				break;
			}
			++ans;
			int right = left;
			for (int i = 0; i < N; ++i) {
				if (arrivals[i] <= left) {
					right = max(right, departures[i]);
				}
			}
			for (int i = 0; i < N; ++i) {
				if (arrivals[i] <= right) {
					used[i] = 1;
				}
			}
		}
		return ans;
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
			int Arr0[] = {2, 10, 6}	;
			int Arr1[] = {6, 11, 9};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 10, 23, 34, 45, 123, 1};
			int Arr1[] = {25, 12, 40, 50, 48, 187, 365};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 12, 20, 30, 54, 54, 68, 75};
			int Arr1[] = {13, 31, 30, 53, 55, 70, 80, 76};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148};
			int Arr1[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6};
			int Arr1[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13};
			int Arg2 = 14;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	JanuszTheBusinessman ___test;
	___test.run_test(-1);
}
// END CUT HERE
