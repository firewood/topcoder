
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef vector<III> IIIV;
typedef vector<IIIV> IIIVV;

int solve(IIIVV &v) {
	if (v[0].size() <= 0) {
		return 1;
	}
	int line = v[0].rbegin()->second.first;
	int pos = v[0].rbegin()->second.second;
	while (true) {
		int index = lower_bound(v[line].begin(), v[line].end(), III(pos, II(0,0))) - v[line].begin();
		if (--index < 0) {
			break;
		}
		pos = v[line][index].second.second;
		line = v[line][index].second.first;
	}
	return line + 1;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int L = 0, N = 0, M = 0;
	{
		stringstream ss(s);
		ss >> L >> N >> M;
	}
	IIIVV v(M);
	for (int i = 0; i < M; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int a = 0, b = 0, c = 0;
		ss >> a >> b >> c;
		v[a-1].push_back(III(b,II(a,c)));
		v[a].push_back(III(c,II(a-1,b)));
	}
	for (int i = 0; i < M; ++i) {
		sort(v[i].begin(), v[i].end());
	}
	cout << solve(v) << endl;
	return 0;
}

