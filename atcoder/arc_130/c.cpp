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

typedef pair<int, int> II;
typedef pair<string, string> SS;

vector<int> get_count(string s) {
	vector<int> cnt(10);
	for (auto c : s) {
		cnt[c - '0'] += 1;
	}
	return cnt;
}

string to_str(vector<int> v) {
	string s;
	for (int i = v.size() - 1; i >= 0; --i) {
		s += char('0' + v[i]);
	}
	return s;
}

int eval(vector<int> a, vector<int> b) {
	if (a.size() < b.size()) {
		swap(a, b);
	}
	int tot = 0, carry = 0;
	for (int i = 0; i < a.size(); ++i) {
		int x = a[i] + carry;
		if (i < b.size()) {
			x += b[i];
		}
		carry = x >= 10;
		x %= 10;
		tot += x;
	}
	return tot + carry;
}

void fill_any(vector<int>& a, vector<int>& x, int len, int offset) {
	int pos = 0;
	for (int i = 9; i >= 1; --i) {
		while (a[i] > 0 && pos < len) {
			a[i] -= 1;
			x[pos + offset] = i;
			++pos;
		}
	}
}

bool build(vector<int> ca, vector<int> cb, vector<int>& x, vector<int>& y, int start) {
	auto check = [&]() {
		for (int j = 10 - start; j < 20 - start; ++j) {
			int d = j % 10;
			if (ca[start] > 0 && cb[d] > 0) {
				x[0] = start;
				y[0] = d;
				ca[start] -= 1;
				cb[d] -= 1;
				return true;

			}
		}
		return false;
	};
	if (!check()) {
		return false;
	}
	int pos = 1;
	for (int i = 1; i <= 9; ++i) {
		for (int j = 9 - i; j <= 9; ++j) {
			while (ca[i] > 0 && cb[j] > 0) {
				x[pos] = i;
				y[pos] = j;
				ca[i] -= 1;
				cb[j] -= 1;
				++pos;
			}
		}
	}
	fill_any(ca, x, x.size() - pos, pos);
	fill_any(cb, y, y.size() - pos, pos);
	return true;
}

SS solve(std::string a, std::string b) {
	int mn = 1 << 30;
	SS ans;
	vector<int> ca = get_count(a), cb = get_count(b);
	for (int i = 1; i <= 9; ++i) {
		vector<int> x(a.length()), y(b.length());
		if (build(ca, cb, x, y, i)) {
			int e = eval(x, y);
			if (e < mn) {
				mn = e;
				ans.first = to_str(x);
				ans.second = to_str(y);
			}
		}
	}
	return ans;
}

int main() {
	std::string a, b;
	std::cin >> a >> b;
	SS ans = solve(a, b);
	cout << ans.first << endl;
	cout << ans.second << endl;
	return 0;
}
