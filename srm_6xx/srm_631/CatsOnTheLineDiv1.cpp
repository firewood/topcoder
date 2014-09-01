// BEGIN CUT HERE
/*
SRM 631 Div1 Medium (500)

PROBLEM STATEMENT

There are some cats sitting on a straight line that goes from the left to the right.
You are given two vector <int>s position and count.
For each valid i, there are count[i] cats initially sitting at the point position[i].

During each minute, each cat chooses and performs one of three possible actions: it may stay in its place, move one unit to the left (i.e., from x to x-1), or move one unit to the right (i.e., from x to x+1).
(Note that there are no restrictions. In particular, different cats that are currently at the same point may make different choices.)

You are also given an int time.
Cats don't like to sit together with other cats, so they want to minimize the number of points that contain two or more cats after time minutes.
Return this minimum number.


DEFINITION
Class:CatsOnTheLineDiv1
Method:getNumber
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int getNumber(vector <int> position, vector <int> count, int time)


CONSTRAINTS
-position will contain between 1 and 1,000 elements, inclusive.
-position and count will contain the same number of elements.
-Each element of position will be between -100,000,000 and 100,000,000, inclusive.
-Each element of position will be distinct.
-Each element of count will be between 1 and 100,000,000, inclusive.
-time will be between 0 and 100,000,000, inclusive.


EXAMPLES

0)
{0}
{7}
3

Returns: 0

In this case, there are initially 7 cats at the origin. Each of the cats can go to a separate point. They will occupy all integer points from -3 to 3, inclusive. Thus, the answer is 0.


1)
{0}
{6}
2

Returns: 1

In this case, there will always be at least one point with more than one cat. One of the best strategies for the cats is to not move at all. This strategy will lead to the answer equal to 1.


2)
{4, 7, 47}
{4, 7, 4}
1

Returns: 3


3)
{3, 0, 7, 10}
{3, 7, 4, 5}
2

Returns: 2


4)
{-5, 0, 7}
{47, 85, 10}
6

Returns: 1


5)
{-8, 12, -15, -20, 17, -5, 7, 10}
{20, 10, 7, 9, 2, 8, 11, 10}
2

Returns: 5

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
typedef vector<II> IIVec;

class CatsOnTheLineDiv1 {
public:
	int getNumber(vector <int> position, vector <int> count, int time) {
		int N = (int)position.size();
		IIVec v;
		for (int i = 0; i < N; ++i) {
			v.push_back(II(position[i], count[i]));
		}
		sort(v.begin(), v.end());

		int ans = 0;
		LL prev = -1LL << 60;
		LL merged = -1LL << 60;
		for (int i = 0; i < N; ++i) {
			LL left = v[i].first - time;
			if (left <= merged) {
				continue;
			}
			left = max(prev + 1, left);
			LL right = left + v[i].second - 1;
			if (right <= v[i].first + time) {
				prev = right;
			} else {
				++ans;
				merged = v[i].first + time;		// rightmost
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
			int Arr0[] = {0};
			int Arr1[] = {7};
			int Arg2 = 3;
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {6};
			int Arg2 = 2;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 7, 47};
			int Arr1[] = {4, 7, 4};
			int Arg2 = 1;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 0, 7, 10};
			int Arr1[] = {3, 7, 4, 5};
			int Arg2 = 2;
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-5, 0, 7};
			int Arr1[] = {47, 85, 10};
			int Arg2 = 6;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-8, 12, -15, -20, 17, -5, 7, 10};
			int Arr1[] = {20, 10, 7, 9, 2, 8, 11, 10};
			int Arg2 = 2;
			int Arg3 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 5,5,5 };
			int Arr1[] = { 5,5,5 };
			int Arg2 = 1;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 527, -279, -793, 900, 637, 542, 1, 826, 201, 877, -968, 88, 815, 618, -195, -982, -976, -335, 915, -288, -778, -432, 340, -482, -56, -22, 300, -930, 562, -276, -792, 510, 281, 352, 341, -617, 87, -42, -143, 13, -783, 839, 454, 356, 760, -473, -898, -481, 282, -269 };
			int Arr1[] = { 750, 871, 338, 234, 714, 647, 1185, 249, 1154, 445, 211, 773, 973, 391, 911, 323, 510, 684, 296, 525, 149, 684, 1169, 142, 170, 1005, 561, 46, 845, 176, 510, 764, 228, 332, 538, 821, 1279, 321, 1263, 1101, 723, 814, 557, 1114, 729, 862, 437, 1195, 1050, 279 };
			int Arg2 = 824;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CatsOnTheLineDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
