// BEGIN CUT HERE
/*
SRM 700 Div1 Easy (300)

PROBLEM STATEMENT

Your friend just took part in a popular online programming contest.
The participants were split across roomCount rooms, with each room containing exactly roomSize contestants.
We will use n = roomCount * roomSize to denote the total number of contestants.

The contest was such that there were no ties.
After the contest, each contestant had a distinct rank between 1 and n, inclusive.
(The contestant with rank 1 is the winner.)

A room winner is the contestant with the best (i.e., smallest) rank in their room.

You do not know the final standings.
The only thing you know are the ranks of all room winners.
More precisely, you are given a vector <int> leaders with roomCount elements.
The i-th element of leaders denotes the rank of the room winner of the i-th room.

Your friend just told you that her rank in this contest was friendPlace.

Return the number of different rooms in which your friend could have competed, given the information you have.


DEFINITION
Class:FindingFriend
Method:find
Parameters:int, vector <int>, int
Returns:int
Method signature:int find(int roomSize, vector <int> leaders, int friendPlace)


NOTES
-The value of n is not explicitly given in the arguments, but can be computed as roomSize times the number of elements in leaders.


CONSTRAINTS
-roomSize will be between 1 and 1,000,000,000, inclusive.
-roomCount will be between 1 and 1,000, inclusive.
-Additionally, roomSize and roomCount will be such that n (that is, roomSize times roomCount) will not exceed 1,000,000,000.
-leaders will contain exactly roomCount elements.
-Each element of leaders will be between 1 and n, inclusive.
-All elements of leaders will be distinct.
-It is guaranteed there is at least one distribution of contestants into rooms that is consistent with leaders.
-friendPlace will be between 1 and n, inclusive.


EXAMPLES

0)
2
{5,1,2}
4

Returns: 2

We have 6 contestants: 3 rooms with 2 contestants in each of them.
Your friend finished 4-th.
Given the information you have, there are only two possible distributions of contestant ranks into rooms:

Room 1: ranks 5 and 6. Room 2: ranks 1 and 3. Room 3: ranks 2 and 4.
Room 1: ranks 5 and 6. Room 2: ranks 1 and 4. Room 3: ranks 2 and 3.

Your friend has competed either in room 2 or in room 3.
There are two possible rooms, so the correct return value is 2.


1)
5
{1,2,3,4,5}
4

Returns: 1

You know for sure your friend is in room 4, as she is its room winner.


2)
6
{10,5,1,4,2,20}
9

Returns: 4

Your friend can be in either of the rooms 2, 3, 4, and 5.


3)
1000000000
{1}
700700700

Returns: 1


4)
2
{3,6,8,1,2}
10

Returns: 5

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

class FindingFriend {

	bool possible(int roomSize, vector <int> leaders, int friendPlace, int target_room) {
		if (leaders[target_room] > friendPlace) {
			return false;
		}
		int rooms = (int)leaders.size();
		int cnt[1000] = {};
		IIVec v;
		for (int i = 0; i != rooms; ++i) {
			cnt[i] = roomSize;
			v.push_back(II(leaders[i], i));
		}
		sort(v.rbegin(), v.rend());
		int b = rooms * roomSize + 1;
		bool fit = false;
		bool ext = false;
		for (int i = 0; i != rooms; ++i) {
			int leader = v[i].first;
			int room = v[i].second;
			int bottom = b;
			int top = b - cnt[room];
			b = top;
			if (top < leader) {
				return false;
			}
			if (room == target_room) {
				return bottom >= friendPlace && leader <= friendPlace;
			} else {
				if (top <= friendPlace) {
					if ((top - 1) < leader) {
						return false;
					}
					return true;
				}
			}
		}
		return false;
	}

public:
	int find(int roomSize, vector <int> leaders, int friendPlace) {
		int rooms = (int)leaders.size();
		if (roomSize <= 1 || rooms <= 1) {
			return 1;
		}
		if (std::find(leaders.begin(), leaders.end(), friendPlace) != leaders.end()) {
			return 1;
		}

		int ans = 0;
		for (int i = 0; i != rooms; ++i) {
			ans += possible(roomSize, leaders, friendPlace, i);
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
			int Arg0 = 2;
			int Arr1[] = {5,1,2};
			int Arg2 = 4;
			int Arg3 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {1,2,3,4,5};
			int Arg2 = 4;
			int Arg3 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {10,5,1,4,2,20};
			int Arg2 = 9;
			int Arg3 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arr1[] = {1};
			int Arg2 = 700700700;
			int Arg3 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {3,6,8,1,2};
			int Arg2 = 10;
			int Arg3 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2140026;
			int Arr1[] = { 209068604, 196882393, 423725149, 264546532, 84360518, 359524369, 57461806, 272446616, 439678847, 346895056, 34240417, 142044799, 168038587, 20841717, 308163745, 98441197, 49481079, 272846772, 389484733, 365786277, 181902211, 374504551, 353104291, 332286683, 111281353, 199022419, 63273593, 164782003, 269145228, 147661795, 27341653, 408744967, 29960365, 342404161, 314009632, 385402879, 355244317, 406604941, 221435105, 192639617, 141241717, 38520469, 250383043, 241426303, 154798579, 82580214, 178834860, 15322643, 291043537, 14979956, 259966751, 71549347, 402324889, 151941847, 428005201, 286763485, 449199131, 130600731, 115561405, 331523160, 40660495, 25680313, 343936149, 319832759, 77905035, 284623459, 102841831, 89881093, 171202081, 299483408, 74839629, 281284912, 235402861, 303883693, 206320972, 7909996, 55640677, 429002899, 100581223, 339007491, 316723849, 360104161, 444630, 227213807, 60121150, 117701431, 368084473, 119738112, 333217672, 4280053, 78692740, 136961665, 378784603, 188322289, 36152612, 309187471, 12773171, 434425279, 192024933, 442985383, 165917424, 451545487, 1, 149801821, 214002601, 300911092, 30276962, 395904811, 413025019, 323031686, 220422679, 155536518, 95767653, 322857492, 50213286, 295323589, 346684213, 151999322, 82823784, 424432753, 398044837, 239682913, 391624759, 133481348, 217722118, 363734256, 184042237, 70620859, 398758977, 68480833, 306023719, 6420079, 278203381, 113177035, 190462315, 126565475, 9719329, 237542887, 357384343, 288399649, 49220599, 230596797, 203696377, 414595877, 370362537, 265814992, 438054609, 159622244, 224702731, 453685513, 338124109, 380924629, 404464915, 409829712, 175482133, 348177673, 203302471, 207590112, 262848363, 376564855, 100777000, 145521769, 21280542, 42800521, 123270399, 176287183, 413487529, 445125409, 250420600, 393322394, 185853800, 312443797, 292806774, 121981483, 19260235, 216142627, 245307489, 318863875, 416931810, 43930002, 385204681, 329564005, 63883167, 435843098, 280343407, 370224499, 271783303, 383064655, 233262835, 297421770, 243091750, 130541587, 327423979, 94161145, 201162445, 107408893, 171644202, 107001301, 77040937, 256803121, 414953234, 59920729, 248243017, 45452905, 258490950, 253864583, 447265435, 162641977, 226235923, 432264274, 125088409, 137276055, 90024899 };
			int Arg2 = 322987645;
			int Arg3 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arr1[] = { 1, 4, 21, 31 };
			int Arg2 = 35;
			int Arg3 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FindingFriend ___test;
	___test.run_test(-1);
}
// END CUT HERE
