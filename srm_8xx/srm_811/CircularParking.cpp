// BEGIN CUT HERE
/*
SRM 811 Div2 Medium (500)

PROBLEM STATEMENT

This problem is about simulating how N cars park along a circular street.

There is a long circular one-way road.
Along the road there are N parking spots, numbered from 0 to N-1 in order.
As you drive along the road, parking spot numbers increase.
(As the road is circular, after N-1 you get back to 0.)

Initially, all parking spots are empty.
N cars arrive to the circular road and park there.
The cars arrive one at a time: the next car always arrives only after the previous one has parked.

The cars are numbered from 0 to N-1 in the order in which they arrive.
The numbering of cars is unrelated to the numbering of parking spots.

For each i from 0 to N-1, inclusive:
Car i will arrive to the circular road in such a place that the first parking spot it encounters is the parking spot 
P[i] = (A*i*i + B*i + C) modulo N.

Each car drives along the road until it finds an empty parking spot.
Once it finds an empty parking spot, it parks there.

For example, suppose we have N = 4 and (A,B,C)=(1,2,3). Car 0 will park at spot P[0] = 3, car 1 will park at spot P[1] = 2, car 2 will appear next to the occupied parking spot P[2] = 3, drive past it and park at spot 0, and finally car 3 will appear at P[3] = 2, drive past occupied spots 2, 3, and 0, and park at the final free spot 1.

Each time a car encounters an occupied parking spot, a collision occurs.
For example, in the scenario described above the cars produce a total of 0 + 0 + 1 + 3 = 4 collisions.
We don't like collisions, as they cause delays.


Calculate and return the total number of collisions that will happen while our N cars park.


DEFINITION
Class:CircularParking
Method:park
Parameters:int, int, int, int
Returns:long long
Method signature:long long park(int N, int A, int B, int C)


NOTES
-It should be obvious that the correct answer always fits into a signed 64-bit integer.
-Watch out for integer overflows when computing the value "(A*i*i + B*i + C) modulo N".


CONSTRAINTS
-N will be between 3 and 250,000, inclusive.
-A will be between 0 and N-1, inclusive.
-B will be between 0 and N-1, inclusive.
-C will be between 0 and N-1, inclusive.


EXAMPLES

0)
47
0
1
0

Returns: 0

For each i, car i arrives at the parking spot i, and as it is empty, it parks there. No collisions.


1)
47
0
0
42

Returns: 1081

Each car arrives at the parking spot 42. Car i will have i collisions before it parks on the spot (42+i) modulo 47.


2)
30
1
1
1

Returns: 175

Car i starts looking for an empty parking spot at the parking spot (i*i + i + 1) modulo 30. There will be some collisions. E.g., eight of the 30 cars will start at the parking spot number 13.


3)
4
1
2
3

Returns: 4

The example from the problem statement.

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

class CircularParking {
public:
	long long park(LL N, LL A, LL B, LL C) {
		LL ans = 0;
		set<LL> s;
		for (int i = 0; i < N; ++i) {
			s.insert(i);
		}
		for (LL i = 0; i < N; ++i) {
			LL x = (A * i * i + B * i + C) % N;
			auto it = s.lower_bound(x);
			if (it == s.end()) {
				ans += N - x;
				x = 0;
				it = s.lower_bound(x);
			}
			ans += *it - x;
			s.erase(it);
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
			int Arg0 = 47;
			int Arg1 = 0;
			int Arg2 = 1;
			int Arg3 = 0;
			long long Arg4 = 0LL;

			verify_case(n, Arg4, park(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 42;
			long long Arg4 = 1081LL;

			verify_case(n, Arg4, park(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;
			long long Arg4 = 175LL;

			verify_case(n, Arg4, park(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 3;
			long long Arg4 = 4LL;

			verify_case(n, Arg4, park(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 250000;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			long long Arg4 = 31249875000LL;

			verify_case(n, Arg4, park(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 250000;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 249999;
			long long Arg4 = 31249875000LL;

			verify_case(n, Arg4, park(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CircularParking ___test;
	___test.run_test(-1);
}
// END CUT HERE
