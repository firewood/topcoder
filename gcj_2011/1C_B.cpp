/*

Google Code Jam 2011 Round 1C

Problem B. Space Emergency


問題
星0から星Nまで、速度0.5の宇宙船で移動する。
利用準備に時間tがかかるブースターがL個ある。
ブースターを使うと、使用してから次の星までの速度が1.0になる。
星と星との距離を示すのに、C個の配列が与えられる。
それぞれの星の距離はC個の配列の繰り返しである。
星Nへの最短到達時間を求める。

*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef map<int, int> IntMap;

// L speedboosters
// t time to boost
// N stars
// C repeat
LL solve(int L, LL t, int N, int C, IntVec &v) {
	LL result = 0;

	IntMap cnt;
	int i;
	for (i = 0; i < C; ++i) {
		cnt[v[i]] += (N / C) + ((N % C) >= (i+1));
	}

	for (i = 0; result < t && i < N; ++i) {
		int d = v[i % C];
		result += d;
		cnt[d] -= 1;
		if (result > t) {
			d = (int)(result - t);
			cnt[d] += 1;
			result = t;
		}
	}

	IntMap::reverse_iterator it;
	for (it = cnt.rbegin(); it != cnt.rend(); ++it) {
		int can = min(L, it->second);
		result += it->first * can / 2;
		it->second -= can;
		L -= can;
	}
	for (it = cnt.rbegin(); it != cnt.rend(); ++it) {
		result += it->first * it->second;
	}

	return result;
}

int main()
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int i, j, L, N, C;
	LL t;
	for (i = 0; i < T; ++i) {
		getline(cin, s);
		stringstream ss(s);
		ss >> L >> t >> N >> C;
		IntVec v(C);
		for (j = 0; j < C; ++j) {
			ss >> v[j];
			v[j] *= 2;
		}
		LL result = solve(L, t, N, C, v);
		cout << "Case #" << (i+1) << ": " << result << endl;
	}
	return 0;
}

