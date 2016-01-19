//
// Facebook Hacker Cup 2016 Round 1
// D. Boomerang Tournament
//

/*
Constraints

1 <= T <= 250
N = 2K where K is an integer and 0 <= K <= 4

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

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

typedef vector<int> IntVec;
typedef set<int> IntSet;
typedef map<int, IntVec> IntVecMap;
typedef map<int, IntSet> IntSetMap;

int d[16][16];

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> d[i][j];
			}
		}
		IntSetMap bw[5], wb[5], lb[5];
		for (int i = 0; i < N; ++i) {
			bw[0][1 << i].insert(i);
		}
		int bits = 2;
		for (int n = 1; bits <= N; bits *= 2, ++n) {
			IntSetMap::const_iterator a;
			for (a = bw[n - 1].begin(); a != bw[n - 1].end(); ++a) {
				IntSetMap::const_iterator b;
				for (b = a, ++b; b != bw[n - 1].end(); ++b) {
					int c = a->first | b->first;
					if (popcount(c) == bits) {
						for (int aa : a->second) {
							for (int bb : b->second) {
								if (d[aa][bb]) {
									bw[n][c].insert(aa);
									wb[n][aa].insert(c);
									lb[n][bb].insert(c);
								} else {
									bw[n][c].insert(bb);
									wb[n][bb].insert(c);
									lb[n][aa].insert(c);
								}
							}
						}
					}
				}
			}
		}

		cout << "Case #" << t << ":" << endl;
		switch (N) {
		case 1:
			cout << "1 1" << endl;
			break;
		case 2:
			if (d[0][1]) {
				cout << "1 1" << endl;
				cout << "2 2" << endl;
			} else {
				cout << "2 2" << endl;
				cout << "1 1" << endl;
			}
			break;
		case 4:
			for (int i = 0; i < N; ++i) {
				int res[2] = { 1, 1 };
				if (wb[2][i].size() == 0) {
					++res[0];
					if (wb[1][i].size() == 0) {
						++res[0];
					}
				}
				if (lb[1][i].size() > 0) {
					res[1] = 3;
				}
				cout << res[0] << " " << res[1] << endl;
			}
			break;
		case 8:
			for (int i = 0; i < N; ++i) {
				int res[2] = { 1, 1 };
				if (wb[3][i].size() == 0) {
					++res[0];
					if (wb[2][i].size() == 0) {
						++res[0];
						if (wb[1][i].size() == 0) {
							res[0] += 2;
						}
					}
				}
				if (lb[1][i].size() > 0) {
					res[1] = 5;
				}
				cout << res[0] << " " << res[1] << endl;
			}
			break;
		case 16:
			for (int i = 0; i < N; ++i) {
				int res[2] = { 1, 1 };
				if (wb[4][i].size() == 0) {
					++res[0];
					if (wb[3][i].size() == 0) {
						++res[0];
						if (wb[2][i].size() == 0) {
							res[0] += 2;
							if (wb[1][i].size() == 0) {
								res[0] += 4;
							}
						}
					}
				}
				if (lb[1][i].size() > 0) {
					res[1] = 9;
				}
				cout << res[0] << " " << res[1] << endl;
			}
			break;
		}
	}
	return 0;
}
