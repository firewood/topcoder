#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

void merge(int *s, int left, int middle, int right) {
	int *temp = new int[right + 1];
	for (int i = left; i <= right; ++i) {
		temp[i] = s[i];
	}
	int l = left, r = middle + 1, w = left;
	while (l <= middle) {
		if (r <= right && temp[l] > temp[r]) {
			s[w++] = temp[r++];
		} else {
			s[w++] = temp[l++];
		}
	}
}

void merge_sort(int *s, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		merge_sort(s, left, middle);
		merge_sort(s, middle + 1, right);
		merge(s, left, middle, right);
	}
}

int main(int argc, char *argv[])
{
	int a[10000];

	for (int t = 0; t < 10000; ++t) {
		int cnt[128] = {};
		int N = rand() % 100 + 1;
		for (int i = 0; i < N; ++i) {
			a[i] = rand() % 100;
			++cnt[a[i]];
		}
		merge_sort(a, 0, N - 1);
		--cnt[a[0]];
		for (int i = 1; i < N; ++i) {
			assert(a[i] >= a[i - 1]);
			--cnt[a[i]];
		}
		for (int i = 0; i <= 100; ++i) {
			assert(cnt[i] == 0);
		}
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	merge_sort(a, 0, N - 1);
	for (int i = 0; i < N; ++i) {
		cout << " " << a[i];
	}
	cout << endl;
	return 0;
}
