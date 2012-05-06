/*

Google Code Jam 2011 Round 1B

Problem B. Revenge of the Hot Dogs


問題
ホットドッグ屋が水平方向のみに伸びる道路上にいる。
それぞれのホットドッグ屋は、少なくとも距離Dだけ離れる必要がある。
ホットドッグ屋の移動速度は毎時1である。
地点の水平座標と、その地点のホットドッグ屋の個数が与えられる。
全てのホットドッグ屋の移動が完了する時間を求める。

*/

#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> IntVec;
typedef vector<double> DblVec;

static bool check(double t, int C, int D, IntVec &P, IntVec &V) {
	double pos = -1099511627776;
	int i;
	for (i = 0; i < C; ++i) {
		double width = (double)D * V[i];
		double movable = t - (width - D) / 2;
		if (movable < 0) {
			return false;
		}
		double LeftMin = (double)P[i] - width / 2 - movable;
		double LeftMax = (double)P[i] - width / 2 + movable;
		if (pos > LeftMax) {
			return false;
		}
		pos = max(pos, LeftMin);
		pos += width;
	}
	return true;
}

static double solve(int C, int D, IntVec &P, IntVec &V) {
	if (check(0, C, D, P, V)) {
		return 0;
	}

	double low = 0;
	double high = 1099511627776;
	while ((high - low) > 0.1) {
		double mid = (low + high) / 2;
		if (check(mid, C, D, P, V)) {
			high = mid;
		} else {
			low = mid;
		}
	}
	return high;
}

int main()
{
	cout.precision(16);
	int T, C, D;
	cin >> T;
	int t, i;
	for (t = 0; t < T; ++t) {
		cin >> C >> D;
		IntVec P(C), V(C);
		for (i = 0; i < C; ++i) {
			cin >> P[i] >> V[i];
		}
		cout << "Case #" << (t+1) << ": ";
		double result = solve(C, D, P, V);
		cout << result << endl;
	}

	return 0;
}

