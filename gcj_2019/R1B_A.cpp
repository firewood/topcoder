// Google Code Jam 2019 Round 1B
// Problem A. 

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, II> IIII;

II solve(vector<IIII> p, int q) {
	II ans(q, q);
	{
		vector<int> cnt(q + 1);
		for (auto x : p) {
			II st = x.first;
			II dir = x.second;
			if (dir.first < 0) {
				cnt[0] += 1;
				cnt[st.first] -= 1;
			}
			if (dir.first > 0) {
				cnt[st.first + 1] += 1;
			}
		}

		int sum = 0, mx = -1;
		for (int i = 0; i <= q; ++i) {
			sum += cnt[i];
			if (sum > mx) {
				mx = sum;
				ans.first = i;
			}
		}
	}
	{
		vector<int> cnt(q + 1);
		for (auto x : p) {
			II st = x.first;
			II dir = x.second;
			if (dir.second < 0) {
				cnt[0] += 1;
				cnt[st.second] -= 1;
			}
			if (dir.second > 0) {
				cnt[st.second + 1] += 1;
			}
		}

		int sum = 0, mx = -1;
		for (int i = 0; i <= q; ++i) {
			sum += cnt[i];
			if (sum > mx) {
				mx = sum;
				ans.second = i;
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int p, q;
		cin >> p >> q;
		vector<IIII> v;
		for (int i = 0; i < p; ++i) {
			int x, y;
			string d;
			cin >> x >> y >> d;
			if (d == "N") {
				v.push_back(IIII(II(x, y), II(0, 1)));
			}
			if (d == "S") {
				v.push_back(IIII(II(x, y), II(0, -1)));
			}
			if (d == "E") {
				v.push_back(IIII(II(x, y), II(1, 0)));
			}
			if (d == "W") {
				v.push_back(IIII(II(x, y), II(-1, 0)));
			}
		}
		II ans = solve(v, q);
		cout << "Case #" << t << ": " << ans.first << " " << ans.second << endl;
	}
	return 0;
}
