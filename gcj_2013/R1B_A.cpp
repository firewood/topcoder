// Google Code Jam 2013 R1B
// Problem A. Osmos

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

LL solve(LL A, int N, LLVec &v)
{
	if (A <= 1) {
		return N;
	}
	int ans = N;
	int c = 0;
	int i;
	for (i = 0; i < N; ++i) {
		ans = min(ans, c + (N - i));
		while (v[i] >= A) {
			++c;
			A += A - 1;
		}
		A += v[i];
	}
	return min(ans, c);
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 0; t < T; ++t) {
		int A = 0, N = 0;
		getline(cin, s);
		{
			stringstream ss(s);
			ss >> A >> N;
			if (A <= 0 || N <= 0) {
				break;
			}
		}
		LLVec v(N);
		getline(cin, s);
		{
			stringstream ss(s);
			for (int i = 0; i < N; ++i) {
				ss >> v[i];
			}
		}
		sort(v.begin(), v.end());
		cout << "Case #" << (t+1) << ": " << solve(A, N, v) << endl;
	}

	return 0;
}

