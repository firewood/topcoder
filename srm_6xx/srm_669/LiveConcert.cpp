// BEGIN CUT HERE
/*
SRM 669 Div2 Easy (250)

PROBLEM STATEMENT

Today, a large live concert is going to take place.
Some interprets (called "idols") are going to perform at the concert.
Different idols have different names.

There are M distinct songs that can be included in the concert.
The songs are numbered 0 through M-1.
Song i can only be performed by the idol s[i].
Including this song in the concert will increase the happiness of the audience by h[i].

We have to choose the set list for this concert.
Our goal is to make the audience as happy as possible.
However, the concert time is limited and therefore each idol can only perform at most one song.

You are given the vector <int> h and the vector <string> s with M elements each.
Find the set of songs that should be played at the concert.
The set of songs must have the following properties:

Each idol will perform at most one song.
After hearing the songs, the happiness of the audience will increase by the largest amount possible.

Return the largest possible amount of happiness the audience can gain.


DEFINITION
Class:LiveConcert
Method:maxHappiness
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int maxHappiness(vector <int> h, vector <string> s)


NOTES
-The value M is not given explicitly. You can determine M as the length of h.


CONSTRAINTS
-M will be between 1 and 100, inclusive.
-h and s will contain exactly M elements each.
-All numbers in h will be between 1 and 100, inclusive.
-All strings in s will have between 1 and 10 characters, inclusive.
-For each valid i, each character in s[i] will be a lowercase letter ('a'-'z').


EXAMPLES

0)
{10,5,6,7,1,2}
{"ciel","bessie","john","bessie","bessie","john"}

Returns: 23

The optimal concert will contain three songs:

"ciel" will sing the song number 0, which will give the audience 10 happiness
"bessie" will sing the song number 3, which will give the audience 7 happiness
"john" will sing the song number 2, which will give the audience 6 happiness

The total amount of happiness will be 10+7+6 = 23.


1)
{3,3,4,3,3}
{"a","a","a","a","a"}

Returns: 4

There is a single idol, thus the concert will consist of a single song.
The optimal choice is the song that gives 4 happiness.


2)
{1,2,3,4,5,6,7,8,9,10,100}
{"a","b","c","d","e","e","d","c","b","a","abcde"}

Returns: 140


3)
{100}
{"oyusop"}

Returns: 100


4)
{100,100,100,100,100,100,100,100,100,100,100,100,100}
{"haruka","chihaya","yayoi","iori","yukiho","makoto","ami","mami","azusa","miki","hibiki","takane","ritsuko"}

Returns: 1300

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class LiveConcert {
public:
	int maxHappiness(vector <int> h, vector <string> s) {
		map<string, int> t;
		for (int i = 0; i != h.size(); ++i) {
			t[s[i]] = max(t[s[i]], h[i]);
		}
		map<string, int>::const_iterator it;
		int ans = 0;
		for (it = t.begin(); it != t.end(); ++it) {
			ans += it->second;
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
			int Arr0[] = {10,5,6,7,1,2};
			string Arr1[] = {"ciel","bessie","john","bessie","bessie","john"};
			int Arg2 = 23;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxHappiness(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3,4,3,3};
			string Arr1[] = {"a","a","a","a","a"};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxHappiness(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10,100};
			string Arr1[] = {"a","b","c","d","e","e","d","c","b","a","abcde"};
			int Arg2 = 140;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxHappiness(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100};
			string Arr1[] = {"oyusop"};
			int Arg2 = 100;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxHappiness(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,100,100,100,100,100,100,100,100,100,100,100,100};
			string Arr1[] = {"haruka","chihaya","yayoi","iori","yukiho","makoto","ami","mami","azusa","miki","hibiki","takane","ritsuko"};
			int Arg2 = 1300;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxHappiness(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LiveConcert ___test;
	___test.run_test(-1);
}
// END CUT HERE
