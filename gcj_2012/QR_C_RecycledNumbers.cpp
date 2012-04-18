
//
// Google Code Jam 2012 QR
// C. Recycled Numbers
//

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> IntVec;
typedef map<int, int> IntMap;

// union find tree
// http://www.prefield.com/algorithm/container/union_find.html
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

static int solve(int A, int B) {
	int res = 0;
	UnionFind uf(10000);
	char t[16] = {};
	char w[8] = {};
	int i, j;
	for (i = A; i <= B; ++i) {
		if (uf.size(i) > 1) {
			continue;
		}
		sprintf(t, "%d", i);
		int digits = strlen(t);
		sprintf(t + digits, "%d", i);
		for (j = 1; j < digits; ++j) {
			memcpy(w, t + j, digits);
			int x = atoi(w);
			if (x != i && x >= A && x <= B) {
				uf.unionSet(i, x);
			}
		}
	}

	for (i = A; i <= B; ++i) {
		if (uf.size(i) > 1) {
			res += uf.size(i) - 1;
		}
	}
	res /= 2;

	return res;
}

int main(int argc, char *argv[])
{
	int t, T;
	cin >> T;
	for (t = 0; t < T; ++t) {
		int A, B;
		cin >> A >> B;
		int res = solve(A, B);
		cout << "Case #" << (t+1) << ": " << res << endl;
	}

	return 0;
}

