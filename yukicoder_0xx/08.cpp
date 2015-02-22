#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

static bool solve(int N, int K) {
	return (N % (K + 1)) != 1;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int i = 0; i < T; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int N, K;
		ss >> N >> K;
		string ans = solve(N, K) ? "Win" : "Lose";
		cout << ans << endl;
	}
	return 0;
}
