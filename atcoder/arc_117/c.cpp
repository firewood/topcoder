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

int solve1(int N, string s) {
	int a = 1, b = 1, c = 0, sum = 0;
	for (int i = 0; i < N; ++i) {
		if (i) {
			a *= (N - i);
			while (a % 3 == 0) {
				a /= 3;
				++c;
			}
			a %= 3;
			b *= i;
			while (b % 3 == 0) {
				b /= 3;
				--c;
			}
			b %= 3;
		}
		int ch;
		switch (s[i]) {
		case 'B':
			ch = 0;
			break;
		case 'W':
			ch = 1;
			break;
		case 'R':
			ch = 2;
			break;
		}
		if (c <= 0) {
			sum = (sum + a * b * ch) % 3;
		}
	}
	return N % 2 ? sum : (3 - sum) % 3;
}

int solve2(int N, string s) {
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		switch (s[i]) {
		case 'B':
			a[i] = 0;
			break;
		case 'W':
			a[i] = 1;
			break;
		case 'R':
			a[i] = 2;
			break;
		}
	}
	while (a.size() > 1) {
		vector<int> next(a.size() - 1);
		for (int i = 1; i < a.size(); ++i) {
			next[i - 1] = (6 - a[i - 1] - a[i]) % 3;
		}
		a = next;
	}
	return a[0];
}

int main() {
	int N;
	string s;
	std::cin >> N >> s;
	cout << "BWR"[solve1(N, s)] << endl;
	return 0;
}
