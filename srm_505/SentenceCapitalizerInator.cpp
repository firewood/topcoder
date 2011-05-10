// BEGIN CUT HERE 
/*
// SRM 505 Div2 Easy
// PROBLEM STATEMENT
// You are given a simple paragraph containing a number of sentences, the original person who wrote the paragraph was in a rush and used only lower case letters ('a'-'z') for the words in the paragraph and did not use any punctuation other than a period to separate sentences. Your task is to fix the capitalization in the paragraph, the objective is to make it so every sentence in the paragraph begins with a capital (upper case) letter ('A'-'Z').

The paragraph is formatted as one or more sentences separated by single space (' ') characters. Each sentence consists of one or more words separated by single space (' ') characters. The last word in a sentence is always immediately followed by a single dot ('.') character. Each word is a non-empty string containing only lower case letters ('a'-'z'). As an example, consider the following paragraph (quotes for clarity):


"this is merely an example. be careful. this is a new sentence."

The result of your program must then be as follows:


"This is merely an example. Be careful. This is a new sentence."








DEFINITION
Class:SentenceCapitalizerInator
Method:fixCaps
Parameters:string
Returns:string
Method signature:string fixCaps(string paragraph)


CONSTRAINTS
-paragraph will contain between 2 and 50 characters, inclusive.
-Each character in paragraph will be a lower case letter ('a'-'z'), a space (' ') or a dot ('.').
-The first character of paragraph will be a lower case letter ('a'-'z').
-The last character of paragraph will be a dot ('.').
-There will be no two consecutive space characters in paragraph.
-Every space (' ') character in paragraph will precede a letter.
-Every '.' character in paragraph except the last one will precede a space character.


EXAMPLES

0)
"hello programmer. welcome to topcoder."

Returns: "Hello programmer. Welcome to topcoder."



1)
"one."

Returns: "One."

A sentence can consist of just a single word.

2)
"not really. english. qwertyuio. a. xyz."

Returns: "Not really. English. Qwertyuio. A. Xyz."



3)
"example four. the long fourth example. a. b. c. d."

Returns: "Example four. The long fourth example. A. B. C. D."



*/
// END CUT HERE
#line 74 "SentenceCapitalizerInator.cpp"
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

class SentenceCapitalizerInator {
	public:
	string fixCaps(string paragraph) {
		size_t length = paragraph.length();
		char *p = new char[length + 1];
		strcpy(p, paragraph.c_str());
		char *w = p;
		*w = toupper(*w);
		while (w && *w) {
			w = strchr(w, ' ');
			if (!w) {
				break;
			}
			bool Capital = w > p && *(w - 1) == '.';
			++w;
			if (Capital && *w) {
				*w = toupper(*w);
			}
		}
		string s = p;
		delete [] p;
		return s;
	}
};

// BEGIN CUT HERE 
static void Test(const char *seq)
{
	SentenceCapitalizerInator ___test;
	string result = ___test.fixCaps(seq);
	printf("result: %s\n", result.c_str());
}

int main() {
	Test("hello programmer. welcome to topcoder.");
	return 0;
}
// END CUT HERE
