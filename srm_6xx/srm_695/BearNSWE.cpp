// BEGIN CUT HERE
/*
SRM 695 Div2 Easy (250)

PROBLEM STATEMENT
Bear Limak is going to walk to the store.
On his way to the store he likes to visit his friends and stop at various other interesting places.
On his way back he is carrying heavy bags and therefore he walks straight home.

Limak's walk from his home to the store consists of M parts.
In the i-th part (0-based index) Limak will walk a[i] meters in the direction indicated by the character dir[i].
That character is one of 'N', 'S', 'W', 'E', denoting North, South, West, and East, respectively.

On his way back home, Limak follows a straight line from the store to his home.

You are given the description of Limak's way to the store:
the vector <int> a with M integers and the string dir with M characters.
Compute and return the total distance (in meters) Limak will walk on his way to the store and back.
Note that the correct answer may be non-integer (see the first example below).


DEFINITION
Class:BearNSWE
Method:totalDistance
Parameters:vector <int>, string
Returns:double
Method signature:double totalDistance(vector <int> a, string dir)


NOTES
-Your return value must have relative error smaller than 1e-6. In other words, your returned value x will be accepted only if abs(x - ans) ? ans * 10-6, where ans denotes the exact correct answer.


CONSTRAINTS
-M will be between 1 and 50, inclusive.
-a will have exactly M elements.
-dir will have exactly M characters.
-Each element in a will be between 1 and 50, inclusive.
-Each character in dir will be one of 'N', 'S', 'W', 'E'.


EXAMPLES

0)
{1,3,3}
"NES"

Returns: 10.60555127546399

In total, Limak's walk consists of four parts:

He goes 1 meter North.
3 meters East.
3 meters South.
He goes straight to his home.
The distance is sqrt(2*2+3*3) = sqrt(13) = 3.6055512755.

The total distance is 1 + 3 + 3 + 3.6055512755 = 10.6055512755.


1)
{10,10,10,10}
"NWSE"

Returns: 40.0

In this test case the store is located at the same place as Limak's home.
Thus, the length of Limak's walk from the store back home is 0 meters.


2)
{10,10,10,15,8,20,5}
"NEWEWWE"

Returns: 90.8062484748657

It's possible that Limak visits some places more than once.


3)
{42}
"E"

Returns: 84.0


4)
{10,40,40}
"NSE"

Returns: 140.0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BearNSWE {
public:
	double totalDistance(vector <int> a, string dir) {
		double ans = 0;
		int x = 0, y = 0;
		for (int i = 0; i != a.size(); ++i) {
			ans += a[i];
			switch (dir[i]) {
			case 'N': y -= a[i]; break;
			case 'E': x += a[i]; break;
			case 'W': x -= a[i]; break;
			case 'S': y += a[i]; break;
			}
		}
		ans += sqrt(x * x + y * y);
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,3};
			string Arg1 = "NES";
			double Arg2 = 10.60555127546399;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10,10,10};
			string Arg1 = "NWSE";
			double Arg2 = 40.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10,10,15,8,20,5};
			string Arg1 = "NEWEWWE";
			double Arg2 = 90.8062484748657;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42};
			string Arg1 = "E";
			double Arg2 = 84.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,40,40};
			string Arg1 = "NSE";
			double Arg2 = 140.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearNSWE ___test;
	___test.run_test(-1);
}
// END CUT HERE
