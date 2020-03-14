// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstdio>

using namespace std;

int n;

void dfs(int b, int i, string s) {
	if (i >= n) {
		printf("%s\n", s.c_str());
		return;
	}
	for (int j = 0; j < 10; ++j) {
		if (j == 0 || (b & (1 << (j - 1))) != 0) {
			dfs(b | (1 << j), i + 1, s + string(1, 'a' + j));
		}
	}
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		n = -1;
		cin >> n;
		if (n < 0) return 0;
		dfs(1, 1, "a");
	}
	return 0;
}
