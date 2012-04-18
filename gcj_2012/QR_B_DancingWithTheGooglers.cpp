
//
// Google Code Jam 2012 QR
// B. Dancing With the Googlers
//

#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> IntVec;
typedef map<int, int> IntMap;

static int solve(int S, int p, const IntVec &v) {
	int Good = (max(0, p-1)*2 + p);
	int Min = max(0, p-2);
	int Surprise = Min*2 + (Min+2);
	int res = 0;
	int i;
	for (i = 0; i < (int)v.size(); ++i) {
		if (v[i] >= Good) {
			++res;
		} else if (S > 0 && v[i] >= Surprise) {
			--S;
			++res;
		}
	}
	return res;
}

int main(int argc, char *argv[])
{
	int t, T;
	cin >> T;
	for (t = 0; t < T; ++t) {
		int N, S, p;
		cin >> N >> S >> p;
		IntVec v(N);
		int i;
		for (i = 0; i < N; ++i) {
			cin >> v[i];
		}
		int res = solve(S, p, v);
		cout << "Case #" << (t+1) << ": " << res << endl;
	}

	return 0;
}

