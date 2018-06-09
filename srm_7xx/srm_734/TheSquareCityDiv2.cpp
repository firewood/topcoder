// BEGIN CUT HERE
/*
SRM 734 Div2 Medium (500)

PROBLEM STATEMENT
John and Brus have found a nice horizontal plane and they built a square city somewhere on the plane.
The city has n rows and n columns of houses.
More precisely, John and Brus built a house at each lattice point (x, y) such that 0 ? x, y < n.

The winter is coming.
Different houses have different heating systems and thus the temperatures inside them are distinct.
You are given the vector <int> t with n*n elements.
The temperature inside the house at (x, y) is t[x*n + y] degrees.

Outside there is a lot of snow and the only paths in the snow are along coordinate axes.
Thus, moving from the house at (x1, y1) to the house at (x2, y2) takes |x1 - x2| + |y1 - y2| minutes.
Additionally, it's freezing outside, so a person can only stay outside for at most r consecutive minutes.

Initially there is exactly one person living in each house.
Each person then repeats the following process: They find the warmest house they can reach in a single trip, and they move there.
The people repeat the action until there is no warmer house within r minutes of travel from their current house.

Find two values:

a = the number of houses that will contain at least one person once everyone stops moving
b = the maximal number of people who will share the same house

Return a vector <int> with exactly two elements: {a, b}.


DEFINITION
Class:TheSquareCityDiv2
Method:find
Parameters:int, vector <int>
Returns:vector <int>
Method signature:vector <int> find(int r, vector <int> t)


CONSTRAINTS
-n will be between 1 and 20, inclusive.
-r will be between 1 and 40, inclusive.
-t will contain exactly n*n elements.
-Each element of t will be between 1 and 1,000, inclusive.
-All elements of t will be distinct.


EXAMPLES

0)
1
{
9, 1, 6, 
5, 3, 2, 
7, 4, 8
}

Returns: {4, 4 }

There are nine houses in the city. We will identify them by the temperature inside. I.e., "house x" means "the house with temperature x inside".

People from house 1 and house 5 will move to house 9 and stay there.

The person from house 3 will first move to house 5 and then to house 9.

People from house 2 and house 4 will move to house 8 and stay there.

All other people (the ones who start in houses 6, 7, 8, and 9) will not move at all.

In the end there will be 4 non-empty houses (houses 6 through 9) and the most occupied house will be house 9 with 4 inhabitants.


1)
2
{
9, 1, 6, 
5, 3, 2, 
7, 4, 8
}

Returns: {2, 6 }

This is the same city but the people can stay outside for two minutes at a time. 
In the end, three people will end in house 8 and the other six will reach house 9.


2)
7
{
9, 1, 6, 
5, 3, 2, 
7, 4, 8
}

Returns: {1, 9 }

Now since r is large everyone will move directly to house 9.


3)
3
{
59, 22,  2, 17, 77, 43, 67, 
16, 49, 51, 46, 61,  4,  9, 
42, 12, 80, 82, 24, 29,  1, 
27, 63, 65, 26, 10, 28, 83, 
 7, 73,  8, 47, 37, 23, 38, 
75, 54, 71, 58, 78, 21, 45, 
35, 81, 48, 41, 44, 52, 32
}

Returns: {5, 20 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TheSquareCityDiv2 {
public:
	vector <int> find(int r, vector <int> t) {
		int wi[20][20];
		int wj[20][20];
		int cnt[20][20];
		int n = sqrt(t.size());
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cnt[i][j] = 1;
				int p = i, q = j;
				for (int k = 0; k < n; ++k) {
					for (int l = 0; l < n; ++l) {
						if ((i != k || j != l) && (abs(i - k) + abs(j - l)) <= r && t[k * n + l] > t[p * n + q]) {
							p = k, q = l;
						}
					}
				}
				wi[i][j] = p;
				wj[i][j] = q;
			}
		}
		bool f = true;
		while (f) {
			f = false;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (cnt[i][j] && (wi[i][j] != i || wj[i][j] != j)) {
						f = true;
						cnt[wi[i][j]][wj[i][j]] += cnt[i][j];
						cnt[i][j] = 0;
					}
				}
			}
		}
		vector<int> ans{ 0, 0 };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans[0] += cnt[i][j] > 0;
				ans[1] = max(ans[1], cnt[i][j]);
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {
9, 1, 6, 
5, 3, 2, 
7, 4, 8
};
			int Arr2[] = {4, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {
9, 1, 6, 
5, 3, 2, 
7, 4, 8
};
			int Arr2[] = {2, 6 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arr1[] = {
9, 1, 6, 
5, 3, 2, 
7, 4, 8
};
			int Arr2[] = {1, 9 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {
59, 22,  2, 17, 77, 43, 67, 
16, 49, 51, 46, 61,  4,  9, 
42, 12, 80, 82, 24, 29,  1, 
27, 63, 65, 26, 10, 28, 83, 
 7, 73,  8, 47, 37, 23, 38, 
75, 54, 71, 58, 78, 21, 45, 
35, 81, 48, 41, 44, 52, 32
};
			int Arr2[] = {5, 20 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheSquareCityDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
