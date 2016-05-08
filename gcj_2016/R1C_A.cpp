// Google Code Jam 2016 Round 1C
// Problem A. Senate Evacuation

#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, char> II;

string solve() {
	string ans;
	int N;
	cin >> N;
	priority_queue<II> Q;
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		int p;
		cin >> p;
		Q.push(II(p, 'A' + i));
		sum += p;
	}
	while (Q.size()) {
		II top = Q.top();
		Q.pop();
		top.first -= 1;
		--sum;
		string a(1, top.second);
		if (top.first > 0) {
			Q.push(II(top));
		}

		if (sum != 2) {
			top = Q.top();
			Q.pop();
			top.first -= 1;
			--sum;
			string b(1, top.second);
			a += b;
			if (top.first > 0) {
				Q.push(II(top));
			}
		}

		if (!ans.empty()) {
			ans += " ";
		}
		ans += a;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string ans = solve();
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
