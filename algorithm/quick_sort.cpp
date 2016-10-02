#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

void quick_sort(int *s, int N) {
	if (N <= 1) {
		return;
	}
	int left = 0, right = N - 1;
	int p = s[N / 2];
	while (true) {
		while (s[left] < p) {
			assert(left < N);
			++left;
		}
		while (p < s[right]) {
			assert(right >= 0);
			--right;
		}
		if (left >= right) {
			break;
		}
		swap(s[left], s[right]);
		++left, --right;
	}
	quick_sort(s, left);
	quick_sort(s + left, N - left);
}

int main(int argc, char *argv[])
{
	int a[10000];

	for (int t = 0; t < 10000; ++t) {
		int N = rand() % 10 + 1;
		for (int i = 0; i < N; ++i) {
			a[i] = rand() % 100;
		}
		quick_sort(a, N);
		for (int i = 1; i < N; ++i) {
			assert(a[i] >= a[i - 1]);
		}
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	quick_sort(a, N);
	for (int i = 0; i < N; ++i) {
		cout << " " << a[i];
	}
	cout << endl;
	return 0;
}
