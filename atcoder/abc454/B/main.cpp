#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
const string YES = "Yes";
const string NO = "No";

std::vector<bool> solve(int64_t N, int64_t M, std::vector<int64_t> F) {
	set<int64_t> s(F.begin(), F.end());
	std::vector<bool> ans = { s.size() == N, s.size() == M };
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> F(N);
	for (int64_t i = 0; i < N; ++i) {
		std::cin >> F[i];
	}
	auto answers = solve(N, M, std::move(F));
	for (const auto ans : answers) {
		cout << (ans ? YES : NO) << endl;
	}
}
