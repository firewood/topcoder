#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int N, T, L[32], F[32] = {};
	map<string, vector<int> > S;
	map<string, int> timestamp;
	cin >> N;
	for (int i = 0; i != N; ++i) {
		cin >> L[i];
	}
	cin >> T;
	for (int i = 0; i != T; ++i) {
		string name, p;
		cin >> name >> p;
		int pn = p[0] - 'A';
		++F[pn];
		int score = (int)(50 * L[pn] * (1 + 1 / (0.8 + 0.2 * F[pn])) + 1e-12);
		S[name].resize(N);
		S[name][pn] = score;
		timestamp[name] = i;
	}
	vector<tuple<int, int, string> > v;
	for (auto kv : S) {
		v.push_back(make_tuple(-accumulate(kv.second.begin(), kv.second.end(), 0), timestamp[kv.first], kv.first));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i != v.size(); ++i) {
		string &name = get<2>(v[i]);
		cout << (i + 1) << " " << name;
		for (auto a : S[name]) {
			cout << " " << a;
		}
		cout << " " << -get<0>(v[i]);
		cout << endl;
	}
	return 0;
}
