#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int64_t N, M;
	cin >> N >> M;
	vector<int> score(N * 2);
	vector<string> hand(N * 2);
	map<int, map<int, int>> m;
	m['G']['C'] = 1;
	m['C']['P'] = 1;
	m['P']['G'] = 1;
	for (int i = 0; i < N * 2; ++i) {
		cin >> hand[i];
	}
	auto get_sorted_list = [&]() {
		vector<int> seq(N * 2);
		iota(seq.begin(), seq.end(), 0);
		sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
			return make_pair(-score[lhs], lhs) < make_pair(-score[rhs], rhs);
		});
		return seq;
	};
	for (int t = 0; t < M; t++) {
		vector<int> seq = get_sorted_list();
		for (int i = 0; i < N * 2; i += 2) {
			int a = seq[i], b = seq[i + 1];
			score[a] += m[hand[a][t]][hand[b][t]];
			score[b] += m[hand[b][t]][hand[a][t]];
		}
	}
	for (auto order : get_sorted_list()) {
		cout << (order + 1) << endl;
	}
	return 0;
}
