// BEGIN CUT HERE
/*
// SRM 507 Div2 Medium (500)

問題

六面体を、色が隣り合わないように塗れるかどうかを答える


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
	// example 0
	Test("cyan,magenta,yellow,purple,black,white,purple", "YES");

	// example 1
	Test("blue,blue,blue,blue,blue,blue,blue,blue,blue,blue", "NO");

	// example 2
	Test("red,yellow,blue,red,yellow,blue,red,yellow,blue", "YES");

	// example 3
	Test("purple,orange,orange,purple,black,orange,purple", "NO");

	// example 4
	Test("white,gray,green,blue,yellow,red,target,admin", "YES");

	return 0;
}
// END CUT HERE
