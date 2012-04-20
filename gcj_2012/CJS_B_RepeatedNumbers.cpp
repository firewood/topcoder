/*

Code Jam Sprint
Problem B. Repeated Numbers


Problem

Raising ducklings is a lot of work, and one of the hardest parts is
keeping track of them all. I have a system where I assign a K-digit
number to each duckling. To save space while storing the number,
I draw the numbers from a long string of N digits, so that they overlap.
For example, if I have 10 ducklings and K=2, I might have a string like
17893349714, which yields the duckling numbers
17, 78, 89, 93, 33, 34, 49, 97, 71, and 14. Thankfully these are all
unique: my system wouldn't work if I had any repetitions.

For this problem, you must design a program that, given K and a string
of digits S of length N, checks if there are any repeated K-digit numbers
in the string. If any exist, your program should determine which numbers
are repeated.


Input

The first line of the input gives the number of test cases, T. T lines
follow. Each line will consist of 2 numbers, K and S, separated by a space.


Output

For each test case, output one line containing "Case #X: Y", where X is
the case number (starting from 1) and Y is:

- NONE if there are no repeated K-digit numbers.
- A sorted, space-separated list of the unique repeated K-digit numbers.


Limits

1 <= K <= 9;
There will be no zeros in S.


Small dataset

1 <= T <= 100
1 <= N <= 1000.


Large dataset

1 <= T <= 4
1 <= N <= 25000.


Sample

Input

4
1 4793723
2 575865329
2 88989726572
3 12345123333

Output

Case #1: 3 7
Case #2: NONE
Case #3: 72 89
Case #4: 123 333

*/

#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<int> IntSet;

static string solve(int K, string s) {
	IntSet used, repeated;
	size_t pos;
	for (pos = 0; pos <= s.length() - K; ++pos) {
		int n = atoi(s.substr(pos, K).c_str());
		if (used.count(n) > 0) {
			repeated.insert(n);
		}
		used.insert(n);
	}

	ostringstream ss;
	IntSet::const_iterator it;
	for (it = repeated.begin(); it != repeated.end(); ++it) {
		if (it != repeated.begin()) {
			ss << " ";
		}
		ss << *it;
	}
	return ss.str();
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t, K;
	for (t = 0; t < T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		ss >> K;
		ss >> s;
		string result = solve(K, s);
		cout << "Case #" << (t+1) << ": " << (result.empty() ? "NONE" : result) << endl;
	}
	return 0;
}

