// BEGIN CUT HERE
/*
// SRM 512 Div2 Medium (512)

問題

N日間営業しているレストランがある。
そのレストランではM種類の料理がある。
1日に1種類しか食べることができない。
ある日に種類 j の料理を頼むと、同じ曜日には j を頼まなければならない。
料理を頼まない日があると、翌日以降は頼めない。
料理の値段は毎日異なる。
値段は文字の配列で与えられる。
'0'から'9'が0から9ドル
'A'から'Z'が10から35ドル
'a'から'z'が36から61ドル
予算 budget で、食べられる最大日数を求める。


#line 75 "MysteriousRestaurant.cpp"
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
typedef vector<int> VI;

class MysteriousRestaurant {
	public:
	int maxDays(vector <string> prices, int budget) {
		int result = 0;
		int Total[7][50] = {0};
		int days = prices.size();
		int dishes = prices[0].length();
		int day, dish;
		for (day = 0; day < days; ++day) {
			int week = day % 7;
			const string &s = prices[day];
			for (dish = 0; dish < dishes; ++dish) {
				const char *tbl = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
				const char *p = strchr(tbl, s[dish]);
				if (p) {
					Total[week][dish] += p - tbl;
				}
			}
			int Sum = 0;
			for (week = 0; week < 7; ++week) {
				int Min = 999999;
				for (dish = 0; dish < dishes; ++dish) {
					Min = min(Min, Total[week][dish]);
				}
				Sum += Min;
			}
			if (Sum > budget) {
				break;
			}
			++result;
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

static void Test(const char *seq, int budget, int expected)
{
	vector <string> v = getVector<string>(seq);
	MysteriousRestaurant ___test;
	int result = ___test.maxDays(v, budget);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test("26 14 72 39 32 85 06", 13, 5);

	// example 1
	Test("26 14 72 39 32 85 06 91", 20, 8);

	// example 2
	Test("SRM 512", 4, 0);

	// example 3
	Test("Dear Code rsHa veFu nInT heCh alle ngeP hase andb ecar eful", 256, 10);

	return 0;
}
// END CUT HERE
