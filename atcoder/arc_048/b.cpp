// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;
typedef map<int, int> IntMap;
typedef vector<int> IntVec;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	IntVec R, H, SR;
	IntMap HR[3];
	for (int i = 0; i != N; ++i) {
		int r, h;
		cin >> r >> h;
		--h;
		R.push_back(r);
		H.push_back(h);
		HR[h][r] += 1;
	}
	SR = R;
	sort(SR.begin(), SR.end());
	for (int i = 0; i != N; ++i) {
		int win = lower_bound(SR.begin(), SR.end(), R[i]) - SR.begin();
		win += HR[(H[i] + 1) % 3][R[i]];
		int pos = lower_bound(SR.begin(), SR.end(), R[i] + 1) - SR.begin();
		int lose = N - pos;
		lose += HR[(H[i] + 2) % 3][R[i]];
		int draw = HR[H[i]][R[i]] - 1;
		cout << win << " " << lose << " " << draw << endl;
	}
	return 0;
}
