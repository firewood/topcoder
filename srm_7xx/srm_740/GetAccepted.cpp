// BEGIN CUT HERE
/*
SRM 740 Div2 Easy (250)

PROBLEM STATEMENT

For this task we have created a simple automated system.
It was supposed to ask you a question by giving you a string question.
You would have returned a string with the answer, and that would be all.
Here is the entire conversation the way we planned it:

"Do you want to get accepted?"
"True."

Unluckily for you, a hacker got into our system and modified it by inserting negations into the sentence. Each negation completely changes the meaning of the question to the opposite one, which means that you need to give us the opposite answer.

Write a program that will read the question and answer accordingly.
More precisely, your program must return either the string "True." if the question you are given has the same meaning as the one shown above or the string "False." if the question has the opposite meaning.


DEFINITION
Class:GetAccepted
Method:answer
Parameters:string
Returns:string
Method signature:string answer(string question)


NOTES
-All strings in this problem are case-sensitive. In particular, make sure the strings your program returns have correct uppercase and lowercase letters, as shown in the statement and examples.


CONSTRAINTS
-question will always have the following form: "Do you " + X + "want to " + Y + "get " + Z + "accepted?", where each of X, Y and Z is the concatenation of zero or more copies of the string "not ".
-question will have at most 1000 characters.


EXAMPLES

0)
"Do you want to get accepted?"

Returns: "True."

This is the original question, you should give the original answer.


1)
"Do you not want to get accepted?"

Returns: "False."

This question has the opposite meaning from the original, you should give the opposite answer.


2)
"Do you want to not get accepted?"

Returns: "False."

This is another possible negation of the original question.


3)
"Do you want to get not not accepted?"

Returns: "True."

Two negations cancel each other out. The meaning of this question is the same as the meaning of the original question, so you should answer "True.".


4)
"Do you not want to not get not not not accepted?"

Returns: "False."

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class GetAccepted {
public:
	string answer(string question) {
		map<string, int> m;
		string ans;
		stringstream ss(question);
		string x = " ";
		while (!x.empty()) {
			x.clear();
			ss >> x;
			m[x] += 1;
		}
		return m["not"] % 2 ? "False." : "True.";
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
			string Arg0 = "Do you want to get accepted?";
			string Arg1 = "True.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Do you not want to get accepted?";
			string Arg1 = "False.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Do you want to not get accepted?";
			string Arg1 = "False.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Do you want to get not not accepted?";
			string Arg1 = "True.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Do you not want to not get not not not accepted?";
			string Arg1 = "False.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GetAccepted ___test;
	___test.run_test(-1);
}
// END CUT HERE
