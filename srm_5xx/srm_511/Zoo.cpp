// BEGIN CUT HERE
/*
// SRM 511 Div2 Medium (500)

問題

N匹の動物がいて0からN-1までの番号が振られている。
動物は兎または猫のいずれかである。
それぞれの動物の背丈は全て異なる。
それぞれの動物に「自分と同じ種類で、自分より背が高いのは何匹か」と聞いた。
答えの配列には、背丈の回答のみが含まれており、種類は不明である。
動物の種類の組み合わせが何通りあるか求める。


#line 65 "Zoo.cpp"
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

typedef long long ll;

class Zoo {
	public:
	long long theCount(vector <int> answers) {
		sort(answers.begin(), answers.end());
		int length = (int)answers.size();
		int a = 0;
		int b = 0;
		int i;
		for (i = 0; i < length; ++i) {
			if (answers[i] == a) {
				++a;
			} else if (answers[i] == b) {
				++b;
			} else {
				return 0;
			}
		}
		int shifts = min(a, b) + (a != b);
		ll result = 1LL << shifts;
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

static void Test(const char *seq, long long expected)
{
	vector <int> v = getVector<int>(seq);
	Zoo ___test;
	long long result = ___test.theCount(v);
	printf("result: %s, %ld\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test("0,1,2,3,4", 2);

	// example 1
	Test("5,8", 0);

	// example 2
	Test("0,0,0,0,0,0", 0);

	// example 3
	Test("1,0,2,0,1", 8);

	// example 4
	Test("1,0,1", 0);

	Test("1,0,0,1", 4);

	return 0;
}
// END CUT HERE
