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

vector<int> solve(int N, std::string S) {
	deque<int> q;
	q.emplace_back(N);
	for (int i = N - 1; i >= 0; --i) {
		if (S[i] == 'R') {
			q.push_front(i);
		} else {
			q.push_back(i);
		}
	}
	return vector<int>(q.begin(), q.end());
}

int main() {
	int N;
	std::string S;
	std::cin >> N >> S;
	vector<int> ans = solve(N, S);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
