// B. 

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> children[100001];

int dfs(int n) {
	vector<int> depth;
	for (int c : children[n]) {
		depth.push_back(dfs(c));
	}
	int r = 0;
	sort(depth.begin(), depth.end());
	for (int d : depth) {
		r = 1 + max(r, d);
	}
	return r;
}

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	for (int i = 2; i <= N; ++i) {
		int a;
		cin >> a;
		children[a].push_back(i);
	}
	int ans = dfs(1);
	cout << ans << endl;
	return 0;
}
