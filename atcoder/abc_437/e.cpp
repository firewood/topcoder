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

struct Node {
	set<int> nodes;
	map<int, int> mapping;
};
vector<Node> pool(500004);

void dfs(vector<int>& ans, const Node& node) {
	for (int x : node.nodes) {
		ans.emplace_back(x);
	}
	for (const auto& kv : node.mapping) {
		dfs(ans, pool[kv.second]);
	}
}

vector<int> solve(int64_t N, std::vector<int> x, std::vector<int> y) {
	vector<int> ans, index(N + 1);
	iota(index.begin(), index.end(), 0);
	for (int i = 0; i < N; ++i) {
		Node& parent = pool[index[x[i]]];
		auto it = parent.mapping.find(y[i]);
		if (it != parent.mapping.end()) {
			index[i + 1] = it->second;
		} else {
			parent.mapping[y[i]] = i + 1;
		}
		pool[index[i + 1]].nodes.insert(i + 1);
	}
	dfs(ans, pool[0]);
	return ans;
}

int main() {
	{
		int64_t N;
		std::cin >> N;
		std::vector<int> x(N), y(N);
		for (int i = 0; i < N; i++) {
			std::cin >> x[i] >> y[i];
		}
		vector<int> ans = solve(N, x, y);
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << (ans[i]);
		}
		cout << endl;
	}
	return 0;
}
