// Google Code Jam 2014 R1C
// Problem B. Reordering Train Cars

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		getline(cin, s);
		int N = atoi(s.c_str());
		string car[128];
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < N; ++i) {
			string c;
			ss >> car[i];
		}

		int seq[10];
		for (int j = 0; j < N; ++j) {
			seq[j] = j;
		}
		int ans = 0;
		do {
			int cnt[256] = {};
			char prev = 0;
			bool f = true;
			for (int i = 0; f && i < N; ++i) {
				string &x = car[seq[i]];
				for (int j = 0; j < (int)x.length(); ++j) {
					char c = x[j];
					if (prev > 0 && prev != c) {
						cnt[prev] = -1;
					}
					if (cnt[c] < 0) {
						f = false;
						break;
					}
					cnt[c] += 1;
					prev = c;
				}
			}
			ans += f;
		} while (next_permutation(seq, seq + N));

		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}

