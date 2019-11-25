// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> e;
vector<int> col;
int max_color;

void dfs(int n, int used_color) {
	int current_color = 0;
	for (auto kv : e[n]) {
		if (!col[kv.second]) {
			if (++current_color == used_color) {
				++current_color;
			}
			col[kv.second] = current_color;
			dfs(kv.first, current_color);
			max_color = max(max_color, current_color);
		}
	}
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		max_color = 0;
		e.clear();
		e.resize(n);
		col.clear();
		col.resize(n);
		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			cin >> a >> b;
			--a, --b;
			e[a].push_back({ b, i });
			e[b].push_back({ a, i });
		}
		dfs(0, 0);
		cout << max_color << endl;
		for (int i = 0; i < n - 1; ++i) {
			cout << col[i] << endl;
		}
	}
	return 0;
}
