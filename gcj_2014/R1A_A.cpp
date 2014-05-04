// Google Code Jam 2014 R1A
// Problem A. Charging Chaos

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;

static int popcount(LL bits) {
	bits = (bits & 0x5555555555555555LL) + (bits >> 1 & 0x5555555555555555LL);
	bits = (bits & 0x3333333333333333LL) + (bits >> 2 & 0x3333333333333333LL);
	bits = (bits & 0x0f0f0f0f0f0f0f0fLL) + (bits >> 4 & 0x0f0f0f0f0f0f0f0fLL);
	bits = (bits & 0x00ff00ff00ff00ffLL) + (bits >> 8 & 0x00ff00ff00ff00ffLL);
	bits = (bits & 0x0000ffff0000ffffLL) + (bits >> 16 & 0x0000ffff0000ffffLL);
	bits = (bits & 0x00000000ffffffffLL) + (bits >> 32 & 0x00000000ffffffffLL);
	return (int)bits;
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

		IntSet source[2];
		LLSet src;

		getline(cin, s);
		{
			stringstream ss(s);
			for (int i = 0; i < N; ++i) {
				string x;
				ss >> x;
				int k = 0;
				LL l = 0;
				int j;
				for (j = 0; j < L/2; ++j) {
					k <<= 1;
					k |= x[j] != '0';
					l <<= 1;
					l |= x[j] != '0';
				}
				source[0].insert(k);
				k = 0;
				for (; j < (int)x.length(); ++j) {
					k <<= 1;
					k |= x[j] != '0';
					l <<= 1;
					l |= x[j] != '0';
				}
				source[1].insert(k);
				src.insert(l);
			}
		}

		IntSet target[2];
		LLSet dst;

		getline(cin, s);
		{
			stringstream ss(s);
			for (int i = 0; i < N; ++i) {
				string x;
				ss >> x;
				int k = 0;
				LL l = 0;
				int j;
				for (j = 0; j < L/2; ++j) {
					k <<= 1;
					k |= x[j] != '0';
					l <<= 1;
					l |= x[j] != '0';
				}
				target[0].insert(k);
				k = 0;
				for (; j < (int)x.length(); ++j) {
					k <<= 1;
					k |= x[j] != '0';
					l <<= 1;
					l |= x[j] != '0';
				}
				target[1].insert(k);
				dst.insert(l);
			}
		}

		int ans = -1;

		IntSet ok[2];
		for (int k = 0; k < 2; ++k) {
			int m = k == 0 ? (1 << (L / 2)) : (1 << (L - L / 2));
			for (int i = 0; i < m; ++i) {
				bool found = true;
				IntSet::const_iterator a;
				for (a = source[k].begin(); found && a != source[k].end(); ++a) {
					found = target[k].find(*a ^ i) != target[k].end();
				}
				if (found) {
					ok[k].insert(i);
				}
			}
		}

		IntSet::const_iterator a, b;
		for (a = ok[0].begin(); a != ok[0].end(); ++a) {
			LL x = (LL)*a << (L - L / 2);
			for (b = ok[1].begin(); b != ok[1].end(); ++b) {
				LL y = x | (LL)*b;
				LLSet::const_iterator c;
				bool found = true;
				for (c = src.begin(); found && c != src.end(); ++c) {
					found = dst.find(*c ^ y) != dst.end();
				}
				if (found) {
					int bits = popcount(y);
					if (ans < 0 || bits < ans) {
						ans = bits;
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

