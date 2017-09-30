// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int, int> II;
typedef pair<double, II> DII;

vector<DII> v;

void solve(long long n) {
	double x = 4.0 / n;
	double diff = 1e9;
	int p, q, r;
	for (int i = 1; i <= 3500; ++i) {
		double y = 1.0 / i;
		vector<DII>::const_iterator it = lower_bound(v.begin(), v.end(), DII(x - y - 1e-7, II(0, 0)));
		for (; it != v.end(); ++it) {
			if (it->first > (x-y+1e-7)) {
				break;
			}
			II k = it->second;
			double hnw = 1.0 * k.first * k.second * i;
			double d = fabs(hnw / k.first + hnw / k.second + hnw / i - (hnw * 4.0) / n);
			if (d < diff) {
				p = i, q = k.first, r = k.second;
				diff = d;
			}
		}
	}
	cout << p << " " << q << " " << r << endl;
}

int main(int argc, char *argv[])
{
	for (int i = 1; i <= 3500; ++i) {
		for (int j = i; j <= 3500; ++j) {
			v.push_back(DII((1.0 / i) + 1.0 / j, II(i, j)));
		}
	}
	sort(v.begin(), v.end());
	long long n;
	cin >> n;
	solve(n);
}

