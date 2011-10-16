// BEGIN CUT HERE 
/*
// SRM 503 Div2 Medium (500)

問題
  Toastmanが何種類かのパンを焼いてトーストを作る。
  それぞれのパンはそれぞれ固有の値を持っていて、ちょうどX分焼くと素晴らしいトーストになる。
  X分未満だと生焼け、X分を超えると焼きすぎになる。
  N枚焼いたが、ToastmanはそれぞれのXを知らないため、いずれも生焼けか焼きすぎとなった。
  全種類について、1枚以上の生焼けと1枚以上の焼きすぎが存在する。
  条件を満たすトーストの最小の種類を答える。(条件を満たさないなら-1)

制約条件
  undertoasted (1-1000000)[1-50] 値は全て異なる
  overtoasted (1-1000000)[1-50] 値は全て異なる
  undertoasted と overtoasted は全て異なる

*/
#include <string>
// END CUT HERE
#line 87 "ToastXToast.cpp"
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> VI;

class ToastXToast {
	public:
	int bake(vector <int> undertoasted, vector <int> overtoasted) {
		sort(undertoasted.begin(), undertoasted.end());
		sort(overtoasted.begin(), overtoasted.end());
		if (undertoasted.size() < 1 || overtoasted.size() < 1) {
			return -1;
		}
		if (*undertoasted.rbegin() >= *overtoasted.rbegin() ) {
			return -1;
		}
		if (*undertoasted.begin() >= *overtoasted.begin() ) {
			return -1;
		}
		if (*undertoasted.rbegin() < *overtoasted.begin()) {
			return 1;
		}
		return 2;
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

static void Test(const char *u, const char *o, int expected)
{
	vector <int> under = getVector<int>(u);
	vector <int> over = getVector<int>(o);
	ToastXToast ___test;
	int result = ___test.bake(under, over);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test("2,4", "5,6,3", 2);

	// example 1
	Test("5", "4", -1);

	// example 2
	Test("1,2,3", "5,6,7", 1);

	// example 3
	Test("1,3,5", "2,4,6", 2);

	Test("5", "1,9", -1);

	return 0;
}
// END CUT HERE
