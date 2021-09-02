// BEGIN CUT HERE
/*
SRM 812 Div2 Medium (600)

PROBLEM STATEMENT

Elon is planning to colonize Mars.

According to Elon's plans, there should be N habitats on Mars.
They are going to be numbered from 0 to N-1, inclusive.
Habitat 0 will be the communications center.

Habitats will be connected by (bidirectional) corridors.
For technical reasons, each habitat must have exactly three outgoing corridors.

Sometimes, both ends of a corridor may connect to the same habitat.
Such a corridor counts as two corridors leaving that habitat.

Each corridor must have a non-negative integer length.

Note that the length of any corridor may be zero.
(Self-looping corridors that start and end at the same habitat also may, but do not have to, have length zero.)

Once you build the N habitats and all corridors between them, we can measure distances:
the distance between any two habitats is the smallest total length of corridors one has to cross in order to get from one habitat to the other.

Elon has a clear vision how far from the communications center each habitat should be.
More precisely, for each habitat i Elon has determined the shortest distance distances[i] from habitat 0 along some corridors to habitat i.

Note that all the distances in distances are finite non-negative values, which implies that Elon wants to have a connected network of habitats.

Determine whether it is possible to design the corridors according to the technical requirements and Elon's wishes: each habitat must have three corridors, and all the distances must be as given in the input.

If it's not possible, return an empty vector <int>.

If it's possible, return a vector <int> with exactly 6*N values.

For each habitat i, look at the three corridors that leave this habitat. For each of them, write down first the number of the habitat at its other end, and then the length of the corridor.
The description of habitat i are the six values {number1, length1, number2, length2, number3, length3}.

Return the concatenation of the descriptions of all habitats in your solution.
Your solution will be accepted if it produces the correct distances.
Additionally, we require that the length of each corridor must be at most 1,000,000.
For each habitat, the three outgoing corridors can be listed in any order.


DEFINITION
Class:MarsHabitats
Method:design
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> design(vector <int> distances)


NOTES
-The value N is not given explicitly. You can determine it as the number of elements in distances.


CONSTRAINTS
-distances will have between 1 and 200 elements, inclusive.
-Each element of distances will be between 0 and 1,000,000, inclusive.
-distances[0] will be 0.


EXAMPLES

0)
{0}

Returns: { }

There is just a single habitat. There is no way to have exactly three corridors leaving this habitat, so we cannot satisfy the technical requirements.


1)
{0, 10}

Returns: {1, 10, 1, 42, 1, 47, 0, 10, 0, 47, 0, 42 }

In the example output, the two habitats are connected by three separate corridors: one has length 10, one has length 42, and one has length 47. The distance from habitat 0 to habitat 1 is the length of the shortest of those three corridors.


2)
{0, 47}

Returns: {0, 10, 0, 10, 1, 47, 1, 10, 0, 47, 1, 10 }

In the example output, the two habitats are connected by a single corridor of length 47. Additionally, each habitat has its own self-looping corridor of length 10.


3)
{0, 47, 42, 25, 10, 22}

Returns: {1, 47, 2, 42, 4, 10, 0, 47, 3, 33, 3, 34, 0, 42, 2, 1234, 2, 1234, 1, 34, 1, 33, 4, 15, 0, 10, 3, 15, 5, 12, 5, 0, 4, 12, 5, 0 }

The sample return value corresponds to the following configuration of habitats:


 5 --(12)-- 4 --(10)-- 0 --(42)-- 2
            |          |
           (15)       (47)
            |          |
            3 --(33)-- 1
             \__(34)__/
 
The number in parentheses is the length of the corridor. Numbers outside parentheses represent habitats. There are two self-looping corridors that are not shown in the figure.

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
#include <queue>

using namespace std;

typedef pair<int, int> II;

class MarsHabitats {
public:
	vector <int> design(vector <int> distances) {
		vector <int> ans;
		int N = distances.size();
		vector<vector<II>> e(N);
		priority_queue<II, vector<II>, greater<II>> q;
		for (int i = 0; i < 3; ++i) {
			q.emplace(II(0, 0));
		}
		vector<II> v;
		for (int i = 1; i < N; ++i) {
			v.emplace_back(II(distances[i], i));
		}
		sort(v.begin(), v.end());
		for (int vi = 0; vi < N - 1; ++vi) {
			int from = v[vi].second, cost = v[vi].first;
			int prev_cost = q.top().first, to = q.top().second;
			q.pop();
			e[from].emplace_back(II(to, cost - prev_cost));
			e[to].emplace_back(II(from, cost - prev_cost));
			q.emplace(II(cost, from));
			q.emplace(II(cost, from));
		}
		while (!q.empty()) {
			int from = q.top().second;
			q.pop();
			if (q.empty()) {
				return ans;
			}
			int to = q.top().second;
			q.pop();
			e[from].emplace_back(II(to, 1000000));
			e[to].emplace_back(II(from, 1000000));
		}
		for (int i = 0; i < N; ++i) {
			for (auto kv : e[i]) {
				ans.emplace_back(kv.first);
				ans.emplace_back(kv.second);
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
			int Arr0[] = {0};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, design(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 10};
			int Arr1[] = {1, 10, 1, 42, 1, 47, 0, 10, 0, 47, 0, 42 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, design(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 47};
			int Arr1[] = {0, 10, 0, 10, 1, 47, 1, 10, 0, 47, 1, 10 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, design(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 47, 42, 25, 10, 22};
			int Arr1[] = {1, 47, 2, 42, 4, 10, 0, 47, 3, 33, 3, 34, 0, 42, 2, 1234, 2, 1234, 1, 34, 1, 33, 4, 15, 0, 10, 3, 15, 5, 12, 5, 0, 4, 12, 5, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, design(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MarsHabitats ___test;
	___test.run_test(-1);
}
// END CUT HERE
