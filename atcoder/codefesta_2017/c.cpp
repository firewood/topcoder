// C.

#include <iostream>
#include <cstdio>

using namespace std;

int cnt[256];

bool dec(int r) {
	for (int i = 'a'; r >= 1 && i <= 'z'; ++i) {
		if (cnt[i] > 0 && (cnt[i] % 4) != 0 && (cnt[i] % 2) == 0) {
			cnt[i] -= 2;
			--r;
		}
	}
	for (int i = 'a'; r >= 2 && i <= 'z'; ++i) {
		while (r >= 2 && cnt[i] > 0 && (cnt[i] % 4) == 0) {
			cnt[i] -= 4;
			r -= 2;
		}
	}
	return r == 0;
}

bool check(int h, int w) {
	if ((h % 2) == 0 && (w % 2) == 0) {

	} else if ((h % 2) != 0 && (w % 2) != 0) {
		int oc = 0;
		for (int i = 'a'; i <= 'z'; ++i) {
			if (cnt[i] % 2) {
				--cnt[i];
				++oc;
			}
		}
		if (oc != 1) {
			return false;
		}
		if (!dec((w - 1) / 2 + (h - 1) / 2)) {
			return false;
		}
	} else {
		if ((w % 2) != 0) {
			swap(h, w);
		}
		if (!dec(w / 2)) {
			return false;
		}
	}
	for (int i = 'a'; i <= 'z'; ++i) {
		if (cnt[i] % 4) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < w; ++j) {
			cnt[s[j]] += 1;
		}
	}
	bool ans = check(h, w);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
