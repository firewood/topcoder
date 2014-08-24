// BEGIN CUT HERE
/*
SRM 629 Div1 Medium (500)

PROBLEM STATEMENT

Alice likes eating candies.
Her favorite type of candy are the Surprise Candies.
Surprise Candies come in N different flavors and in N different shapes.
You know the following facts about the shapes and flavors of Surprise Candies:

The shapes are numbered 0 through N-1.
The flavors are numbered 0 through N-1.
You can tell the shape of a candy before buying it. (Thus, you can do stuff like "buy exactly 47 candies of shape 3".)
You can only tell the flavor of a candy when eating it. (Thus, you do not know the flavor when you are buying the candy.)
For each shape of Surprise Candies, there are exactly two flavors that can have that shape.
For each flavor of Surprise Candies, there are exactly two shapes that can have that flavor.

In Alice's street there is a store that sells Surprise Candies.
Alice knows the exact inventory of this store.
You are given this information in vector <int>s Type1, Number1, Type2, and Number2.
Each of these vector <int>s has exactly N elements.
For each i, their elements at index i correspond to the shape number i, as follows:

The store contains exactly Number1[i] candies with shape i and flavor Type1[i].
The store contains exactly Number2[i] candies with shape i and flavor Type2[i].

Alice wants to eat candies of all N flavors today.
However, she is lazy to go to the store, so she sent Kirito to do the shopping for her.
Kirito must buy a set of candies that is guaranteed to contain all N flavors.
Return the smallest number of candies Kirito may buy.


DEFINITION
Class:CandyCollection
Method:solve
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2)


CONSTRAINTS
-N will between 1 and 1000, inclusive.
-Type1, Number1, Type2, Number2 will each contain exactly N elements.
-For each i, Type1[i] and Types2[i] will be different.
-Each element of Type1 and Type2 will be between 0 and N-1, inclusive.
-Each element of Number1 and Number2 will be between 1 and 1000, inclusive.
-Each of the values 0 through N-1 will appear exactly twice in Type1 and Type2 together.


EXAMPLES

0)
{0,0}
{1,1}
{1,1}
{1,1}

Returns: 2

In this test case we have N=2.
Thus, there are two shapes and two flavors.
The store has exactly one candy for each combination (shape,flavor).
Kirito can simply buy two candies with the same shape, their flavors must be different.


1)
{0,0}
{2,5}
{1,1}
{2,5}

Returns: 3

In this test case we have N=2 again, but now the supply of candies in the store is larger.
There are 2+2 = 4 candies of shape 0, and 5+5 = 10 candies of shape 1.
The optimal strategy for Kirito is to buy 3 candies of shape 0.
Both flavors have to be present in those three candies.


2)
{0,0,2,3}
{1,1,2,2}
{1,1,3,2}
{1,1,2,2}

Returns: 5

One optimal solution is to buy two candies of shape 0 and three candies of shape 2.


3)
{0,1,2,3}
{5,5,10,13}
{1,2,3,0}
{8,8,10,15}

Returns: 20


4)
{12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13}
{895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530}
{1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16}
{779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394}

Returns: 5101

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class CandyCollection {
public:
	int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2) {
		int TypeToIndex[1000][2];
		memset(TypeToIndex, -1, sizeof(TypeToIndex));
		int N = (int)Type1.size();
		for (int i = 0; i < N; ++i) {
			bool f = TypeToIndex[Type1[i]][0] < 0;
			TypeToIndex[Type1[i]][!f] = i;
			f = TypeToIndex[Type2[i]][0] < 0;
			TypeToIndex[Type2[i]][!f] = i;
		}

		int ans = 0;

		bool vis[1000] = {};
		for (int i = 0; i < N; ++i) {
			if (!vis[i]) {
				vis[i] = true;
				int start_type = Type1[i];
				int current_type = Type2[i];

				int dp[2][2][2] = {};
				dp[0][0][1] = Number1[i] + 1;
				dp[0][1][0] = Number2[i] + 1;
				dp[0][1][1] = max(dp[0][0][1], dp[0][1][0]);
				int r = 0, w = 1;

				while (current_type != start_type) {
					int j = TypeToIndex[current_type][0];
					if (vis[j]) {
						j = TypeToIndex[current_type][1];
					}
					vis[j] = true;

					bool f = Type1[j] == current_type;
					int a = f ? (Number2[j] + 1) : (Number1[j] + 1);
					int b = f ? (Number1[j] + 1) : (Number2[j] + 1);

					for (int k = 0; k < 2; ++k) {
						dp[w][k][0] = min(dp[r][k][0] + a, dp[r][k][1]);
						dp[w][k][1] = min(dp[r][k][0] + max(a, b), dp[r][k][1] + b);
					}

					current_type = f ? Type2[j] : Type1[j];
					r ^= 1, w ^= 1;
				}

				ans += min(dp[r][0][1], dp[r][1][0]);
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
			int Arr0[] = {0,0};
			int Arr1[] = {1,1};
			int Arr2[] = {1,1};
			int Arr3[] = {1,1};
			int Arg4 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0};
			int Arr1[] = {2,5};
			int Arr2[] = {1,1};
			int Arr3[] = {2,5};
			int Arg4 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,2,3};
			int Arr1[] = {1,1,2,2};
			int Arr2[] = {1,1,3,2};
			int Arr3[] = {1,1,2,2};
			int Arg4 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3};
			int Arr1[] = {5,5,10,13};
			int Arr2[] = {1,2,3,0};
			int Arr3[] = {8,8,10,15};
			int Arg4 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13};
			int Arr1[] = {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530};
			int Arr2[] = {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16};
			int Arr3[] = {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394};
			int Arg4 = 5101;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CandyCollection ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
