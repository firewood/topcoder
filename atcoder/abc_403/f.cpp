#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

string solve(int64_t N) {
	string ans;

	vector<string> memo1(2002), memo2(2002);
	memo1[1] = "1";
	memo1[11] = "11";
	memo1[111] = "111";
	memo1[1111] = "1111";
	auto update = [](string& memo, const string& s) {
		if (memo.empty() || memo.length() > s.length()) {
			memo = s;
		}
	};
	auto get_min = [&](int x) {
		const string& s1 = memo1[x], & s2 = memo2[x];
		if (s2.empty()) return s1;
		return s1.length() <= s2.length() ? s1 : s2;
	};
	auto get_embraced = [&](int x) {
		const string& s1 = memo1[x], & s2 = memo2[x];
		if (s2.empty()) return s1;
		return s1.length() <= (s2.length() + 2) ? s1 : "(" + s2 + ")";
	};
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i + j > N) break;
			update(memo1[i + j], "(" + get_min(j) + "+" + get_min(i) + ")");
			update(memo2[i + j], get_min(j) + "+" + get_min(i));
			if (i * j > N) continue;
			update(memo1[i * j], get_embraced(j) + "*" + get_embraced(i));
		}
	}
	return get_min(N);
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
