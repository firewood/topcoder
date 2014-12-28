#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> IntVec;

IntVec solve(int N, int D, int K)
{
	IntVec res(K);
	int m = (K*(K + 1)) / 2;
	if (m > D) {
		return IntVec();
	}
	int r = D - m;
	for (int i = K - 1; i >= 0; --i) {
		int n = i + 1;
		int a = min(n + r, N);
		r -= (a - n);
		--N;
		res[i] = a;
	}
	if (r > 0) {
		return IntVec();
	}
	return res;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N, D, K;
	stringstream ss(s);
	ss >> N >> D >> K;
	IntVec res = solve(N, D, K);
	if (res.size() <= 0) {
		cout << "-1" << endl;
	} else {
		for (int i = 0; i < (int)res.size(); ++i) {
			if (i > 0) {
				cout << " ";
			}
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}
