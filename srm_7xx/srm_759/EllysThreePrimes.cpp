// BEGIN CUT HERE
/*
SRM 759 Div1 Easy (250)

PROBLEM STATEMENT

Kriss told Elly her three favorite five-digit prime numbers. Elly was lazy to remember them exactly,
so she decided that she will write them below each other and she will only remember the sum of digits in each column.
For example, if Kriss likes the primes 42649, 18287, and 91703, Elly will write them as follows:

    42649
    18287
    91703

Then, she will sum each column of digits separately, from the right to the left
(i.e., starting with the ones digit of each number).
In our example, the sums she will get are 9+7+3 = 19, 4+8+0 = 12, 6+2+7 = 15, 2+8+1 = 11, and 4+1+9 = 14.

Elly thought that it would be easy to reconstruct the numbers Kriss told her from the sums she remembers.
It turns out that not only is it hard (since the answer can be ambiguous),
but already finding any three distinct five-digit prime numbers that satisfy the conditions isn't trivial.

Now Elly has given you the five sums she remembers in the vector <int> sums,
where sums[i] is the sum of digits that correspond to 10^i.
Return a vector <int> with three elements - three distinct five-digit prime numbers,
whose digits sum to the given numbers.
If Elly didn't remember some of the numbers correctly and an answer doesn't exist,
return an empty vector <int> instead.


DEFINITION
Class:EllysThreePrimes
Method:getPrimes
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> getPrimes(vector <int> sums)


NOTES
-A prime number (or a prime) is a natural number greater than 1 that cannot be formed by multiplying
 two smaller natural numbers. (Wikipedia)
-The five-digit primes cannot have leading zeros. For example, 00047 is not a five-digit prime.


CONSTRAINTS
-sums will contain exactly 5 elements.
-Each element of sums will be between 0 and 27, inclusive.


EXAMPLES

0)
{19, 12, 15, 11, 14}

Returns: {20533, 87119, 44987 }

You don't necessarily need to return the primes Kriss gave to Elly. You may return any three different ones that satisfy the conditions.


1)
{22, 19, 3, 8, 23}

Returns: { }

In this case Elly doesn't remember the sums properly, as there are no three different primes whose digits sum to these numbers.


2)
{13, 17, 0, 25, 20}

Returns: {27011, 99083, 99089 }


3)
{11, 12, 13, 14, 15}

Returns: {47221, 23789, 94421 }


4)
{14, 27, 6, 12, 15}

Returns: { }

No three five-digit primes have an even sum of the units digits.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysThreePrimes {
	vector<int> is_prime;
	vector<int> primes;
	vector< vector<int> > digits;
public:
	vector <int> getPrimes(vector <int> sums) {
		if (is_prime.empty()) {
			is_prime.resize(100000, 1);
			for (int i = 2; i < 100000; ++i) {
				if (is_prime[i]) {
					for (int j = i * 2; j < 100000; j += i) {
						is_prime[j] = 0;
					}
					if (i >= 10000) {
						primes.push_back(i);
						vector<int> d;
						for (int x = i; x > 0; x /= 10) {
							d.push_back(x % 10);
						}
						digits.push_back(d);
					}
				}
			}
		}
		for (int i = 0; i < (int)primes.size(); ++i) {
			for (int j = i + 1; j < (int)primes.size(); ++j) {
				int x = 0, z = 1;
				for (int k = 0; k < 5; ++k) {
					int y = sums[k] - digits[i][k] - digits[j][k];
					if (y < 0 || y > 9) {
						x = 4;
						break;
					}
					x += y * z;
					z *= 10;
				}
				if (x > primes[j] && is_prime[x]) {
					return { primes[i], primes[j], x };
				}
			}
		}
		return {};
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {19, 12, 15, 11, 14};
			int Arr1[] = {20533, 87119, 44987 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getPrimes(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {22, 19, 3, 8, 23};
//			int Arr1[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, getPrimes(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13, 17, 0, 25, 20};
			int Arr1[] = {27011, 99083, 99089 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getPrimes(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {11, 12, 13, 14, 15};
			int Arr1[] = {47221, 23789, 94421 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getPrimes(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {14, 27, 6, 12, 15};
//			int Arr1[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, getPrimes(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = {17, 0, 0, 0, 2};
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, getPrimes(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysThreePrimes ___test;
	___test.run_test(-1);
}
// END CUT HERE
