#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int cnt[14] = {};
	for (int i = 0; i < 5; ++i) {
		int a;
		cin >> a;
		cnt[a] += 1;
	}
	int pairs = 0, three = 0;
	for (int i = 1; i <= 13; ++i) {
		pairs += cnt[i] == 2;
		three += cnt[i] == 3;
	}
	string ans = "NO HAND";
	if (three) {
		ans = pairs ? "FULL HOUSE" : "THREE CARD";
	} else if (pairs) {
		ans = pairs >= 2 ? "TWO PAIR" : "ONE PAIR";
	}
	cout << ans << endl;
	return 0;
}
