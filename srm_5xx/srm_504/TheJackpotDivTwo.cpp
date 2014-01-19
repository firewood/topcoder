// BEGIN CUT HERE
/*
// SRM 504.5 Div2 Easy (250)

問題

整数の配列と、jackpot jが与えられる。
一番低い値のところにjを1ずつ分配した結果の配列を求める。


*/
#line 59 "TheJackpotDivTwo.cpp"
// END CUT HERE
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector <int> VI;

class TheJackpotDivTwo {
	public:
	vector <int> find(vector <int> money, int jackpot) {
		sort(money.begin(), money.end());

		int i;
		int sum = jackpot;
		for (i = 0; i < (int)money.size(); ++i) {
			sum += money[i];
		}
		int average;
		for (i = money.size() - 1; i >= 0; --i) {
			average = sum / (i + 1);
			if (average >= money[i]) {
				break;
			}
			sum -= money[i];
		}
		int m = i;
		for (i = 0; i <= m; ++i) {
			int diff = average - money[i];
			money[i] += diff;
			jackpot -= diff;
		}
		for (i = m; jackpot > 0; --i) {
			money[i] += 1;
			jackpot -= 1;
		}

		return money;
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

static void Test(const char *seq, int jackpot, const char *expected)
{
	vector <int> v = getVector<int>(seq);
	TheJackpotDivTwo ___test;
//	int result = 0;
	vector <int> result = ___test.find(v, jackpot);
//	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
	string s;
	char buffer[256];
	size_t i;
	for (i = 0; i < result.size(); ++i) {
		if (!s.empty()) {
			s += ',';
		}
		sprintf(buffer, "%d", result[i]);
		s += buffer;
	}
	printf("expected %s, result: %s, %s\n", expected, strcmp(expected, s.c_str()) == 0 ? "OK" : "FAILED", s.c_str());
}

int main() {
	// example 0
	Test("1,2,3,4", 2, "2,3,3,4");

	// example 1
	Test("4,7", 1, "5,7");

	// example 2
	Test("1", 100, "101");

	// example 3
	Test("21,85,6,54,70,100,91,60,71", 15, "21,21,54,60,70,71,85,91,100");


	Test("1,2", 100000, "50001,50002");
	return 0;
}
// END CUT HERE
