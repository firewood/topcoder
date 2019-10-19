// BEGIN CUT HERE
/*
SRM 769 Div1 Easy (250)

PROBLEM STATEMENT

An integer is a prime number if it has exactly two positive integer divisors. The first few prime numbers are P[0]=2, P[1]=3, P[2]=5, and so on.

Let alphabet[x] denote the x-th (0-based index) lowercase letter of the English alphabet. For example, alphabet[0]='a' and alphabet[24]='y'.

You are given the ints N and E.
Generate an N-character string by concatenating alphabet[P[i] mod 26] for i=0..N-1.
Then, produce the lexicographically largest possible string by erasing exactly E of those characters.
Return that string.


DEFINITION
Class:PrimePruning
Method:maximize
Parameters:int, int
Returns:string
Method signature:string maximize(int N, int E)


CONSTRAINTS
-N will be between 1 and 10^9, inclusive.
-E will be between max(0,N-1000) and N-1, inclusive.


EXAMPLES

0)
10
0

Returns: "cdfhlnrtxd"

We generate a 10-character string using the first 10 primes, and then we don't erase anything.


1)
30
5

Returns: "nrtxdflprvbhjptvbfltxzdfj"

When erasing 5 characters out of the first 30, the optimal solution happens to be erasing the first five.


2)
30
15

Returns: "xvjptvbfltxzdfj"

When erasing 15 characters out of the first 30, the optimal strategy is no longer the same as above.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PrimePruning {
	vector<int> is_prime;
	vector<int> primes;
public:
	string maximize(int N, int E) {
		if (is_prime.empty()) {
			is_prime.resize(32000, 1);
			for (int i = 2; i < 32000; ++i) {
				if (is_prime[i]) {
					for (int j = i * 2; j < 32000; j += i) {
						is_prime[j] = 0;
					}
					primes.push_back(i);
				}
			}
		}
		int len = N - E;
		string ans(len, 'z');
		if (N < 14000) {
			vector<int> p;
			for (int i = 2; p.size() < N; ++i) {
				for (int x : primes) {
					if (x * x > i) {
						p.push_back(i % 26);
						break;
					}
					if ((i % x) == 0) {
						break;
					}
				}
			}
			for (int i = len; i < N; ++i) {
				p[len] = p[i];
				for (int j = 0; j < len; ++j) {
					if (p[j] < p[j + 1]) {
						for (int k = j; k < len; ++k) {
							p[k] = p[k + 1];
						}
						break;
					}
				}
			}
			for (int i = 0; i < len; ++i) {
				ans[i] = 'a' + p[i];
			}
		}
		return ans;
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
			int Arg0 = 10;
			int Arg1 = 0;
			string Arg2 = "cdfhlnrtxd";

			verify_case(n, Arg2, maximize(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30;
			int Arg1 = 5;
			string Arg2 = "nrtxdflprvbhjptvbfltxzdfj";

			verify_case(n, Arg2, maximize(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30;
			int Arg1 = 15;
			string Arg2 = "xvjptvbfltxzdfj";

			verify_case(n, Arg2, maximize(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 13000;
			int Arg1 = 12000;
			string Arg2 = string(1000, 'z');

			verify_case(n, Arg2, maximize(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PrimePruning ___test;
	___test.run_test(-1);
}
// END CUT HERE
