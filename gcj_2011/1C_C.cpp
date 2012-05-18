/*

Google Code Jam 2011 Round 1C

Problem C. Perfect Harmony


問題
ある二つの数があり、片方がもう片方で割り切れるとき、ハーモニーと呼ぶことにする。
数値の配列Aが与えられる。
L以上H以下でAの全てとハーモニーが成り立つ数を求める。

*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
typedef set<LL> LLSet;
typedef vector<int> IntVec;

LL solve(int N, LL L, LL H, IntVec &v) {
	LLSet m;
	int i;
	for (i = 0; i < N; ++i) {
		m.insert(v[i]);
	}
	LL x;
	for (x = L; x <= H; ++x) {
		LLSet::const_iterator it;
		for (it = m.begin(); it != m.end(); ++it) {
			if ((*it % x) != 0 && (x % *it) != 0) {
				break;
			}
		}
		if (it == m.end()) {
			return x;
		}
	}
	return -1;
}

int main()
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int i, j, N;
	LL L, H;
	for (i = 0; i < T; ++i) {
		{
			getline(cin, s);
			stringstream ss(s);
			ss >> N >> L >> H;
		}
		IntVec v(N);
		{
			getline(cin, s);
			stringstream ss(s);
			for (j = 0; j < N; ++j) {
				ss >> v[j];
			}
		}
		LL result = solve(N, L, H, v);
		if (result >= 0) {
			cout << "Case #" << (i+1) << ": " << result << endl;
		} else {
			cout << "Case #" << (i+1) << ": NO" << endl;
		}
	}
	return 0;
}

