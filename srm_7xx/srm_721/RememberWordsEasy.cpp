// BEGIN CUT HERE
/*
SRM 721 Div2 Medium (500)

PROBLEM STATEMENT
For Fox Ciel it is the beginning of a new school year.
Her school year will consist of two semesters.
The first semester contains d1 days and the second semester contains d2 days.
Surprisingly, there are no breaks during or between the semesters: the entire school year consists of d1+d2 consecutive days of classes.

Fox Ciel is taking an English class during both semesters.
For the class she needs to learn a lot of new words: exactly w1 words during the first semester and exactly w2 words during the second semester.

Ciel can learn arbitrarily many words on any single day.
However, she does not like to change her workload too much.
Therefore, the number of words she will learn on any two consecutive days must differ by at most one.

Formally, suppose the days of the school year are numbered from 1 to d1+d2.
Suppose that Ciel will learn x[i] words on day i.
Ciel will be happy if the numbers x[i] have the following properties:

x[1] + ... + x[d1] is exactly equal to w1
x[d1+1] + ... + x[d1+d2] is exactly equal to w2
for each valid i, | x[i+1] - x[i] | is at most 1


You are given the ints d1, d2, w1, and w2.
Return "Possible" if there is a schedule that makes Ciel happy, or "Impossible" if there is no such schedule.


DEFINITION
Class:RememberWordsEasy
Method:isPossible
Parameters:int, int, int, int
Returns:string
Method signature:string isPossible(int d1, int d2, int w1, int w2)


CONSTRAINTS
-d1 will be between 1 and 1,000,000, inclusive.
-d2 will be between 1 and 1,000,000, inclusive.
-w1 will be between 0 and 1,000,000, inclusive.
-w2 will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
2
3
7
18

Returns: "Possible"

The school year has 2+3 = 5 days.
Ciel needs to learn exactly 7 words during the first semester and exactly 18 words during the second semester.
The only valid way to do so is to learn 3, 4, 5, 6, and 7 words during the five days of the school year.
Note that 3+4 = 7 and 5+6+7 = 18.


1)
1
1
3
5

Returns: "Impossible"

Here the school year has just 1+1 = 2 days.
Ciel must learn 3 words on the first day and 5 words on the second day.
However, |3 - 5| is more than 1, so Ciel will not be happy with this schedule.


2)
3
5
300
500

Returns: "Possible"

One possible solution is to learn 100 words every day.


3)
100
1
0
2

Returns: "Impossible"


4)
1000000
1000000
1000000
1000000

Returns: "Possible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

void get_bounds(LL v, LL d, LL &l, LL &h) {
	l = 0, h = 0;
	if (v >= (d * (d - 1)) / 2) {
		LL r = v - (d * (d - 1) / 2);
		l = h = r / d;
		v -= l * d;
	}
	LL a, b = 0;
	for (a = 1; ; ++a) {
		b = ((a + 1) * a) / 2;
		if (b >= v) {
			break;
		}
	}
	if (v) {
		if (v >= b) {
			h += a;
		} else {
			h += a - 1;
			v -= (a - 1);
			if (v && a >= d) {
				++l;
			}
		}
	}
}

bool possible(LL d1, LL d2, LL w1, LL w2) {
	LL p, q, r, s;
	get_bounds(w1, d1, p, q);
	get_bounds(w2, d2, r, s);
	return abs(p - r) <= 1 || abs(p - s) <= 1 || abs(q - r) <= 1 || abs(q - s) <= 1 ||
		(p >= r && p <= s) || (q >= r && q <= s) || (r >= p && r <= q) || (s >= p && s <= q);
}

class RememberWordsEasy {
public:
	string isPossible(int d1, int d2, int w1, int w2) {
		return possible(d1, d2, w1, w2) ? "Possible" : "Impossible";
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
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 7;
			int Arg3 = 18;
			string Arg4 = "Possible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 3;
			int Arg3 = 5;
			string Arg4 = "Impossible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arg2 = 300;
			int Arg3 = 500;
			string Arg4 = "Possible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1;
			int Arg2 = 0;
			int Arg3 = 2;
			string Arg4 = "Impossible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1000000;
			int Arg2 = 1000000;
			int Arg3 = 1000000;
			string Arg4 = "Possible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arg1 = 9090;
			int Arg2 = 439;
			int Arg3 = 91156;
			string Arg4 = "Possible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RememberWordsEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
