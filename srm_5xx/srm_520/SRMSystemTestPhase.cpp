// BEGIN CUT HERE
/*
// SRM 520 Div2 Hard (1000)

問題

SRMのテストフェーズになった。
解いたかどうかの結果が description[i] で与えられる。
description は順位毎になっている。
各 description[i] の要素は、解いた Y または解いていない N のいずれかである。
解いた場合の結果は、passed か failed か challenged のいずれかである。
順位の優先度は passed が多い順である。
passed が同じ場合は challenged が少ない順である。
スコアボードが何通りあるか答える。

#line 101 "SRMSystemTestPhase.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SRMSystemTestPhase {

public:
	int countWays(vector <string> description) {
		const int M = 1000000007;
		enum { FAILED, CHALLENGED, PASSED };
		int N = description.size();
		int dp[50][13] = {0};
		int i, j;
		for (i = N - 1; i >= 0; --i) {
			const string &d = description[i];
			int st[3];
			for (st[0] = 0; st[0] < 3; ++st[0]) {
				// 解いていない場合はFAILED扱い
				if (st[0] > 0 && d[0] != 'Y') continue;
				for (st[1] = 0; st[1] < 3; ++st[1]) {
					if (st[1] > 0 && d[1] != 'Y') continue;
					for (st[2] = 0; st[2] < 3; ++st[2]) {
						if (st[2] > 0 && d[2] != 'Y') continue;

						int score = 3;
						for (j = 0; j < 3; ++j) {
							// challengedは-1
							score += (st[j] == CHALLENGED ? -1 : 0);
							// 解いたら+3
							score += (st[j] == PASSED ? 3 : 0);
						}
						if (i == (N - 1)) {
							// 最下位
							dp[i][score] += 1;
						} else {
							// ひとつ下の順位の同じか少ないスコア
							for (j = 0; j <= score; ++j) {
								dp[i][score] += dp[i + 1][j];
								dp[i][score] %= M;
							}
						}
					}
				}
			}
		}

		int result = 0;
		for (j = 0; j <= 12; ++j) {
			result += dp[0][j];
			result %= M;
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

static void Test(const char *seq, int expected)
{
	vector <string> v = getVector<string>(seq);
	SRMSystemTestPhase ___test;
	int result = ___test.countWays(v);
	printf("result: %s, returned %d, expected %d\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {
	// example 0
	Test("YYY", 27);

	// example 1
	Test("YNN,NYN", 6);

	// example 2
	Test("YNN,NNN,NNY", 4);

	// example 3
	Test("NNN,NNN", 1);

	// example 4
	Test("YYY,YNY,NYY,YYN,YYY,YNN", 15176);

	return 0;
}
// END CUT HERE
