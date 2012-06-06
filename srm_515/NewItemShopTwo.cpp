// BEGIN CUT HERE
/*
// SRM 515 Div2 Hard (1000)

// PROBLEM STATEMENT
// Lecette is going to open an item shop. 
On the first day, she will sell only one magical sword. 
She will keep the shop open for the whole day, from 00:00 to 23:59. 

Since the shop is new, Lecette has only two customers so far, and she has a lot of information about them.
The information is given as vector <string> customers with exactly 2 elements. 
Each element represents a single customer who may come to the shop at some point during the day. 
It is formatted as 
"T1,C1,P1
 T2,C2,P2
 ...
 TN,CN,PN"
 (quotes for clarity), where N is a positive integer. 
An occurrence of three integers Tj, Cj and Pj 
within customers[i] means that the following event will happen with a probability of Pj percent: 
the i-th customer comes to the shop at Tj o'clock 
and offers to buy a magical sword at a price of Cj units of money. 
The same customer never comes to the shop more than once. 
That is, the customer does not come to the shop during the day 
with a probability of 100 - (P1 + P2 + ... + PN) percent. 
The values of Tj are such that at most one customer can come to the shop during each hour of the day 
(see the constraints for further clarification). 

When a customer comes to the shop, Lecette can choose to either accept or reject the offer. 
Let's define S as the amount of money that Lecette will get for the sword (or 0 if she will not sell it). 
Lecette will act in such a way that maximizes the expected value of S. Return this expected value. 


DEFINITION
Class:NewItemShopTwo
Method:getMaximum
Parameters:vector <string>
Returns:double
Method signature:double getMaximum(vector <string> customers)


NOTES
-The returned value must have an absolute or relative error less than 1e-9. 


CONSTRAINTS
-customers will contain exactly 2 elements. 
-Each element of customers will contain between 5 and 50 characters, inclusive. 
-Each element of customers will be formatted as "T1,C1,P1 T2,C2,P2 ... TN,CN,PN", where Each Tj, Cj and Pj will be nonnegative integers without extra leading zeros. 
-Each Tj will be between 0 and 23, inclusive. 
-Each Cj will be between 1 and 100, inclusive. 
-Each Pj will be between 1 and 100, inclusive. 
-For each t, 0 <= t < 24, there will be at most one pair (i, j) such that the value of Tj in customers[i] is equal to t. 
-In each element of customers, T1 < T2 < ... < TN will hold. 
-In each element of customers, P1 + P2 + ... + PN will not exceed 100. 


EXAMPLES

0)
{ "8,1,80 16,100,11", "12,10,100" }

Returns: 19.0

The optimal strategy is as follows: 
At 08:00, Lecette should not sell the sword even if the first customer comes to the shop. 
At 12:00, the second customer surely comes. Then, 

	If the first customer has come at 08:00, she should sell the sword to the second customer. 
	Otherwise, she should not sell the sword to the second customer. She should sell it at 16:00 if possible. 

By this strategy, S will be 10 (80%) or 100 (11%) or 0 (9%). 


1)
{ "8,1,80 16,100,11", "12,10,90 13,30,5" }

Returns: 19.4


2)
{ "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" }

Returns: 90.0


3)
{ "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,95" }

Returns: 95.0


4)
{ "0,3,1 2,4,1 4,5,9 6,2,6 8,5,3 10,5,8 12,9,7 14,9,3", 
  "1,2,3 3,8,4 5,6,2 7,6,4 9,3,3 11,8,3 13,2,7 15,9,5" }

Returns: 3.0692999999999997

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class NewItemShopTwo {

public:
	double getMaximum(vector <string> customers) {
		int index[25];
		double price[25] = {};
		double probability[25] = {};
		memset(index, -1, sizeof(index));
		int i, h;
		for (i = 0; i < 2; ++i) {
			double r = 100.0;
			stringstream ss(customers[i]);
			while (true) {
				h = -1;
				int a, b;
				char c;
				ss >> h >> c >> a >> c >> b;
				if (h < 0 || h >= 24) break;
				index[h] = i;
				price[h] = a;
				probability[h] = b / r;
				r -= b;
			}
		}

		double earn[25][2] = {};
		for (h = 24-1; h >= 0; --h) {
			for (i = 0; i < 2; ++i) {
				earn[h][i] = earn[h+1][i];
				if (index[h] == i) {
					earn[h][i] = price[h] * probability[h] + (1.0 - probability[h]) * earn[h+1][i];
				}
			}
		}
		double dp[25] = {};
		for (h = 24-1; h >= 0; --h) {
			dp[h] = dp[h+1];
			for (i = 0; i < 2; ++i) {
				if (index[h] == i) {
					dp[h] = probability[h] * max(price[h], earn[h][i^1]) + (1.0 - probability[h]) * dp[h+1];
				}
			}
		}
		return dp[0];
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
			string Arr0[] = { "8,1,80 16,100,11", "12,10,100" };
			double Arg1 = 19.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "8,1,80 16,100,11", "12,10,90 13,30,5" };
			double Arg1 = 19.4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" };
			double Arg1 = 90.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,95" };
			double Arg1 = 95.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "0,3,1 2,4,1 4,5,9 6,2,6 8,5,3 10,5,8 12,9,7 14,9,3", 
  "1,2,3 3,8,4 5,6,2 7,6,4 9,3,3 11,8,3 13,2,7 15,9,5" }
;
			double Arg1 = 3.0692999999999997;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NewItemShopTwo ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
