#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int s[6];
	for (int i = 0; i < 6; ++i) {
		cin >> s[i];
	}
	sort(s, s + 6);
	int sum = accumulate(s + 1, s + 5, 0) * 100 / 4;
	printf("%d%c%02d\n", sum / 100, '.', sum % 100);
	return 0;
}
