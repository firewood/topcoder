// D.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	vector<int> v[100000];
	int visited[100000] = {};
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> q[2];
	visited[0] = 1;
	q[0].push_back(0);
	visited[n - 1] = 1;
	q[1].push_back(n - 1);
	int score[2] = {};
	while (!q[0].empty() || !q[1].empty()) {
		vector<int> next[2];
		for (int i = 0; i < 2; ++i) {
			for (int x : q[i]) {
				for (int y : v[x]) {
					if (!visited[y]) {
						++score[i];
						visited[y] = 1;
						next[i].push_back(y);
					}
				}
			}
			q[i] = next[i];
		}
	}
	cout << (score[0] > score[1] ? "Fennec" : "Snuke") << endl;
	return 0;
}
