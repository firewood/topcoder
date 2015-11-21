// BEGIN CUT HERE
/*
SRM 673 Div1 Easy (250)

PROBLEM STATEMENT
Would you want to fight against bears who ride horses?
Me neither.

Limak is a grizzly bear.
He is a general of the dreadful army of Bearland.
The most important part of the army is, of course, the cavalry.

The cavalry of Bearland consists of the same number of warriors and horses.
Limak knows the strength of each warrior and also the strength of each horse.
These are given in vector <int>s warriors and horses, respectively.

General Limak must assign exactly one horse to each warrior.
Obviously, different warriors must be given different horses.

A warrior together with his assigned horse is called a unit.
The strength of a unit is equal to the product of the strengths of the warrior and the horse that form the unit.

The warrior that corresponds to element 0 in warriors is called Bravebeart.
He is always the first to charge the enemy.
Limak decided that Bravebeart deserves some respect.
Thus, his unit must be strictly stronger than any other unit.
(Ties are not allowed.)

Given this constraint, let X be the number of valid ways in which Limak can create the units.
A general must know everything about his army.
Help Limak count the valid assignments.
Compute and return the value (X modulo 1,000,000,007).


DEFINITION
Class:BearCavalry
Method:countAssignments
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countAssignments(vector <int> warriors, vector <int> horses)


CONSTRAINTS
-warriors will contain between 2 and 50 elements, inclusive.
-warriors and horses will contain the same number of elements.
-Each element in warriors and in horses will be between 1 and 1000, inclusive.


EXAMPLES

0)
{5,8,4,8}
{19,40,25,20}

Returns: 2

There are four warriors and four horses for them.
Bravebeart's strength is warriors[0] = 5.

There are two valid ways to pair the warriors and horses into units.
Below, each unit is presented as an ordered pair (warrior's strength, horse's strength).
The warriors are presented in the same order as in warriors.

Valid assignment #1: (5,40), (8,19), (4,25), (8,20).

Valid assignment #2: (5,40), (8,20), (4,25), (8,19).

In assignment #1, the strength of Bravebeart's unit is 5*40 = 200.
The other three units have strengths 8*19 = 152, 4*25 = 100, and 8*20 = 160.
This is a valid assignment because the number 200 is strictly greater than each of the numbers 152, 100, and 160.


1)
{1,1}
{1,1}

Returns: 0


2)
{10,2,10}
{100,150,200}

Returns: 3

There are three valid assignments.

(10,200), (2,150), (10,100)
(10,200), (2,100), (10,150)
(10,150), (2,200), (10,100)

(Again, the warriors are printed in the same order as in warriors. Hence, in each assignment Bravebeart's unit is the first one printed.)


3)
{10,20}
{1,3}

Returns: 1


4)
{20,20,25,23,24,24,21}
{20,25,25,20,25,23,20}

Returns: 0


5)
{970,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,
800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800}
{1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}

Returns: 318608048

In all 50! assignments Bravebeart's unit is the strongest one.
Thus, you should return 50! modulo 1,000,000,007.
Note that even if different warriors/horses have the same strength, they are still considered distinct.

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

typedef vector<int> IntVec;

#define MOD 1000000007

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
};

class BearCavalry {
public:
	int countAssignments(vector <int> warriors, vector <int> horses) {
		int N = warriors.size();
		sort(warriors.begin() + 1, warriors.end());
		modll ans = 0;
		for (int i = 0; i < N; ++i) {
			int a = warriors[0] * horses[i];
			IntVec h = horses;
			h.erase(h.begin() + i);
			sort(h.begin(), h.end());
			modll b = 1;
			for (int j = 0; j < N - 1; ++j) {
				int k;
				for (k = 0; k < N - 1; ++k) {
					if (warriors[j+1] * h[k] >= a) {
						break;
					}
				}
				int c = k - (N - 2 - j);
				b *= max(0, c);
			}
			ans += b;
		}
		return ans;
	}

// BEGIN CUT HERE
	int countAssignments2(vector <int> warriors, vector <int> horses) {
		LL ans = 0;
		int N = warriors.size();
		if (N <= 8) {
			int seq[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
			do {
				int a = warriors[0] * horses[seq[0]];
				int i;
				for (i = 1; i < N; ++i) {
					if (warriors[i] * horses[seq[i]] >= a) {
						break;
					}
				}
				ans += i >= N;
			} while (next_permutation(seq, seq + N));
		}
		return ans;
	}

private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,8,4,8};
			int Arr1[] = {19,40,25,20};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countAssignments(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1};
			int Arr1[] = {1,1};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countAssignments(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,2,10};
			int Arr1[] = {100,150,200};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countAssignments(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,20};
			int Arr1[] = {1,3};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countAssignments(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {20,20,25,23,24,24,21};
			int Arr1[] = {20,25,25,20,25,23,20};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countAssignments(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {970,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,
800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800};
			int Arr1[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int Arg2 = 318608048;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countAssignments(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearCavalry ___test;
	___test.run_test(-1);

	for (int t = 0; t != 100; ++t) {
		int N = (rand() * 6) / (RAND_MAX + 1) + 1;
		IntVec a(N);
		IntVec b(N);
		for (int i = 0; i < N; ++i) {
			a[i] = (rand() * 10) / (RAND_MAX + 1) + 1;
			b[i] = (rand() * 10) / (RAND_MAX + 1) + 1;
		}
		int p = ___test.countAssignments(a, b);
		int q = ___test.countAssignments2(a, b);
		if (p != q) {
			printf("%d, %d\n ", p, q);
			for (int i = 0; i < N; ++i) {
				printf(" %d", a[i]);
			}
			printf("\n ");
			for (int i = 0; i < N; ++i) {
				printf(" %d", b[i]);
			}
			printf("\n");
			break;
		}
	}
}
// END CUT HERE
