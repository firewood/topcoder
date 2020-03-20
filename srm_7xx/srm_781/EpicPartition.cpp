// BEGIN CUT HERE
/*
SRM 781 Div1 Easy (250)

PROBLEM STATEMENT

Ramanujan loved partitions.
And he also loved natural numbers.
So, yay!
He has a problem for you.

The set S consists of the first 6*N natural numbers. That is, S = {1, 2, ..., 6*N}.
You have to partition S into three equally-large sets A, B, C.
Additionally, this partition must be such that sum(C) = 2 * sum(A) = 2 * sum(B).

If there is no solution, return an empty string.
Otherwise, return a string of length 6*N that describes any one valid solution.
For each i, the i-th character (1-based index) of the return value should be 'a' if value i belongs to A, 'b' for B, or 'c' for C.


DEFINITION
Class:EpicPartition
Method:createPartition
Parameters:int
Returns:string
Method signature:string createPartition(int N)


CONSTRAINTS
-N will be between 1 and 100, inclusive.


EXAMPLES

0)
1

Returns: ""


1)
2

Returns: ""


2)
4

Returns: "aaabababbbbabbcccccccaac"

A = {1,2,3,4,6,18,19,22}. Sum(A) = 75.
B = {5,7,8,9,10,11,12,13}. Sum(B) = 75
C = {14,15,16,17,20,21,23,24}. Sum(C) = 150

Satisfies size(A) = 2 * 4, size(B) = 2 * 4, size(C) = 2 * 4.
And union of A,B,C = {1,2,3,...6*4}.
And sum(C) = 2 * sum(A) = 2 * sum(B)


3)
8

Returns: "abaaaaaabaabbaabbbbbbbbbbbbccccccccaaccccccacaac"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EpicPartition {
public:
	string createPartition(int N) {
		int n = N * 2;
		vector<int> a;
		int sum[3] = {};
		for (int i = 0; i < n * 3; ++i) {
			a.push_back(i + 1);
			sum[i / n] += a[i];
		}
		int all_sum = ((n * 3 + 1) * n * 3) / 2;
		if (all_sum % 4) {
			return "";
		}
		int goal = all_sum / 4;
		while (sum[0] != sum[1] || sum[0] * 2 != sum[2]) {
			auto change = [&](int goal1, int goal2, int &sum1, int &sum2, int offset1, int offset2) {
				int p = (rand() % n) + offset1, q = (rand() % n) + offset2;
				int prev = abs(sum1 - goal1) + abs(sum2 - goal2);
				int next = abs(sum1 - goal1 + a[q] - a[p]) + abs(sum2 - goal2 + a[p] - a[q]);
				if (next < prev) {
					sum1 += a[q] - a[p];
					sum2 += a[p] - a[q];
					swap(a[p], a[q]);
				}
			};
			change(goal, goal, sum[0], sum[1], 0, n);
			change(goal, goal * 2, sum[0], sum[2], 0, n * 2);
			change(goal, goal * 2, sum[1], sum[2], n, n * 2);
		}
		string ans(N * 6, 'c');
		int i;
		for (i = 0; i < n; ++i) {
			ans[a[i] - 1] = 'a';
		}
		for (; i < n * 2; ++i) {
			ans[a[i] - 1] = 'b';
		}
		return ans;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string& Expected, const string& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			string Arg1 = "";

			verify_case(n, Arg1, createPartition(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			string Arg1 = "";

			verify_case(n, Arg1, createPartition(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			string Arg1 = "aaabababbbbabbcccccccaac";

			verify_case(n, Arg1, createPartition(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 8;
			string Arg1 = "abaaaaaabaabbaabbbbbbbbbbbbccccccccaaccccccacaac";

			verify_case(n, Arg1, createPartition(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 12;
			string Arg1 = "abbaacabacabaababbaaabaabbacbbbbbbbbabbbbaaabbacacaccccccccccacccccacccc";

			verify_case(n, Arg1, createPartition(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			string Arg1 = "baacababaaabaccaaabbabcbaabcababbabbababbaabbbabacbacaaabbaabbcaababbcbabbbaaaacabaacabcaaabbacaababbaababaaaabbbcabbbaaabaacbaacaaabbaaaaabcabaaaaaaaaaabaabaaaaaaabaabaaabccaaababaaabcabbbbbaabaabbaabbabbcbbbbbabbcbbabbbabbabaaababbabbabbbbbbbbbababbbbabbbcabaabbbbbbbbbabbacbbbabbbbbbabbbaaabaabbbacbabbcbaabbbbbbbbbabbabbbabbbabbabbbababbbabbabbbaaaaaababbacabbbbbabbababbabaacbbbbabaaacabbabbabbbcaccccccacaccccccacccacccccaccccccaccccccccccccccccccccccaaccacccccccccacccccccccaaccccccaccccccccccccccccccacccccaacaccccccccaacccacccccaccccccccccccaccccaaccccccccacaacaccccccccccccccccccccccccccccc";

			verify_case(n, Arg1, createPartition(Arg0));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EpicPartition ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
