// Google Code Jam 2014 Qualification Round
// Problem B. Cookie Clicker Alpha

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

typedef vector<LL> LLVec;

double solve(double C, double F, double X)
{
	long double r = 2.0;
	long double ans = X / r;
	for (int i = 0; i < 10000000; ++i) {
		long double t = ans - (X - C) / r;
		r += F;
		t += X / r;
		if (t > ans) {
			break;
		}
		ans = t;
	}
	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		double C = 0, F = 0, X = 0;
		ss >> C >> F >> X;
		printf("Case #%d: %.7f\n", t, solve(C, F, X));
	}

	return 0;
}

