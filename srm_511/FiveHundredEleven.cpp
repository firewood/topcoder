// BEGIN CUT HERE
/*
// SRM 511 Div2 Hard (1000)

問題

Fox Ciel と Toastman がターン制のゲームをする。
状態とN枚のカードを使用する。
状態は最初ゼロで、カードを出すとカードに書かれた数値がORされる。
出すカードがないと負ける。
カードを出した結果、状態が511になると、出したほうが負ける。
最適化戦略において勝者を求める。


#line 65 "FiveHundredEleven.cpp"
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

typedef unsigned long long ULL;

typedef vector<int> IV;

class FiveHundredEleven {
#if 1
	int n;
	IV cards;
	int dp[512][64];

	int isWinner(int memory, int played) {
		if (memory == 511) {
			return true;
		}
		if (played >= n) {
			return false;
		}
		int &result = dp[memory][played];
		if (result != -1) {
			return result;
		}
		int i;
		for (i = 0; i < n; ++i) {
			int newmem = memory | cards[i];
			if (newmem != memory) {
				return result = !isWinner(newmem, played + 1);
			}
		}
		return result = !isWinner(memory, played + 1);
	}

public:
	string theWinner(vector <int> _cards) {
		n = _cards.size();
		cards = _cards;
		memset(dp, -1, sizeof(dp));
		return isWinner(0, 0) ? "Fox Ciel" : "Toastman";
	}

#else
	bool isWinner(const IV &c, int v, ULL f) {
		if (f == 0) {
			return false;
		}

		ULL b = 1;
		int i;
		for (i = 0; i < (int)c.size(); ++i) {
			if (f & b) {
				int nv = v | c[i];
				if (nv != 511 && !isWinner(c, nv, f ^ b)) {
					return true;
				}
			}
			b <<= 1;
		}

		return false;
	}

public:
	string theWinner(vector <int> cards) {
		ULL f = (1LL << cards.size()) - 1;
		return isWinner(cards, 0, f) ? "Fox Ciel" : "Toastman";
	}
#endif
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
	vector <int> v = getVector<int>(seq);
	FiveHundredEleven ___test;
	string result = ___test.theWinner(v);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	// example 0
	Test("3,5,7,9,510", "Fox Ciel");

	// example 1
	Test("0,0,0,0", "Toastman");

	// example 2
	Test("511", "Toastman");

	// example 3
	Test("5,58,192,256", "Fox Ciel");

	Test("77,389,61,361,289,255,195,13,485,476,239,317,234,310,372,426,478,29,356,30,60,439,349,261,440,117,459,253,289,495,350,167,115,492,338,394,429,243,177,368,11,282,393,227,405,372,364,56,276,160", "Fox Ciel");

	return 0;
}
// END CUT HERE
