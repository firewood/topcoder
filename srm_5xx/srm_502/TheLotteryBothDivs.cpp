// BEGIN CUT HERE
/*
// SRM 502 Div2 Medium (500)

問題
  000000000 から 999999999 までの 1000000000 種類のくじがある
  当たりの下n桁を保持する配列 goodSuffixes から、当たる確率を求める

制約条件
  誤差1e-9未満
  goodSuffixes(1-9桁の数字文字列)[1-50]

#line 70 "TheLotteryBothDivs.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StringVector;
typedef set<string> StringSet;

class TheLotteryBothDivs {
public:
	double find(vector <string> goodSuffixes) {
		double result = 0;
		StringSet S;
		int i;
		for (i = 0; i < (int)goodSuffixes.size(); ++i) {
			// 接頭辞にして格納する
			reverse(goodSuffixes[i].begin(), goodSuffixes[i].end());
			S.insert(goodSuffixes[i]);
		}
		string prev;
		StringSet::const_iterator it;
		for (it = S.begin(); it != S.end(); ++it) {
			const string &s = *it;
			if (!prev.empty() && strncmp(prev.c_str(), s.c_str(), prev.length()) == 0) {
				// 接頭辞が一致したら、当選確率にはすでに含まれているので無視する
				// prevは最も短いものを保持したままとする
				continue;
			}
			// 当選確率 = 0.1^当選末尾桁数
			result += pow(0.1, (double)s.length());
			prev = s;
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

static void Test(const char *seq, double expected)
{
	vector <string> v = getVector<string>(seq);
	TheLotteryBothDivs ___test;
	double result = ___test.find(v);
	printf("result: %s, expexted %.9f, returned %.9f\n", fabs(result - expected) < 0.000000001 ? "OK" : "FAILED", expected, result);
}


int main() {
	// example 0
	Test("4", 0.1);

	// example 1
	Test("4 7", 0.2);

	// example 2
	Test("47 47", 0.01);

	// example 3
	Test("47 58 4747 502", 0.021);

	// example 4
	Test("8542861 1954 6 523 000000000 5426 8", 0.201100101);

	return 0;
}
// END CUT HERE
