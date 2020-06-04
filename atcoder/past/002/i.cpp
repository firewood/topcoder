// I.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char* argv[]) {
	int f;
	cin >> f;
	int n = 1 << f;
	vector<int> g(n), seq(n), last(n, f);
	for (int i = 0; i < n; ++i) {
		cin >> g[i];
		seq[i] = i;
	}
	for (int i = 0; i < f; ++i) {
		n /= 2;
		vector<int> next(n);
		for (int j = 0; j < n; ++j) {
			int p = seq[j * 2], q = seq[j * 2 + 1];
			if (g[p] < g[q]) {
				last[p] = i + 1;
				next[j] = q;
			} else {
				last[q] = i + 1;
				next[j] = p;
			}
		}
		seq = next;
	}
	n = 1 << f;
	for (int i = 0; i < n; ++i) {
		cout << last[i] << endl;
	}
	return 0;
}
