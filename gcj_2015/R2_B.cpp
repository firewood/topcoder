// Google Code Jam 2015 R2
// Problem B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<double, double> DD;
typedef vector<DD> DDVec;

double solve(LL N, double V, double X, DDVec &v) {
	if (N == 1) {
		double R = v[0].first, C = v[0].second;
		if (X != C) {
			return -1;
		}
		return V / R;
	}
	if (N == 2) {
		double R1 = v[0].first, C1 = v[0].second;
		double R2 = v[1].first, C2 = v[1].second;
		if (C1 > C2) {
			swap(R1, R2);
			swap(C1, C2);
		}
		if (X < C1 || X > C2) {
			return -1;
		}
		if (C1 == C2) {
			return V / (R1 + R2);
		}
		if (C1 == X) {
			return V / R1;
		}
		if (C2 == X) {
			return V / R2;
		}
		double a = (C2 - X) / (C2 - C1);
		double b = (X - C1) / (C2 - C1);
		double c = (V * a) / R1;
		double d = (V * b) / R2;
		return max(c, d);
	}
	return -1;
}

int main(int argc, char *argv[]) {
	cout.precision(9);
	string s;
	getline(cin, s);
	LL T = atoi(s.c_str());
	for (LL t = 1; t <= T; ++t) {
		LL N;
		double V, X;
		{
			getline(cin, s);
			stringstream ss(s);
			ss >> N >> V >> X;
		}
		DDVec v;
		for (LL i = 0; i < N; ++i) {
			getline(cin, s);
			stringstream ss(s);
			double R, C;
			ss >> R >> C;
			v.push_back(DD(R, C));
		}
		double ans = solve(N, V, X, v);
		cout << "Case #" << t << ": ";
		if (ans < 0) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			printf("%.8f\n", ans);
//			cout << ans << endl;
		}
	}
	return 0;
}
