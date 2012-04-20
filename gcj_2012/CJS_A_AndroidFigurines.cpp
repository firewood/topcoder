/*

Code Jam Sprint
Problem A. Android Figurines

問題
M種類のアンドロイドのミニフィギュアが発売になった。
それぞれの種類を少なくともK1, K2, ... KM個入手する衝動に駆られた。
店にはそれぞれの種類の在庫がL個ずつある。
望みの数だけ入手するために最悪何個買う必要があるか求める。

*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

static int solve(int L, int M, IntVec &v) {
	// descending sort
	sort(v.rbegin(), v.rend());
	if (v[0] > L) {
		// impossible; insufficient stock
		return -1;
	}
	if (v[0] <= 0) {
		// needless to buy any figurines
		return 0;
	}
	// in worst case we have to purchase
	// all of (M-1) types of figurines in stock
	return v[0] + (M - 1) * L;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t, L, M, i, x;
	for (t = 0; t < T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		ss >> L >> M;
		IntVec v;
		for (i = 0; i < M; ++i) {
			ss >> x;
			v.push_back(x);
		}
		int res = solve(L, M, v);
		cout << "Case #" << (t+1) << ": " << res << endl;
	}

	return 0;
}

