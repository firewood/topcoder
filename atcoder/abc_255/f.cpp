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
	int64_t _size;
	vector<int> a;
	vector<int> b;
	vector<int> bi;
	vector<vector<int>> v;

	Tree(int64_t size) : _size(size), v(size, vector<int>(2, -1)) { }

	bool dfs(int al, int ar, int bl, int br) {
		int root = a[al];
		int bpos = bi[root];
		int child_al = al + 1 + bpos - bl;
		if (bpos < bl || bpos >= br || child_al > _size) {
			return false;
		}
		if (bl < bpos) {
			v[root][0] = a[al + 1];
			if (!dfs(al + 1, child_al, bl, bpos)) {
				return false;
			}
		}
		if (bpos + 1 < br) {
			v[root][1] = a[child_al];
			if (!dfs(child_al, ar, bpos + 1, br)) {
				return false;
			}
		}
		return true;
	}
};

vector<vector<int>> solve(int N, std::vector<int> P, std::vector<int> I) {
	Tree tree(N);
	tree.a = P;
	tree.b = I;
	tree.bi = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		tree.bi[I[i]] = i;
	}
	if (P[0] == 0 && tree.dfs(0, N, 0, N)) {
		return tree.v;
	}
	return {};
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
		--P[i];
	}
	std::vector<int> I(N);
	for (int i = 0; i < N; i++) {
		std::cin >> I[i];
		--I[i];
	}
	vector<vector<int>> ans = solve(N, P, I);
	if (!ans.empty()) {
		for (int i = 0; i < N; ++i) {
			cout << (ans[i][0] + 1) << " " << (ans[i][1] + 1) << endl;
		}
	} else {
		cout << "-1" << endl;
	}
	return 0;
}
