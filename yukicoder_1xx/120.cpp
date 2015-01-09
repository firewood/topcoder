#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		int N = atoi(s.c_str());
		getline(cin, s);
		stringstream ss(s);
		int n[100] = {};
		for (int i = 0; i < N; ++i) {
			ss >> n[i];
		}
		sort(n, n + N);
		int c = 1;
		int cnt[100] = { 1 };
		for (int i = 1; i < N; ++i) {
			if (n[i - 1] != n[i]) {
				++c;
			}
			cnt[c - 1] += 1;
		}
		int ans = 0;
		if (c >= 3) {
			while (true) {
				sort(cnt, cnt + c);
				if (cnt[c - 3] <= 0) {
					break;
				}
				++ans;
				cnt[c - 3] -= 1, cnt[c - 2] -= 1, cnt[c - 1] -= 1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
