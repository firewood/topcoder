// BEGIN CUT HERE
/*
SRM 680 Div1 Easy (250)

PROBLEM STATEMENT

Limak is a grizzly bear.
He is big and dreadful.
You were chilling in the forest when you suddenly met him.
It's very unfortunate for you.
He will eat all your cookies unless you can demonstrate your mathematical skills.
To test you, Limak is going to give you a puzzle to solve.

It's a well-known fact that Limak, as every bear, owns a set of numbers.
You know some information about the set:

The elements of the set are distinct positive integers.
The number of elements in the set is n. The number n is even.
All elements are between 1 and b, inclusive: bears don't know numbers greater than b.
The set contains exactly n/2 even elements and exactly n/2 odd elements, because grizzly bears only like sets with this property.

Limak smiles mysteriously and gives you q hints about his set.
The hints are numbered 0 through q-1.
For each valid i, the hint number i is the following sentence:
"If you only look at elements that are between 1 and upTo[i], inclusive, you will find exactly quantity[i] such elements in my set."

In a moment Limak will tell you the actual puzzle, but something doesn't seem right...
That smile was very strange.
You start to think about a possible reason.
Maybe Limak cheated you?
Or is he a fair grizzly bear?

You are given the ints n and b.
You are also given the vector <int>s upTo and quantity.
Return "fair" (quotes for clarity) if there exists at least one set that has all the required properties and matches all the given hints.
Otherwise, return "unfair".


DEFINITION
Class:BearFair
Method:isFair
Parameters:int, int, vector <int>, vector <int>
Returns:string
Method signature:string isFair(int n, int b, vector <int> upTo, vector <int> quantity)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-n will be even.
-b will be between n and 1000, inclusive.
-q will be between 1 and 50, inclusive.
-upTo will have exactly q elements.
-quantity will have exactly q elements.
-Each element in upTo will be between 1 and b, inclusive.
-Each element in quantity will be between 0 and n, inclusive.


EXAMPLES

0)
4
6
{3,6}
{2,4}

Returns: "fair"

Limak is a fair bear. Some sets that match his hints are {1,3,4,6} and {1,2,4,5}.


1)
4
6
{3,6}
{2,3}

Returns: "unfair"

The second hint is that exactly 3 elements are between 1 and 6 (inclusive).
But there should be 4 elements in total, all between 1 and 6 (inclusive).
In this situation Limak is clearly being unfair, there is no set that matches these hints.


2)
2
6
{1,2,3}
{1,1,2}

Returns: "unfair"

The only set that matches the hints is the set {1,3}. However, this set violates the constraint that the number of odd elements must be n/2.


3)
50
1000
{736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,
186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357}
{35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16}

Returns: "fair"


4)
4
1000
{400,600}
{4,0}

Returns: "unfair"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;


class BearFair {
public:
	bool check(int n, int b, vector <int> &upTo, vector <int> &quantity) {
		IIVec v(1, II(0,0));
		for (int i = 0; i != upTo.size(); ++i) {
			v.push_back(II(upTo[i], quantity[i]));
		}
		v.push_back(II(b, n));
		sort(v.begin(), v.end());
		int cnt[2] = {};
		for (int i = 1; i != v.size(); ++i) {
			int last_u = v[i - 1].first, u = v[i].first;
			int last_q = v[i - 1].second, q = v[i].second;
			int d = q - last_q;
			if (last_u == u) {
				if (last_q != q) {
					return false;
				}
				continue;
			}
			if (d < 0 || (u - last_u) < d) {
				return false;
			}
			int t[2] = {};
			for (int j = last_u + 1; j <= u; ++j) {
				t[j % 2] += 1;
			}
			cnt[0] += min(t[0], d);
			cnt[1] += min(t[1], d);
		}
		return cnt[0] >= n / 2 && cnt[1] >= n / 2;
	}

	string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
		return check(n, b, upTo, quantity) ? "fair" : "unfair";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arr2[] = {3,6};
			int Arr3[] = {2,4};
			string Arg4 = "fair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arr2[] = {3,6};
			int Arr3[] = {2,3};
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 6;
			int Arr2[] = {1,2,3};
			int Arr3[] = {1,1,2};
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 1000;
			int Arr2[] = {736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,
186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357};
			int Arr3[] = {35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16};
			string Arg4 = "fair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1000;
			int Arr2[] = {400,600};
			int Arr3[] = {4,0};
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1000;
			int Arr2[] = { 400, 400 };
			int Arr3[] = { 4, 5 };
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1000;
			int Arr2[] = { 998, 999 };
			int Arr3[] = { 2, 3 };
			string Arg4 = "fair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1000;
			int Arr2[] = { 998, 999 };
			int Arr3[] = { 1, 2 };
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearFair ___test;
	___test.run_test(-1);
}
// END CUT HERE
