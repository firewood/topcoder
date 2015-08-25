#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> IntVec;
typedef map<int, IntVec> IIVMap;

int main(int argc, char *argv[])
{
	int N, M, K;
	cin >> N >> M >> K;
	IIVMap m[100];
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		m[a - 1][c].push_back(b - 1);
		m[b - 1][c].push_back(a - 1);
	}
	int d[1000];
	for (int i = 0; i < K; ++i) {
		cin >> d[i];
	}
	int f[2][100] = {};
	for (int i = 0; i < N; ++i) {
		f[0][i] = 1;
	}
	for (int i = 0; i < K; ++i) {
		int prev = i & 1;
		int next = prev ^ 1;
		for (int j = 0; j < N; ++j) {
			f[next][j] = 0;
		}
		for (int j = 0; j < N; ++j) {
			if (f[prev][j]) {
				for (int a : m[j][d[i]]) {
					f[next][a] = 1;
				}
			}
		}
	}
	IntVec v;
	for (int i = 0; i < N; ++i) {
		if (f[K % 2][i]) {
			v.push_back(i + 1);
		}
	}
	cout << v.size() << endl;
	for (int i = 0; i < (int)v.size(); ++i) {
		if (i > 0) {
			cout << " ";
		}
		cout << v[i];
	}
	cout << endl;
	return 0;
}
