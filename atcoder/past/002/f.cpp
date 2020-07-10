// F.

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
	int n, a, b;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		v[a - 1].push_back(b);
	}
	priority_queue<int> q;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int a : v[i]) {
			q.emplace(a);
		}
		sum += q.top();
		q.pop();
		cout << sum << endl;
	}
	return 0;
}
