// BEGIN CUT HERE
/*
// SRM 518 Div2 Medium (500)

問題

文字列 s の部分文字列のうち、辞書順最大のものを求める。

#line 59 "LargestSubsequence.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

class LargestSubsequence {
	public:
	string getLargest(string s) {
		string answer;

		char buffer[64] = {0};
		strncpy(buffer, s.c_str(), 63);
		const char *src = buffer;

		const char *seq = "zyxwvutsrqponmlkjihgfedcba";

		int seq_index = 0;
		while (*src && seq_index < 26) {
			const char *p = strchr(src, seq[seq_index]);
			if (p == NULL) {
				++seq_index;
				continue;
			}
			answer += *p;
			src = p + 1;
			seq_index = 0;
		}

		return answer;
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(const char *seq, const char *expected)
{
	LargestSubsequence ___test;
	string result = ___test.getLargest(seq);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	// example 0
	Test("test", "tt");

	// example 1
	Test("a", "a");

	// example 2
	Test("example", "xple");

	// example 3
	Test("aquickbrownfoxjumpsoverthelazydog", "zyog");

	return 0;
}
// END CUT HERE
