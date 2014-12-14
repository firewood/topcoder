#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int memo[16][16][16][16];

int dfs(int *N)
{
	int a[4] = { N[0], N[1], N[2], N[3] };
	sort(a, a + 4);
	if (memo[a[0]][a[1]][a[2]][a[3]] >= 0) {
		return memo[a[0]][a[1]][a[2]][a[3]];
	}
	if (a[2] == 0 && a[3] <= 3) {
		return 1;
	}
	int w = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 1; j <= 3; ++j) {
			if (a[i] >= j) {
				a[i] -= j;
				if (dfs(a) == 0) {
					w = 1;
				}
				a[i] += j;
			}
		}
	}

	memo[a[0]][a[1]][a[2]][a[3]] = w;
	return w;
}

int main(int argc, char *argv[])
{
	memset(memo, -1, sizeof(memo));
	string s;
	getline(cin, s);
	stringstream ss(s);
	int N[4];
	ss >> N[0] >> N[1] >> N[2] >> N[3];
	cout << (dfs(N) ? "Taro" : "Jiro") << endl;
	return 0;
}
