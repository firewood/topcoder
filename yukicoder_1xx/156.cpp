#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	int N, M;
	getline(cin, s);
	{
		stringstream ss(s);
		ss >> N >> M;
	}
	vector<int> v(N);
	getline(cin, s);
	{
		stringstream ss(s);
		for (int i = 0; i < N; ++i) {
			ss >> v[i];
		}
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int a = min(v[i], M);
		v[i] -= a, M -= a;
		ans += v[i] <= 0;
	}
	cout << ans << endl;
	return 0;
}
