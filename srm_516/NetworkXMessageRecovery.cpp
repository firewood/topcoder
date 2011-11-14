// BEGIN CUT HERE
/*
// SRM 516 Div2 Hard (1000)

問題

破損した部分文字列から、元の文字列を求める。
それぞれの文字は1回しか出現しない。
複数の候補がある場合は辞書順。


#line 71 "NetworkXMessageRecovery.cpp"
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

typedef unsigned int UI;
typedef set<UI> IntSet;

class NetworkXMessageRecovery {
	public:
	string recover(vector <string> messages) {
		IntSet used;
		IntSet former[128];
		int i, j, k;
		for (i = 0; i < (int)messages.size(); ++i) {
			const string &s = messages[i];
			int length = s.length();
			for (j = 0; j < length; ++j) {
				used.insert(s[j]);
				for (k = 0; k < j; ++k) {
					former[s[j]].insert(s[k]);
				}
			}
		}

		string result;
		while (used.size() > 0) {
			IntSet::iterator u;
			for (u = used.begin(); u != used.end(); ++u) {
				bool f = true;
				IntSet::const_iterator it;
				for (it = former[*u].begin(); it != former[*u].end(); ++it) {
					if (used.find(*it) != used.end()) {
						f = false;
						break;
					}
				}
				if (!f) {
					continue;
				}
				result += (unsigned char)*u;
				used.erase(u);
				break;
			}
		}

		return result;
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
	vector <string> v = getVector<string>(seq);
	NetworkXMessageRecovery ___test;
	string result = ___test.recover(v);
	printf("result: %s, %s\n", result.compare(expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	// example 0
	Test("acd bce", "abcde");

	// example 1
	Test("ed dc cb ba", "edcba");

	// example 2
	Test("Fox Ciel FoxCiel", "FoxCiel");

	// example 3
	Test("a A", "Aa");

	return 0;
}
// END CUT HERE
