
// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int N, M;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> N >> M;
	vector<string> v(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, v[i]);
	}
	int ans = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int cnt[256] = {};
			cnt[v[i][j]] += 1;
			cnt[v[i][j + 1]] += 1;
			cnt[v[i + 1][j]] += 1;
			cnt[v[i + 1][j + 1]] += 1;
			ans += cnt['f'] && cnt['a'] && cnt['c'] && cnt['e'];
		}
	}
	cout << ans << endl;
	return 0;
}
