// BEGIN CUT HERE
/*
SRM 648 Div2 Easy (250)

PROBLEM STATEMENT
This problem statement contains superscripts that may not display properly outside the applet.

Kitayuta Mart is the largest supermarket in Shuseki Kingdom, offering a great variety of food and household products. The main products are fruits, especially apples. The price system is a little special: the original price of an apple is K yen (the currency of the kingdom). However, if a customer wants to buy more than one apple, the second apple will cost 2*K yen, the third apple will cost 22*K yen, and so on. In general, if a customer is buying n apples, the actual price of the i-th (1 <= i <= n) apple will be 2i-1*K yen.

Lun the dog loves apples. She has just bought some number of apples at Kitayuta Mart. The prices of those apples were calculated using the above formula. The total she paid for her apples was T yen. You are given two ints: K and T. Find and return the number of the apples that Lun has bought. It is guaranteed that K and T are such that the answer exists and is unique.


DEFINITION
Class:KitayutaMart2
Method:numBought
Parameters:int, int
Returns:int
Method signature:int numBought(int K, int T)


CONSTRAINTS
-K will be between 80 and 160, inclusive.
-T will be between 80 and 163,680, inclusive.
-The input will be such that the answer exists and is unique.


EXAMPLES

0)
100
100

Returns: 1

If she buys only one apple, the price will just be K yen.


1)
100
300

Returns: 2

The second apple will cost 2*100 = 200 yen, for the total price of 100 + 200 = 300 yen.


2)
150
1050

Returns: 3

150 + 2*150 + 22*150 = 150 + 300 + 600 = 1050.


3)
160
163680

Returns: 10

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class KitayutaMart2 {
public:
	int numBought(int K, int T) {
		int ans = 0;
		while (T >= K) {
			++ans;
			T -= K;
			K *= 2;
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
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 1;

			verify_case(n, Arg2, numBought(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 300;
			int Arg2 = 2;

			verify_case(n, Arg2, numBought(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 150;
			int Arg1 = 1050;
			int Arg2 = 3;

			verify_case(n, Arg2, numBought(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 160;
			int Arg1 = 163680;
			int Arg2 = 10;

			verify_case(n, Arg2, numBought(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KitayutaMart2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
