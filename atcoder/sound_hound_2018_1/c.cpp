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

class BipartiteMatching {
	int _size;
	vector<int> _left;
	vector<int> _right;
	vector<vector<int>> _edges;
	vector<int> _match;
	vector<int> _visited;
public:
	BipartiteMatching(int size) : _size(size) {
		_left.resize(size);
		_right.resize(size);
		_edges = vector<vector<int>>(size);
	}

	void set_left(int n) { _left[n] = 1; }

	void set_right(int n) { _right[n] = 1; }

	void add_edge(int left, int right) {
		_edges[left].emplace_back(right);
		_edges[right].emplace_back(left);
	}

	int match() {
		int matched = 0;
		_match = vector<int>(_size, -1);
		for (int i = 0; i < _size; ++i) {
			if (_left[i] && _match[i] < 0) {
				_visited = vector<int>(_size);
				matched += dfs(i);
			}
		}
		return matched;
	}

	bool dfs(int n) {
		_visited[n] = 1;
		for (auto x : _edges[n]) {
			auto& w = _match[x];
			if (w < 0 || (!_visited[w] && dfs(w))) {
				_match[n] = x;
				w = n;
				return true;
			}
		}
		return false;
	}

	vector<int> getMaximumIndependentSet() {
		match();
		vector<vector<int>> edges(_size);
		vector<int> visited(_size);
		vector<int> q;
		for (int i = 0; i < _size; ++i) {
			if (_left[i]) {
				for (auto x : _edges[i]) {
					if (_match[i] == x) {
						edges[x].emplace_back(i);
					} else {
						edges[i].emplace_back(x);
					}
				}
				if (_match[i] < 0) {
					q.emplace_back(i);
				}
			}
		}
		while (!q.empty()) {
			auto n = q.back();
			q.pop_back();
			visited[n] = 1;
			for (auto x : edges[n]) {
				if (!visited[x]) {
					q.emplace_back(x);
				}
			}
		}
		vector<int> s;
		for (int i = 0; i < _size; ++i) {
			if ((_left[i] && visited[i]) || (_right[i] && !visited[i])) {
				s.emplace_back(i);
			}
		}
		return s;
	}
};

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

int solve(int H, int W, vector<string>& field) {
	int total = 0;
	auto yx = [&](int y, int x) { return y * W + x; };
	BipartiteMatching bm(H * W);
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			if (field[y][x] == '.') {
				++total;
				if ((y + x) % 2 == 0) {
					bm.set_left(yx(y, x));
					for (int dir = 0; dir < 4; ++dir) {
						int ny = y + dy[dir], nx = x + dx[dir];
						if (ny >= 0 && ny < H && nx >= 0 && nx < W && field[ny][nx] == '.') {
							bm.add_edge(yx(y, x), yx(ny, nx));
						}
					}
				}
			}
		}
	}
	return total - bm.match();
}

int main() {
	int H, W, ans;
	cin >> H >> W;
	vector<string> field(H);
	for (int i = 0; i < H; i++) {
		cin >> field[i];
	}
	cout << solve(H, W, field) << endl;
	return 0;
}
