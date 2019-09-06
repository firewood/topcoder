// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> dep(n, vector<int>(n));
	vector<vector<int>> ord(n, vector<int>(n - 1));
	vector<vector<int>> done(n, vector<int>(n));
	vector<int> index(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			int a;
			cin >> a;
			--a;
			ord[i][j] = a;
			if (j > 0) {
				dep[i][a] += 1;
				dep[a][i] += 1;
			}
		}
	}
	vector<II> q;
	for (int i = 0; i < n; ++i) {
		int a = ord[i][0];
		if (!dep[i][a]) {
			q.push_back(II(i, a));
		}
	}
	int rem = n * (n - 1);
	int ans = 0;
	while (q.size()) {
		++ans;
		vector<II> next;
		vector<int> u(n);
		for (const II& t : q) {
			int a = t.first;
			int b = t.second;
			if ((u[a] || u[b]) && !done[a][b]) {
				next.push_back(t);
				continue;
			}
			u[a] = 1;
			u[b] = 1;
			done[a][b] = 1;
			done[b][a] = 1;

			--rem;
			index[a] += 1;
			if (index[a] < n - 1) {
				int nb = ord[a][index[a]];
				dep[a][nb] -= 1;
				dep[nb][a] -= 1;
				if (dep[a][nb] <= 0) {
					next.push_back(II(a, nb));
				}
				if (dep[nb][a] <= 0) {
					next.push_back(II(nb, a));
				}
			}
		}
		q = next;
	}
	cout << (rem > 0 ? -1 : ans) << endl;
	return 0;
}
