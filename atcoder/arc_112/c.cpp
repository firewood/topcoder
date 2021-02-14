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

struct Tree {
	int _size;
	int _count;
	
	vector<vector<int>> _edges;

	Tree(int size) : _size(size), _count(0), _edges(size) { }

	void build_edges_from_parents(const vector<int>& parents) {
		for (int i = 0; i < parents.size(); ++i) {
			_edges[parents[i]].emplace_back(i + 1);
		}
	}

	int dfs(int node) {
		// コインを獲得して相手のターン
		int s = 1, dir = 1, sz = (int)_edges[node].size();
		++_count;
		vector<int> score(sz), size(sz), seq(sz);
		for (int i = 0; i < sz; ++i) {
			int prev_count = _count;
			score[i] = dfs(_edges[node][i]);
			size[i] = _count - prev_count;
		}
		iota(seq.begin(), seq.end(), 0);
		sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
			return score[lhs] < score[rhs];
		});
		for (int ord = 0; ord < sz; ++ord) {
			int i = seq[ord];
			if (size[i] % 2) {
				// ターンを交代しながら大きなものから取る
				s += dir * score[i];
				dir *= -1;
			} else if (score[i] <= 0) {
				// 相手のターンのまま、相手がコインを取る
				s += score[i];
			}
		}
		// 残りの自分のターンでは損をするムーブを処理する
		for (int i = 0; i < sz; ++i) {
			if (size[i] % 2 == 0 && score[i] > 0) {
				s += dir * score[i];
			}
		}
		return s;
	}
};

int solve(int n, std::vector<int> &p) {
	Tree tree(n);
	tree.build_edges_from_parents(p);
	return (n + tree.dfs(0)) / 2;
}

int main() {
    int n;
	std::cin >> n;
	std::vector<int> p(n - 1);
	for (int i = 0; i < n - 1; i++) {
		std::cin >> p[i];
		--p[i];
	}
	cout << solve(n, p) << endl;
	return 0;
}
