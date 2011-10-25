// BEGIN CUT HERE 
/*
// SRM 504 Div2 Hard (1000)

問題

白と黒どちらかのグリッドからなる行がある。
特定のルールにより、ひとつ上の行の内容に従い、下の行を塗り替える。
塗られた結果から、元々の内容を求める。

*/
// END CUT HERE
#line 98 "Algrid.cpp"
#include <string>
#include <vector>

using namespace std;
typedef vector<string>VS;

class Algrid {
	public:
	vector <string> makeProgram(vector <string> output) {
		VS e;
		int H = output.size();
		if (H <= 1) {
			return e;
		}
		int W = output[0].length();

		char buffer[16][20];
		int x, y;
		for (y = 0; y < H; ++y) {
			strcpy(buffer[y], output[y].c_str());
		}

		VS r;
		r.push_back(output[0]);
		for (y = 0; y <= (H - 2); ++y) {
			char dst[20] = { 0 };
			for (x = 0; x < W; ++x) {
				dst[x] = x;
			}

			for (x = 0; x <= (W - 2); ++x) {
				if (buffer[y][x] == 'W' && buffer[y][x + 1] == 'W') {
					// nothing to do
				} else if (buffer[y][x] == 'B' && buffer[y][x + 1] == 'W') {
					// BW: fill with black
					dst[x] = 'B';
					dst[x + 1] = 'B';
				} else if (buffer[y][x] == 'W' && buffer[y][x + 1] == 'B') {
					// WB: fill with white
					dst[x] = 'W';
					dst[x + 1] = 'W';
				} else if (buffer[y][x] == 'B' && buffer[y][x + 1] == 'B') {
					// BB: swap
					char c = dst[x + 1];
					dst[x + 1] = dst[x];
					dst[x] = c;
				} else {
					return e;
				}
			}

			char src[20] = { 0 };
			memset(src, 'B', W);
			for (x = 0; x < W; ++x) {
				if (dst[x] == 'W' || dst[x] == 'B') {
					if (dst[x] != buffer[y + 1][x]) {
						return e;
					}
				} else {
					size_t index = dst[x];
					src[index] = buffer[y + 1][x];
				}
			}

			r.push_back(src);
		}

		return r;
	}
};

// BEGIN CUT HERE



static void Test(const char *seq)
{
	char buffer[1000];
	strcpy(buffer, seq);
	vector <string> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(p);
		p = strtok(NULL, " ,");
	}
	Algrid ___test;
	v = ___test.makeProgram(v);
	printf("result: %d\n", v.size());
	size_t i;
	for (i = 0; i < v.size(); ++i) {
		printf("%s\n", v[i].c_str());
	}
}

int main() {
	// example 0
	Test("WWWWWWW WWWWWWB BBBBBWW");	// Returns: {"WWWWWWW", "WWWWWWB", "BBBBBBB" }

	// example 1
	Test("BBBBB WBWBW");	// Returns: {"BBBBB", "WWBWB" }

	// example 2
	Test("BBBB BBBB BBWB WWBB BWBB");	// Returns: { }

	// example 3
	Test("WWBBBBW BWBBWBB BWBBWBW BWWBWBB");	// Returns: {"WWBBBBW", "BBBBBWB", "BBBBBBB", "BBBWBBB" }

	return 0;
}
// END CUT HERE
