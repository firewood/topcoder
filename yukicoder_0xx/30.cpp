#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;
LL memo[256];
LLVec req_index[256];
LLVec req_count[256];

LL calc(int index) {
	LL &res = memo[index];
	if (res >= 0) {
		return res;
	}
	res = 0;
	for (LL i = 0; i < req_index[index].size(); ++i) {
		res += calc(req_index[index][i]) * req_count[index][i];
	}
	return res;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	LL N = atoi(s.c_str());
	getline(cin, s);
	LL M = atoi(s.c_str());
	LL gen[256] = {};
	for (LL i = 0; i < M; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int P, Q, R;
		ss >> P >> Q >> R;
		req_index[P - 1].push_back(R - 1);
		req_count[P - 1].push_back(Q);
		gen[R - 1] = 1;
	}
	memset(memo, -1, sizeof(memo));
	memo[N - 1] = 1;
	for (LL i = 0; i < N - 1; ++i) {
		LL c = gen[i] ? 0 : calc(i);
		cout << c << endl;
	}
	return 0;
}
