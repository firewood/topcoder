/*

Google Code Jam 2012 Round 2

問題

危険なジャングルの湿地帯にいる。
自分の小屋から、愛するハニーのいる小屋へ到達したい。
小屋と小屋の間には何本かの蔓（つる）がぶらさがっていて、蔓をターザンのようにスイングさせることにより、次の蔓をつかんで移動することができる。
愛するハニーのもとへ到達できるかどうかを求める。

*/

#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

bool solve(int N, int D, IntVec &pos, IntVec &len) {
	IntVec memo(N);
	memo[0] = pos[0];
	int i, j;
	for (i = 0; i < N; ++i) {
		int upper = pos[i] + memo[i];
		for (j = i+1; j < N && pos[j] <= upper; ++j) {
			memo[j] = max(memo[j], min(len[j], abs(pos[i] - pos[j])));
		}
	}
	for (i = 0; i < N; ++i) {
		if ((pos[i] + memo[i]) >= D) {
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t;
	for (t = 0; t < T; ++t) {
		int N, D;
		getline(cin, s);
		{
			stringstream ss(s);
			ss >> N;
		}
		IntVec pos(N), len(N);
		int i;
		for (i = 0; i < N; ++i) {
			getline(cin, s);
			stringstream ss(s);
			ss >> pos[i] >> len[i];
		}
		{
			getline(cin, s);
			stringstream ss(s);
			ss >> D;
		}
		bool result = solve(N, D, pos, len);
		cout << "Case #" << (t+1) << ": " << (result ? "YES" : "NO") << endl;
	}

	return 0;
}

