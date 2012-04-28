/*

Google Code Jam 2012 Round 1A

Problem B. Kingdom Rush


問題

Kingdom Rushというゲームをクリアしたい。
ゲームはN面からなる。各面はレベル1とレベル2からなる。
全ての面のレベル2をクリアすればゲームクリアである。
レベル1をクリアすると星がひとつ、レベル2をクリアすると星がふたつもらえる。
ただしレベル1をクリア済でレベル2をクリアしたときは星がひとつだけもらえる。
各面のそれぞれのレベルをクリアに必要な星の数が与えられる。
星の条件を満たしている場合、1プレイでそのレベルをクリアである。
星の条件を満たしていない場合、そのレベルはクリアできない。
ゲームをクリアするのに必要な最小のゲームのプレイ数を求める。

*/

#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<II> IIVec;

static int solve(int N, IntVec a, IntVec b) {
	int result = 0;
	IIVec A, B;
	int i, j, k, stars = 0;
	for (i = 0; i < N; ++i) {
		A.push_back(II(a[i], i));
		B.push_back(II(b[i], i));
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	IntVec f(N);
	for (i = 0; i < N; ++i) {
		while (stars < B[i].first) {
			int MaxB = -1;
			for (j = 0; j < N; ++j) {
				if (stars < A[j].first) {
					break;
				}
				if (!f[A[j].second]) {
					if (b[A[j].second] > MaxB) {
						k = A[j].second;
						MaxB = b[k];
					}
				}
			}
			if (MaxB < 0) {
				return -1;
			}
			f[k] = 1;
			++result;
			stars += 1;
		}

		++result;
		stars += 2 - f[B[i].second];
		f[B[i].second] = 2;
	}

	return result;
}


int main(int argc, char *argv[])
{
	cout.precision(16);
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t;
	for (t = 0; t < T; ++t) {
		IntVec a, b;
		getline(cin, s);
		int N = atoi(s.c_str());
		int i;
		for (i = 0; i < N; ++i) {
			getline(cin, s);
			stringstream ss(s);
			int p, q;
			ss >> p >> q;
			a.push_back(p);
			b.push_back(q);
		}
		int result = solve(N, a, b);
		cout << "Case #" << (t+1) << ": ";
		if (result < 0) {
			cout << "Too Bad" << endl;
		} else {
			cout << result << endl;
		}
	}

	return 0;
}

