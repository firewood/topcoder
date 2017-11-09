// D.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[])
{
	int k;
	cin >> k;
	deque<II> q;
	q.push_back(II(1, 1));
	vector<int> vis(k + 1, 1 << 30);
	while (!q.empty()) {
		II top = q.front();
		q.pop_front();
		int x = top.first, y = top.second;
		if (y < vis[x]) {
			vis[x] = y;
			q.push_front(II((x * 10) % k, y));
			q.push_back(II((x + 1) % k, y + 1));
		}
	}
	cout << vis[0] << endl;
}
