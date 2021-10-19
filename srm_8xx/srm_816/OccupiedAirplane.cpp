// BEGIN CUT HERE
/*
SRM 816 Div1 Medium (500)

PROBLEM STATEMENT

Your task is to write a function that will assign airplane seats to groups of passengers.

The airplane has R rows of seats. 
Rows are numbered from 1 (in the front) to R (in the back).

In each row there are six seats, labelled A, B, C, D, E, F.
The label of each seat is its row followed by its letter.
For example, the label of seat C in row 12 is 12C.

All seats can be ordered: first by row number and then by letter alphabetically.
This will be called the canonical order.
The first few seats in the canonical order: 1A, 1B, 1C, 1D, 1E, 1F, 2A, 2B, ...

The 0-based index of a seat in the canonical order is its canonical number: 1A = 0, 1B = 1, ..., 2A = 6, 2B = 7, and so on.

In each row, seats A and F are called "window seats", seats C and D are called "aisle seats", and seats B and E are called "middle seats".

When seating the passengers, you must follow the following simple rules:

Whenever you have multiple equally good options where to seat a passenger, choose the one among them that is first in the canonical order.

When seating a single passenger (a group of size 1):
 
 If there is an available window seat, give them a window seat.
 If there is an available aisle seat, give them an aisle seat.
 And if there are only middle seats left, give them a middle seat.

When seating a group of passengers:
 
 If there are enough empty seats available in any row, seat all passengers in the group in the first such row. (And, as the tiebreaker implies, use the leftmost available seats.)
 Otherwise, seat each member of the group as an individual passenger.

You are given the following inputs:

 the int R that specifies the number of rows in the airplane
 the vector <int> groups with the sizes of a small number of initial groups of passengers to process
 the int seed used to generate additional groups of passengers until the plane becomes full

Proceed according to the following pseudocode:

start with an empty plane
for each element g of groups, in order:
    seat a group of g passengers

state = seed
in an infinite loop:
    state = (state * 1103515245 + 12345) modulo 2^31
    g = ((state >> 10) modulo 6) + 1
    try to seat a group of g passengers
    if you failed to find room for them on the plane: terminate

For each group that you manage to seat, write down the canonical numbers of seats they received.
(When seating a group into the same row, write the seat numbers in ascending order. When breaking up a group into individuals and seating each of them separately, write the seat numbers in the order in which they were assigned.)

Let S = { S[0], S[1], S[2], ... } be the sequence you have written down.
Return the value sum( (i+1)*S[i] ).


DEFINITION
Class:OccupiedAirplane
Method:seat
Parameters:int, vector <int>, int
Returns:long long
Method signature:long long seat(int R, vector <int> groups, int seed)


NOTES
-The reference solution does not depend on the input being pseudorandom.


CONSTRAINTS
-R will be between 1 and 100,000, inclusive.
-groups will have between 0 and 100 elements, inclusive.
-Each element of groups will be between 1 and 6, inclusive.
-The sum of groups will not exceed 6*R.
-seed will be between 0 and 2^31 - 1, inclusive.


EXAMPLES

0)
1
{1, 1, 4}
47

Returns: 60


A single row of seats. The first passenger gets the seat 1A, the second passenger gets the seat 1F, and then the group of four gets the other four seats.

We will write down the sequence 0, 5, 1, 2, 3, 4.
The correct return value is therefore 1*0 + 2*5 + 3*1 + 4*2 + 5*3 + 6*4.


1)
1
{2}
46

Returns: 2

The first group of two passengers gets the seats 1A and 1B.
The next group (the first one generated from the seed) has six passengers. It does not fit onto the plane, so we are done. (Note that we don't seat a part of the group.)
The return value is 1*0 + 2*1.


2)
1
{1, 1, 1, 3}
46

Returns: 59

The first three passengers get seats 1A, 1F, and then 1C. The group of three has no row with three consecutive seats, so they get the non-consecutive seats in row 1: 1B, 1D, and 1E.


3)
2
{1, 1, 1, 3}
46

Returns: 519


Here, the first three passengers get seats 1A, 1F, and 2A. The group of three then gets three consecutive seats in row 1: 1B, 1C, and 1D.

Finally, we have a group of six. (This group is generated as the first pseudorandom group.)

There is no row into which all six would fit, so we are going to seat them as individuals. The first of them is lucky to get the last window seat (2F). The next ones get aisle seats (2C, 2D) and the last three fill in the remaining middle seats (1E, 2B, 2E).

The sequence S that describes the order in which we assigned seats looks as follows:
S = {0, 5, 6, 1, 2, 3, 11, 8, 9, 4, 7, 10}.


4)
2
{1, 1, 1, 1, 1, 4}
46

Returns: 342

The first four passengers grab the four window seats. The next passenger gets the aisle seat 1C. Finally, we have a group of four to seat. They don't fit into the first row, so they'll get all the empty seats in row 2 (seats 2B, 2C, 2D, 2E).

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
typedef priority_queue<II, vector<II>, greater<II>> Queue;

class OccupiedAirplane {
public:
	long long seat(int R, vector <int> groups, int seed) {
		vector<Queue> q(7);
		for (int i = 0; i < R; ++i) {
			for (int j = 2; j <= 6; ++j) {
				for (int k = 0; k + j <= 6; ++k) {
					q[j].emplace(II(i * 6 + k, i * 6 + k));
				}
			}
			q[1].emplace(II(i * 6, i * 6));
			q[1].emplace(II(i * 6 + 1, i * 6 + 5));
			q[1].emplace(II((i + R) * 6, i * 6 + 2));
			q[1].emplace(II((i + R) * 6 + 1, i * 6 + 3));
			q[1].emplace(II((i + R * 2) * 6, i * 6 + 1));
			q[1].emplace(II((i + R * 2) * 6 + 1, i * 6 + 4));
		}

		vector<vector<int>> used(R, vector<int>(6));
		int r = R * 6, i = 0;
		vector<int64_t> seq;
		long long ans = 0, state = seed;
		while (true) {
			int g;
			if (i < groups.size()) {
				g = groups[i++];
			} else {
				state = (state * 1103515245 + 12345) % (1LL << 31);
				g = ((state >> 10) % 6) + 1;
			}
			r -= g;
			if (r < 0) {
				break;
			}
			while (!q[g].empty()) {
				II top = q[g].top();
				q[g].pop();
				int y = top.second / 6, x = top.second % 6;
				bool ok = true;
				for (int i = 0; i < g; ++i) {
					if (used[y][i + x]) {
						ok = false;
					}
				}
				if (ok) {
					for (int i = 0; i < g; ++i) {
						used[y][i + x] = 1;
						seq.emplace_back(y * 6 + i + x);
					}
					goto next;
				}
				if (g == 2 && x == 1 && !used[y][x] && !used[y][3]) {
					used[y][x] = 1;
					used[y][3] = 1;
					seq.emplace_back(y * 6 + x);
					seq.emplace_back(y * 6 + 3);
					goto next;
				}
				if (g == 2 && x == 1 && !used[y][x] && !used[y][4]) {
					used[y][x] = 1;
					used[y][4] = 1;
					seq.emplace_back(y * 6 + x);
					seq.emplace_back(y * 6 + 4);
					goto next;
				}
				if (g == 3 && x == 1 && !used[y][x] && !used[y][3] && !used[y][4]) {
					used[y][x] = 1;
					used[y][3] = 1;
					used[y][4] = 1;
					seq.emplace_back(y * 6 + x);
					seq.emplace_back(y * 6 + 3);
					seq.emplace_back(y * 6 + 4);
					goto next;
				}
			}
			while (g > 0) {
				II top = q[1].top();
				q[1].pop();
				int y = top.second / 6, x = top.second % 6;
				if (!used[y][x]) {
					--g;
					used[y][x] = 1;
					seq.emplace_back(y * 6 + x);
				}
			}

		next:
			{}
		}
		for (int64_t i = 0; i < seq.size(); ++i) {
			ans += (i + 1) * seq[i];
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
			int Arg0 = 1;
			int Arr1[] = {1, 1, 4};
			int Arg2 = 47;
			long long Arg3 = 60LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, seat(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {2};
			int Arg2 = 46;
			long long Arg3 = 2LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, seat(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1, 1, 1, 3};
			int Arg2 = 46;
			long long Arg3 = 59LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, seat(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1, 1, 1, 3};
			int Arg2 = 46;
			long long Arg3 = 519LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, seat(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1, 1, 1, 1, 1, 4};
			int Arg2 = 46;
			long long Arg3 = 342LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, seat(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OccupiedAirplane ___test;
	___test.run_test(-1);
}
// END CUT HERE
