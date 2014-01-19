// BEGIN CUT HERE 
/*
// SRM 505 Div2 Easy (250)

問題

各フレーズの先頭だけを大文字にする。

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
	// example 0
	// Returns: "Hello programmer. Welcome to topcoder."
	Test("hello programmer. welcome to topcoder.");

	// example 1
	Test("one.");
	// Returns: "One."

	// example 2
	// Returns: "Not really. English. Qwertyuio. A. Xyz."
	Test("not really. english. qwertyuio. a. xyz.");

	// example 3
	// Returns: "Example four. The long fourth example. A. B. C. D."
	Test("example four. the long fourth example. a. b. c. d.");

	return 0;
}
// END CUT HERE
