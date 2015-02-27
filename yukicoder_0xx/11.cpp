#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int solve(int W, int H, int N, vector<int> &S, vector<int> &K) {
	set<int> mark(S.begin(), S.end());
	int ans = mark.size() * H - S.size();
	set<int> nums(K.begin(), K.end());
	ans += nums.size() * (W - mark.size());
	return ans;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int W = atoi(s.c_str());
	getline(cin, s);
	int H = atoi(s.c_str());
	getline(cin, s);
	int N = atoi(s.c_str());
	vector<int> S(N), K(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		ss >> S[i] >> K[i];
	}
	int ans = solve(W, H, N, S, K);
	cout << ans << endl;
	return 0;
}
