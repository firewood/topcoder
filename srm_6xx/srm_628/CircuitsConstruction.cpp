// BEGIN CUT HERE
/*
SRM 628 Div1 Medium (500)

PROBLEM STATEMENT
Janusz is a young physicist.
He is currently playing with some electric circuits.

The simplest circuit consists of a single conductor (i.e., a single piece of wire).
Each such circuit is labeled using the string "X".

Janusz is using two different ways to connect two simpler circuits into one new, more complex circuit.
Note that these are not the standard two ways (connecting in series and in parallel), so read the following description carefully.

If Janusz uses the type-A connection, the resistance of the new circuit is the sum of the resistances of the two original circuits.
If Janusz uses the type-B connection, the resistance of the new circuit is the maximum of the resistances of the two original circuits.


Suppose that the two original circuits had labels C1 and C2.
Then we use the label "A"+C1+C2 for a new circuit constructed from them using the type-A connection, and the label "B"+C1+C2 if type-B connection was used.
For example, "AXX" is the label of the circuit obtained by using a type-A connection on two conductors.

You are given a string circuit with a valid label of a circuit.
You are also given a vector <int> conductors with as many elements as the number of occurrences of 'X' in circuit.
The elements of conductors are the resistances of all conductors you are going to use to construct the circuit described by circuit.
Each of the conductors can only be used once.
Each of the conductors can be used as each of the 'X's.
Return the largest possible resistance of the constructed circuit.


DEFINITION
Class:CircuitsConstruction
Method:maximizeResistance
Parameters:string, vector <int>
Returns:int
Method signature:int maximizeResistance(string circuit, vector <int> conductors)


NOTES
-There is no explicit constraint on the length of circuit. This is intentional, as it can be derived from the other constraints.


CONSTRAINTS
-Each character in circuit will be 'A', 'B', or 'X'.
-circuit will be a valid circuit label according to the problem statement.
-conductors will contain between 1 and 2,000 elements, inclusive.
-Each element of conductors will be between 1 and 100,000, inclusive.
-The number of occurrences of the character 'X' in circuit will be equal to the number of elements of conductors.


EXAMPLES

0)
"BXBXX"
{8, 2, 3}

Returns: 8

Regardless of the order in which we use the conductors, the final resistance will be the maximum of the resistances of our three conductors.


1)
"AAXXAXAXX"
{1, 1, 2, 8, 10}

Returns: 22

Regardless of the order in which we use the conductors, the final resistance will be the sum of the resistances of our five conductors.


2)
"AXBXX"
{8, 2, 3}

Returns: 11

One possible optimal solution looks as follows:

We take the conductors with resistance 2 and 3, and use a type-B connection to combine them into a new circuit.
We take the remaining conductor (with resistance 8) and the new circuit constructed in the previous step. We use a type-A connection to combine them into the resulting circuit.

The resistance of the circuit constructed in the first step is max(2,3) = 3.
The resistance of the whole circuit is 8 + 3 = 11, which is the largest value we can obtain.


3)
"BAAXBXXBXAXXBBAXXBXXAAXXX"
{17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30}

Returns: 454

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CircuitsConstruction {
	string c;
	vector <int> con;

	int dfs(const char *&s) {
		switch (*s++) {
		case 'A':
			return dfs(s) + dfs(s);
		case 'B':
			return max(dfs(s), dfs(s));
		case 'X':
			return 1;
		}
		return 0;
	}

public:
	int maximizeResistance(string circuit, vector <int> conductors) {
		const char *s = circuit.c_str();
		int cnt = dfs(s);
		sort(conductors.rbegin(), conductors.rend());
		return accumulate(conductors.begin(), conductors.begin() + cnt, 0);
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
			string Arg0 = "BXBXX";
			int Arr1[] = {8, 2, 3};
			int Arg2 = 8;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAXXAXAXX";
			int Arr1[] = {1, 1, 2, 8, 10};
			int Arg2 = 22;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AXBXX";
			int Arr1[] = {8, 2, 3};
			int Arg2 = 11;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAAXBXXBXAXXBBAXXBXXAAXXX";
			int Arr1[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30};
			int Arg2 = 454;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABBABBXXXAXXBAAXXXBBXXAAXXXBBBXAXXBAXXXBBAAXXXBXXXBAABBBXXXABXBXXBAXXXAXBXAXXXBBABXXAXXABBXXAXAXXXX";
			int Arr1[] = { 323, 647, 195, 94, 682, 35, 723, 252, 143, 261, 106, 832, 450, 894, 669, 569, 484, 429, 246, 514, 516, 899, 238, 940, 915, 963, 708, 157, 242, 454, 47, 3, 578, 285, 753, 908, 795, 489, 12, 840, 370, 184, 273, 721, 925, 592, 695, 681, 81, 793 };
			int Arg2 = 8911;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;




	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CircuitsConstruction ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
