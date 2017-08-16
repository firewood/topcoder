// BEGIN CUT HERE
/*
SRM 719 Div2 Easy (250)

PROBLEM STATEMENT
Zhangzj is the emperor of Yali empire and is esteemed by his people.

"Long live Zhangzj" is heard across the country. Needless to say, people in the empire hope their leader will live forever. However, everybody will die, unless others donate their lives to the person.

In the empire, there's a special way to donate life. There are some fixed words that are called exciting. Whenever someone speaks an exciting word, he automatically donates one second of his life to Zhangzj. For example, "toad" and "river" are exciting. Then, if somebody says the sequence of words "a", "toad", "jumps", "into", "the", "toad", "river", they donate three seconds to Zhangzj.

Given a vector <string> speech containing all the words someone says, and a vector <string> words containing all exciting words, return the number of seconds the speaker will donate to Zhangzj.

A word may appear multiple times in speech, but not in words.


DEFINITION
Class:LongLiveZhangzj
Method:donate
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int donate(vector <string> speech, vector <string> words)


CONSTRAINTS
-Both speech and words will contain between 1 and 50 elements, inclusive.
-All pairs of elements in words will be distinct.
-Each element of speech and words will consist only of lowercase English letters.
-The length of each element of speech and words will be between 1 and 50, inclusive.


EXAMPLES

0)
{"make", "topcoder", "great", "again"}
{"make", "america", "great", "again"}

Returns: 3

"make", "great" and "again" appear in speech and are exciting. Thus, the answer is 3.


1)
{"toads"}
{"toad"}

Returns: 0

The strings "toad" and "toads" are not identical, therefore this speaker does not donate any seconds to Zhangzj.


2)
{"a", "a"}
{"a"}

Returns: 2

Two elements of speech can be the same.


3)
{"je", "le", "ai", "deja", "vu", "et", "je", "le", "veux", "encore"}
{"i", "am", "having", "deja", "vu", "please", "stop", "the", "encore"}

Returns: 3

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class LongLiveZhangzj {
public:
	int donate(vector <string> speech, vector <string> words) {
		set<string> w(words.begin(), words.end());
		int ans = 0;
		for (const string &s : speech) {
			ans += w.find(s) != w.end();
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
			string Arr0[] = {"make", "topcoder", "great", "again"};
			string Arr1[] = {"make", "america", "great", "again"};
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, donate(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"toads"};
			string Arr1[] = {"toad"};
			int Arg2 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, donate(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a", "a"};
			string Arr1[] = {"a"};
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, donate(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"je", "le", "ai", "deja", "vu", "et", "je", "le", "veux", "encore"};
			string Arr1[] = {"i", "am", "having", "deja", "vu", "please", "stop", "the", "encore"};
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, donate(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongLiveZhangzj ___test;
	___test.run_test(-1);
}
// END CUT HERE
