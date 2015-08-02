#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	double st[100], ed[100];
	int ans[100];
	double rst = -1, red = 1e+30;
	for (int i = 0; i < N; ++i) {
		string s, e;
		cin >> s >> e;
		int stt[4], edt[4];
		sscanf(s.c_str(), "%d:%d:%d.%d", stt, stt+1, stt+2, stt+3);
		sscanf(e.c_str(), "%d:%d:%d.%d", edt, edt+1, edt+2, edt+3);
		st[i] = stt[0] * 3600000 + stt[1] * 60000 + stt[2] * 1000 + stt[3];
		ed[i] = edt[0] * 3600000 + edt[1] * 60000 + edt[2] * 1000 + edt[3];
		ans[i] = (int)(ed[i] - st[i]);
		if (ed[i] <= st[i]) {
			rst = max(rst, st[i]);
			red = min(red, ed[i] + 1000);
			ans[i] += 1000;
		}
//		cout << "st:" << (int)st[i] << ",ed:" << (int)ed[i] << endl;
	}
//	cout << "rst:" << (int)rst << ",red:" << (int)red << endl;

	for (int i = 0; i < N; ++i) {
		if (rst < 0) {
			ans[i] = -1;
			continue;
		}
		if (ed[i] <= st[i]) {
			continue;
		}
		if (st[i] > rst - 1000 && st[i] < red) {
			ans[i] = -1;
			continue;
		}
		if (ed[i] > rst - 1000 && ed[i] < red) {
			ans[i] = -1;
			continue;
		}
		if (st[i] <= rst - 1000 && ed[i] >= red) {
			ans[i] += 1000;
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
