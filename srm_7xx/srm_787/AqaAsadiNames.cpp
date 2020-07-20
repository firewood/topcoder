// BEGIN CUT HERE
/*
SRM 787 Div2 Easy (250)

PROBLEM STATEMENT

This problem is about a traditional way of naming the second child in a family. Aqa Asadi wants to name his second child this way.

All people in this problem have exactly two names, e.g., ÅgYasaman SadatÅh or ÅgMohammad RezaÅh.
In this problem, we will assume that the people whose first name starts with a vowel are female and all other people are male.
Note that in this problem the letter Y is considered a vowel (so the vowels are A, E, I, O, U, and Y).

You are given the strings Dad, Mom and FirstChild: the names of a dad, a mom, and their first child.
You are also given the string Gender: the gender of their second child (either "Boy" or "Girl").
Your task is to determine and return the name for the second child according to the rules given below.

If the gender of the first child differs from the second child, the second child will use both names of their parent with the same gender, in reversed order.

If both children have the same gender, the second child will get its first name from the parent with the same gender as itself (i.e., girls from their mom, boys from their dad) and its second name from its older sibling.


DEFINITION
Class:AqaAsadiNames
Method:getName
Parameters:string, string, string, string
Returns:string
Method signature:string getName(string Dad, string Mom, string FirstChild, string Gender)


NOTES
-You should always follow the rules in the problem statement, even if the name they produce does not match the child's gender (see Example #1) or produces the same name as the first child had (see Example #4).


CONSTRAINTS
-Each name (Dad, Mom, FirstChild) will contain at most 20 characters.
-Each name will have the form "First Second", with exactly one space and with exactly the first letter of each name in uppercase.
-Each name will only consist of uppercase and lowercase English letters (A-Z, a-z), and the single space between the two names.
-Dad will start with a consonant and Mom will start with a vowel (AEIOUY).
-Gender will be either "Boy" or "Girl".


EXAMPLES

0)
"Mohammad Reza"
"Yasaman Sadat"
"Baqer Ali"
"Boy"

Returns: "Mohammad Ali"

Both children are boys, so the second child gets his first name ("Mohammad") from his father and his second name ("Ali") from his brother.


1)
"Mohammad Reza"
"Yasaman Sadat"
"Baqer Ali"
"Girl"

Returns: "Sadat Yasaman"

The children have different genders. Thus, the second child's name is obtained by swapping her mother's two names.
Note that the returned name is not a proper name for a girl, but that's what the rules produced, so that's what you should return.


2)
"Mohammad Reza"
"Yasaman Sadat"
"Umi Kulsum"
"Girl"

Returns: "Yasaman Kulsum"

A case similar to Example #0, but this time the child gets her name by combining the names of her mother and her sister.


3)
"Mohammad Reza"
"Yasaman Sadat"
"Umi Kulsum"
"Boy"

Returns: "Reza Mohammad"


4)
"Mohammad Ali"
"Yasaman Sadat"
"Mohammad Reza"
"Boy"

Returns: "Mohammad Reza"


5)
"Dhikrullah Ali"
"Umi Kulsum"
"Reza Hosseinzadeh"
"Boy"

Returns: "Dhikrullah Hosseinzadeh"

Note that the second child's name can sometimes have more than 20 characters.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class AqaAsadiNames {
public:
	string getName(string Dad, string Mom, string FirstChild, string Gender) {
		bool female = string("AEIOUY").find(FirstChild[0]) != string::npos;
		bool same = female == (Gender == "Girl");
		string ans;
		if (same) {
			string parent = female ? Mom : Dad;
			ans = parent.substr(0, parent.find(' ')) + FirstChild.substr(FirstChild.find(' '));
		} else {
			string parent = Gender == "Girl" ? Mom : Dad;
			ans = parent.substr(parent.find(' ') + 1) + " " + parent.substr(0, parent.find(' '));
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
			string Arg0 = "Mohammad Reza";
			string Arg1 = "Yasaman Sadat";
			string Arg2 = "Baqer Ali";
			string Arg3 = "Boy";
			string Arg4 = "Mohammad Ali";

			verify_case(n, Arg4, getName(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Mohammad Reza";
			string Arg1 = "Yasaman Sadat";
			string Arg2 = "Baqer Ali";
			string Arg3 = "Girl";
			string Arg4 = "Sadat Yasaman";

			verify_case(n, Arg4, getName(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Mohammad Reza";
			string Arg1 = "Yasaman Sadat";
			string Arg2 = "Umi Kulsum";
			string Arg3 = "Girl";
			string Arg4 = "Yasaman Kulsum";

			verify_case(n, Arg4, getName(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Mohammad Reza";
			string Arg1 = "Yasaman Sadat";
			string Arg2 = "Umi Kulsum";
			string Arg3 = "Boy";
			string Arg4 = "Reza Mohammad";

			verify_case(n, Arg4, getName(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Mohammad Ali";
			string Arg1 = "Yasaman Sadat";
			string Arg2 = "Mohammad Reza";
			string Arg3 = "Boy";
			string Arg4 = "Mohammad Reza";

			verify_case(n, Arg4, getName(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Dhikrullah Ali";
			string Arg1 = "Umi Kulsum";
			string Arg2 = "Reza Hosseinzadeh";
			string Arg3 = "Boy";
			string Arg4 = "Dhikrullah Hosseinzadeh";

			verify_case(n, Arg4, getName(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AqaAsadiNames ___test;
	___test.run_test(-1);
}
// END CUT HERE
