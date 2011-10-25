// BEGIN CUT HERE 
/*
// SRM 504 Div2 Medium 500

問題

白と黒のボールが入った筒がある。
ボールを1個ずつ取り出す。
取り出したボールが白なら、ボールの並びを反転させる。
取り出したボールが黒なら、筒の色を反転させる。

*/
// END CUT HERE
#line 73 "MathContest.cpp"
#include <string>
#include <vector>

using namespace std;

class MathContest {
	public:
	int countBlack(string ballSequence, int repetitions) {
		char *buffer = new char[100000 + 4];
		char *dst = buffer;
		int chunk_size = (int)ballSequence.length();
		int remain = chunk_size * repetitions;
		while (--repetitions >= 0) {
			memcpy(dst, ballSequence.c_str(), chunk_size);
			dst += chunk_size;
		}
		const char *head = buffer;
		const char *tail = buffer + remain - 1;
		char target = 'B';
		bool is_head = true;
		int black = 0;
		while (--remain >= 0) {
			char c;
			if (is_head) {
				c = *head++;
			} else {
				c = *tail--;
			}
			if (c == target) {
				++black;
				target ^= ('B' ^ 'W');
			} else {
				is_head = !is_head;
			}
		}
		delete [] buffer;
		return black;
	}
};

// BEGIN CUT HERE 
static void Test(const char *seq, int repeat, int expected)
{
	MathContest ___test;
	int result = ___test.countBlack(seq, repeat);
	printf("result: %s, seq:%s, ret:%d\n", result == expected ? "OK" : "FAILED", seq, result);
}

int main() {
	// example 0
	Test("BBWWB", 1, 2);

	// example 1
	Test("BBB", 10, 1);

	// example 2
	Test("BW", 10, 20);

	// example 3
	Test("WWWWWWWBWWWWWWWWWWWWWW", 1, 2);

	return 0;
}
// END CUT HERE
