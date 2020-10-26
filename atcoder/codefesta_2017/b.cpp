#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

void solve(std::string S) {
	int cnt[3] = {};
	for (char c : S) {
		cnt[c - 'a'] += 1;
	}
	sort(cnt, cnt + 3);
	bool ans = cnt[2] - cnt[0] <= 1;
	cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    std::string S;
	std::cin >> S;
	solve(S);
	return 0;
}
