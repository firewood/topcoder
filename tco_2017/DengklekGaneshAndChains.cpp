// BEGIN CUT HERE
/*
TCO 2017 R2B Easy (300)

PROBLEM STATEMENT
Dengklek works as a chain maker. He currently owns N chains. Each chain is a circular chain that consists of K links. There is a letter engraved on each link of each chain.
You are given the vector <string> chains with N elements, each containing exactly K characters. Each element of chains contains the characters written on one of the chains, in order.

Ganesh is Dengklek's best friend. Tomorrow is his birthday. Dengklek wants to give Ganesh a straight (non-circular) chain as a present. He will do so by cutting and then combining some pieces of the chains he currently owns.

More precisely, you are given a vector <int> lengths that contains M elements. Dengklek will construct the new chain as follows:

  At the beginning, the chain for Ganesh is empty.
  For each i from 0 to M-1:
  
    Dengklek will pick one of his circular chains that has not been picked before.
    Dengklek will cut a contiguous sequence of lengths[i] links from the chain. He will keep the sequence and discard the remaining links. (In particular, if lengths[i] = K, Dengklek just splits the chosen chain at some point of his choice to turn it from a circular to a straight sequence. No links are lost while doing so.)
    Dengklek will attach the sequence he just produced to the end of the chain for Ganesh.

Note that Dengklek's current chains are circular, so the last link of each chain is adjacent to the first link of that chain. Dengklek may choose a sequence that contains this part of the chain.

Note that Dengklek's chains are not symmetric. This means that Dengklek is not allowed to reverse the order of the links in any of the sequences he chooses.

Return the lexicographically largest possible string that can appear on the chain Dengklek gives to Ganesh.


DEFINITION
Class:DengklekGaneshAndChains
Method:getBestChains
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string getBestChains(vector <string> chains, vector <int> lengths)


NOTES
-Given two distinct strings of the same length, the lexicographically larger one is the one that has a larger character on the first position on which they differ.


CONSTRAINTS
-N and K will each be between 1 and 50, inclusive.
-chains will contain exactly N elements.
-Each element of chains will contain exactly K characters.
-Each character of chains will be a lowercase English letter ('a' to 'z').
-M will be between 1 and N, inclusive.
-lengths will contain exactly M elements, inclusive.
-Each element of lengths will be between 1 and K, inclusive.


EXAMPLES

0)
{"topc", "oder", "open", "twob"}
{2, 1, 3}

Returns: "wotrod"

The optimal solution is as follows:

Dengklek picks "twob" and cuts "wo" from it.
Dengklek picks "topc" and cuts "t" from it.
Dengklek picks "oder" and cuts "rod" from it. This is possible because the chain is circular, so 'r' and 'o' are adjacent.

The resulting chain is "wo" + "t" + "rod" = "wotrod".


1)
{"ssh", "she", "see", "sea"}
{2, 3, 2, 3}

Returns: "ssshesesee"

The optimal solution is as follows:

Dengklek picks "ssh" and cuts "ss" from it.
Dengklek picks "she" and cuts "she" from it.
Dengklek picks "sea" and cuts "se" from it.
Dengklek picks "see" and cuts "see" from it.

The resulting chain is "ss" + "she" + "se" + "see" = "ssshesesee".


2)
{"wri", "ter", "who", "are", "you"}
{3}

Returns: "you"


3)
{"harus", "imfyo"}
{5, 5}

Returns: "yoimfushar"

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DengklekGaneshAndChains {
public:
	string getBestChains(vector <string> chains, vector <int> lengths) {
		string ans;
		int n = (int)chains.size(), k = (int)chains[0].length();
		for (int i = 0; i < n; ++i) {
			string m = chains[i];
			for (int j = 1; j < k; ++j) {
				m = max(m, chains[i].substr(j) + chains[i].substr(0, j));
			}
			chains[i] = m;
		}
		sort(chains.begin(), chains.end());
		int used[64] = {};
		for (int len : lengths) {
			int j = -1;
			string s;
			for (int i = 0; i < n; ++i) {
				if (!used[i]) {
					if (j < 0 || s < chains[i].substr(0, len)) {
						j = i;
						s = chains[i].substr(0, len);
					}
				}
			}
			used[j] = 1;
			ans += s;
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
			string Arr0[] = {"topc", "oder", "open", "twob"};
			int Arr1[] = {2, 1, 3};
			string Arg2 = "wotrod";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getBestChains(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ssh", "she", "see", "sea"};
			int Arr1[] = {2, 3, 2, 3};
			string Arg2 = "ssshesesee";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getBestChains(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"wri", "ter", "who", "are", "you"};
			int Arr1[] = {3};
			string Arg2 = "you";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getBestChains(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"harus", "imfyo"};
			int Arr1[] = {5, 5};
			string Arg2 = "yoimfushar";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getBestChains(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DengklekGaneshAndChains ___test;
	___test.run_test(-1);
}
// END CUT HERE
