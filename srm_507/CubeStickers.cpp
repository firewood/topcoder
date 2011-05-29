// BEGIN CUT HERE
/*
// SRM 507 Div2 Middle (500)
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.
Fox Ciel has a cube and some colored stickers.  You are given a vector <string> sticker, where the i-th element is the color of the i-th sticker.  Ciel wants to choose six of these stickers and apply one on each of the cube's faces.  Each pair of adjacent faces must have different colors.  Two faces are considered adjacent if they share an edge.

If this is possible, return "YES", otherwise, return "NO" (all quotes for clarity).


DEFINITION
Class:CubeStickers
Method:isPossible
Parameters:vector <string>
Returns:string
Method signature:string isPossible(vector <string> sticker)


CONSTRAINTS
-sticker will contain between 6 and 50 elements, inclusive.
-Each element of sticker will contain between 1 and 10 lowercase letters ('a'-'z'), inclusive.


EXAMPLES

0)
{"cyan","magenta","yellow","purple","black","white","purple"}

Returns: "YES"

One of the possible ways is shown in the following picture:



1)
{"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"}

Returns: "NO"



2)
{"red","yellow","blue","red","yellow","blue","red","yellow","blue"}

Returns: "YES"



3)
{"purple","orange","orange","purple","black","orange","purple"}

Returns: "NO"



4)
{"white","gray","green","blue","yellow","red","target","admin"}

Returns: "YES"



#line 64 "CubeStickers.cpp"
*/
// END CUT HERE
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef map<string, int> SIM;

class CubeStickers {
	public:
	string isPossible(vector <string> sticker) {
		SIM m;
		size_t i;
		for (i = 0; i < sticker.size(); ++i) {
			const string &key = sticker[i];
			if (m.find(key) != m.end()) {
				m[key] += 1;
			} else {
				m[key] = 1;
			}
		}

		size_t ms = m.size();
		if (ms < 3) {
			return "NO";
		}
		if (ms >= 6) {
			return "YES";
		}

		size_t dc = 0;
		SIM::const_iterator it;
		for (it = m.begin(); it != m.end(); ++it) {
			if (it->second >= 2) {
				++dc;
			}
		}

		return (ms + dc) >= 6 ? "YES" : "NO";
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
	CubeStickers ___test;
	string result = ___test.isPossible(v);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
//	Test("cyan magenta yellow purple black white purple", "YES");
	Test("A A B B C C", "YES");
	Test("A A B B C C", "YES");
	Test("R Y B R Y B", "YES");
	Test("P O O P B O P", "NO");
	return 0;
}
// END CUT HERE
