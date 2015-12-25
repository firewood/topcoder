#include <iostream>
#include <sstream>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

int main(int argc, char *argv[]) {
	int C[256][256] = {};
	for (int i = 0; i < 256; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	int N, b = 0;
	cin >> N;

	int tot = 0, len;
	for (len = 3; ; ++len) {
		int a = 0;
		for (int j = 3; j <= len; j += 3) {
			a += C[len - 1][j - 1];
		}
		if (tot + a >= N) {
			break;
		}
		tot += a;
	}

	for (int i = tot; i < N; ++i) {
		++b;
		while ((popcount(b) % 3) != 2) {
			++b;
		}
	}

	string ans = "5";
	for (int i = 1; i < len; ++i) {
		ans = (b & 1 ? "5" : "3") + ans;
		b >>= 1;
	}
	cout << ans << endl;

	return 0;
}
