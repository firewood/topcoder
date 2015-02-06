#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	int cnt[256] = {};
	for (char c : s) {
		cnt[c] += 1;
	}
	int ans = cnt['z'];
	cnt['z'] = 0;
	while (cnt['y'] && cnt['u'] && cnt['k'] && cnt['i']) {
		int i;
		for (i = 'a'; i < 'i'; ++i) {
			if (cnt[i]) {
				break;
			}
		}
		if (i >= 'i') {
			break;
		}
		++ans;
		cnt['y'] -= 1, cnt['u'] -= 1, cnt['k'] -= 1, cnt['i'] -= 1, cnt[i] -= 1;
	}
	while (cnt['y'] && cnt['u'] && cnt['k'] && cnt['i'] >= 2) {
		++ans;
		cnt['y'] -= 1, cnt['u'] -= 1, cnt['k'] -= 1, cnt['i'] -= 2;
	}
	while (cnt['y'] && cnt['u'] && cnt['k'] && cnt['j']) {
		++ans;
		cnt['y'] -= 1, cnt['u'] -= 1, cnt['k'] -= 1, cnt['j'] -= 1;
	}
	while (cnt['y'] && cnt['u'] && cnt['k'] >= 2) {
		++ans;
		cnt['y'] -= 1, cnt['u'] -= 1, cnt['k'] -= 2;
	}
	while (cnt['y'] && cnt['u']) {
		int i;
		for (i = 'l'; i < 'u'; ++i) {
			if (cnt[i]) {
				break;
			}
		}
		if (i >= 'u') {
			break;
		}
		++ans;
		cnt['y'] -= 1, cnt['u'] -= 1, cnt[i] -= 1;
	}
	while (cnt['y'] && cnt['u'] >= 2) {
		++ans;
		cnt['y'] -= 1, cnt['u'] -= 2;
	}
	while (cnt['y']) {
		int i;
		for (i = 'v'; i < 'y'; ++i) {
			if (cnt[i]) {
				break;
			}
		}
		if (i >= 'y') {
			break;
		}
		++ans;
		cnt['y'] -= 1, cnt[i] -= 1;
	}
	while (cnt['y'] >= 2) {
		cnt['y'] -= 2;
		++ans;
	}
	cout << ans << endl;
	return 0;
}
