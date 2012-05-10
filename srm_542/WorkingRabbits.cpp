// BEGIN CUT HERE
/*
// SRM 542 Div2 Easy (250)

// PROBLEM STATEMENT
// N rabbits (numbered 0 through N - 1) are going to work together at the new TopCoder office in Rabbitland. 

Each pair of rabbits will make a certain profit when they work together. 
The efficiency of the group of rabbits is defined as follows: 
Let P be the sum of profits from all pairs of rabbits, and Q be the number of pairs of rabbits. 
Then the efficiency is the real number P / Q. 

You are given a vector <string> profit, 
the j-th character of the i-th element of which represents the profit from the fact that rabbits i and j work together. 
The characters '0', '1', ..., '9' represent the values 0, 1, ..., 9, respectively. 
Compute and return the efficiency of this TopCoder office. 


DEFINITION
Class:WorkingRabbits
Method:getEfficiency
Parameters:vector <string>
Returns:double
Method signature:double getEfficiency(vector <string> profit)


NOTES
-The returned value must have an absolute or relative error less than 1e-9. 


CONSTRAINTS
-profit will contain between 2 and 50 elements, inclusive. 
-Each element of profit will contain exactly N characters, where N is the number of elements in profit. 
-Each character in each element of profit will be a digit ('0' - '9'). 
-For each index i and j, the i-th character of the j-th element of profit will be equal to the j-th character of the i-th element of profit. 
-For each index i, the i-th character of the i-th element of profit will be '0'. 


EXAMPLES

0)
{ "071", 
  "702", 
  "120" }


Returns: 3.3333333333333335

There are three pairs of rabbits: 

	rabbit 0 and rabbit 1 (profit 7)
	rabbit 0 and rabbit 2 (profit 1)
	rabbit 1 and rabbit 2 (profit 2)

So P = 7 + 1 + 2, Q = 3, and the efficiency is P / Q = 10/3. 


1)
{ "00", 
  "00" }


Returns: 0.0


2)
{ "0999", 
  "9099", 
  "9909", 
  "9990" }

Returns: 9.0


3)
{ "013040", 
  "100010", 
  "300060", 
  "000008", 
  "416000", 
  "000800" }

Returns: 1.5333333333333334


4)
{ "06390061", 
  "60960062", 
  "39090270", 
  "96900262", 
  "00000212", 
  "00222026", 
  "66761201", 
  "12022610" }

Returns: 3.2142857142857144

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WorkingRabbits {

public:
	double getEfficiency(vector <string> profit) {
		double res = 0;
		unsigned int i, j;
		for (i = 0; i < profit.size(); ++i) {
			for (j = i+1; j < profit.size(); ++j) {
				res += profit[i][j] - '0';
			}
		}
		res /= (double)(profit.size() * (profit.size() -1) / 2);
		return res;
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
			string Arr0[] = { "071", 
  "702", 
  "120" }
;
			double Arg1 = 3.3333333333333335;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getEfficiency(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "00", 
  "00" }
;
			double Arg1 = 0.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getEfficiency(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "0999", 
  "9099", 
  "9909", 
  "9990" }
;
			double Arg1 = 9.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getEfficiency(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "013040", 
  "100010", 
  "300060", 
  "000008", 
  "416000", 
  "000800" }
;
			double Arg1 = 1.5333333333333334;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getEfficiency(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "06390061", 
  "60960062", 
  "39090270", 
  "96900262", 
  "00000212", 
  "00222026", 
  "66761201", 
  "12022610" }
;
			double Arg1 = 3.2142857142857144;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getEfficiency(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WorkingRabbits ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
