// BEGIN CUT HERE
/*
// SRM 507 Div2 Easy (250)

問題

全ての蟻が蜂蜜を置いた頂点に集まるまでの時間を求める。


#line 64 "CubeAnts.cpp"
*/
// END CUT HERE
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CubeAnts {
	public:
	int getMinimumSteps(vector <int> pos) {
		static const int C[] = {0,1,2,1,1,2,3,2};
		int r = 0;
		size_t s = pos.size();
		size_t i;
		for (i = 0; i < s; ++i) {
			r = max(r, C[pos[i]]);
		}
		return r;
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

static void Test(const char *seq, int expected)
{
	vector <int> v = getVector<int>(seq);
	CubeAnts ___test;
	int result = ___test.getMinimumSteps(v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test("0,1,1", 1);

	// example 1
	Test("5,4", 2);

	// example 2
	Test("0", 0);

	// example 3
	Test("6,1,6", 3);

	// example 4
	Test("7,7,3,3,7,7,3,3", 2);

	return 0;
}
// END CUT HERE
