// Google Code Jam 2014 R1A
// Problem A. Charging Chaos

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
typedef set<LL> LLSet;

static inline int popcount_ll(LL b) {
#ifdef __GNUC__
	return __builtin_popcountll(b);
#elif _MSC_VER >= 1400 && defined(_M_AMD64)
	return (int)__popcnt64(b);
#else
	b = (b & 0x5555555555555555LL) + (b >> 1 & 0x5555555555555555LL);
	b = (b & 0x3333333333333333LL) + (b >> 2 & 0x3333333333333333LL);
	b = (b & 0x0f0f0f0f0f0f0f0fLL) + (b >> 4 & 0x0f0f0f0f0f0f0f0fLL);
	b += b >> 8;
	b += b >> 16;
	return (int)((b + (b >> 32)) & 0x7F);
#endif
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		int N = 0, L = 0;

		getline(cin, s);
		{
			stringstream ss(s);
			ss >> N >> L;
		}

		LLSet src, dst;

		getline(cin, s);
		{
			stringstream ss(s);
			for (int i = 0; i < N; ++i) {
				string x;
				ss >> x;
				LL l = 0;
				for (int j = 0; j < L; ++j) {
					l <<= 1;
					l |= x[j] != '0';
				}
				src.insert(l);
			}
		}

		getline(cin, s);
		{
			stringstream ss(s);
			for (int i = 0; i < N; ++i) {
				string x;
				ss >> x;
				LL l = 0;
				for (int j = 0; j < L; ++j) {
					l <<= 1;
					l |= x[j] != '0';
				}
				dst.insert(l);
			}
		}

		int ans = -1;
		for (LL a : src) {
			for (LL b : dst) {
				LL x = a ^ b;
				if ([](const LLSet &src, const LLSet &dst, LL x) {
					for (LL c : src) {
						if (dst.find(c ^ x) == dst.end()) {
							return false;
						}
					}
					return true;
				}(src, dst, x)) {
					int count = popcount_ll(x);
					if (ans < 0 || count < ans) {
						ans = count;
					}
				}
			}
		}

		printf("Case #%d: ", t);
		if (ans < 0) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}

	return 0;
}

