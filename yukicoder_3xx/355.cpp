#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

void send(int *n, int &x, int &y) {
	printf("%d %d %d %d\n", n[0], n[1], n[2], n[3]);
	fflush(stdout);
	char buff[1024];
	fgets(buff, 1024, stdin);
	sscanf(buff, "%d %d", &x, &y);
}

int main(int argc, char *argv[])
{
	int n[4] = { 1, 2, 3, 4 }, x, y, cnt = 0, f[10] = {}, i = 0, r = 0;
	send(n, x, y);
	while (x + y < 4) {
		int prev = n[i];
		while (n[i] == prev) {
			n[i] = ++r % 10;
			if (f[n[i]]) {
				n[i] = prev;
				continue;
			}
			for (int j = 0; j < 4; ++j) {
				if (i != j && n[i] == n[j]) {
					n[i] = prev;
					break;
				}
			}
		}
		int a = x, b = y;
		send(n, x, y);
		if (x < a || y < b) {
			if (x + y < a + b) {
				f[n[i]] = 1;
			}
			f[prev] = 1;
			n[i] = prev;
			x = a, y = b;
			++i;
		}
	}
	if (x < 4) {
		sort(n, n + 4);
		while (x < 4) {
			send(n, x, y);
			next_permutation(n, n + 4);
		}
	}
	return 0;
}
