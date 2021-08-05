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

enum state {
    UNDECIDED,
    LOSE,
    WIN,
};

vector<string> solve(int64_t N, std::vector<std::string> s) {
    map<string, int> sts, cnt;
    map<string, vector<string>> edges;
    set<string> tokens;
    for (int i = 0; i < N; i++) {
        string pre = s[i].substr(0, 3), post = s[i].substr(s[i].length() - 3);
        edges[post].emplace_back(pre);
        cnt[pre] += 1;
        tokens.insert(pre);
        tokens.insert(post);
    }
    deque<string> q;
    for (auto t : tokens) {
        if (cnt[t] == 0) {
            sts[t] = LOSE;
            q.emplace_back(t);
        }
    }
    while (!q.empty()) {
        string to = q.front();
        q.pop_front();
        for (string from : edges[to]) {
            if (sts[from] != UNDECIDED) {
                continue;
            }
            cnt[from] -= 1;
            if (sts[to] == LOSE) {
                sts[from] = WIN;
                q.push_back(from);
            } else if (cnt[from] == 0) {
                sts[from] = LOSE;
                q.push_back(from);
            }
        }
    }
    vector<string> ans(N);
    const string results[] = {"Draw", "Takahashi", "Aoki" };
    for (int i = 0; i < N; i++) {
        string post = s[i].substr(s[i].length() - 3);
        ans[i] = results[sts[post]];
    }
	return ans;
}

int main() {
#if DEBUG || _DEBUG
//	freopen("in.txt", "r", stdin);
	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N;
	std::cin >> N;
	std::vector<std::string> s(N);
	for (int i = 0; i < N; i++) {
		std::cin >> s[i];
	}
    for (auto s : solve(N, s)) {
        cout << s << endl;
    }
	return 0;
}
