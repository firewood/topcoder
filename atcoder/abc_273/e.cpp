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
	int parent_index;
	int value;
};

vector<int> solve(int Q, const vector<string> &cmd, const vector<int> &val) {
	vector<int> ans(Q);
	vector<Node> nodes;
	nodes.emplace_back(Node({ 0, -1 }));
	int index = 0;
	map<int, int> node_map;
	for (int i = 0; i < Q; ++i) {
		if (cmd[i] == "ADD") {
			nodes.emplace_back(Node({ index, val[i] }));
			index = int(nodes.size()) - 1;
		}
		if (cmd[i] == "DELETE") {
			index = nodes[index].parent_index;
		}
		if (cmd[i] == "SAVE") {
			node_map[val[i]] = index;
		}
		if (cmd[i] == "LOAD") {
			index = node_map[val[i]];
		}
		ans[i] = nodes[index].value;
	}
	return ans;
}

int main() {
	int Q;
	cin >> Q;
	vector<string> cmd(Q);
	vector<int> val(Q, -1);
	for (int i = 0; i < Q; i++) {
		cin >> cmd[i];
		if (cmd[i] != "DELETE") {
			cin >> val[i];
		}
	}
	vector<int> ans = solve(Q, cmd, val);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
