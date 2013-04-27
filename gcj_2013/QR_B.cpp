/*
Google Code Jam 2013 Qualification Round 
Problem B. Lawnmower
*/

#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int grass[100][100];

bool solve(int N, int M)
{
	int colh[100];
	int rowh[100];
	int i, j, x, y;
	for (i = 0; i < 100; ++i) {
		colh[i] = rowh[i] = 100;
	}
	for (y = 0; y < N; ++y) {
		int m = rowh[y] = *max_element(grass[y], grass[y] + M);
		for (x = 0; x < M; ++x) {
			if (grass[y][x] < m) {
				colh[x] = min(colh[x], grass[y][x]);
			}
		}
	}
	for (x = 0; x < M; ++x) {
		int m = 0;
		for (y = 0; y < N; ++y) {
			m = max(m, grass[y][x]);
		}
		colh[x] = min(colh[x], m);
		for (y = 0; y < N; ++y) {
			if (grass[y][x] < m) {
				rowh[y] = min(rowh[y], grass[y][x]);
			}
		}
	}

	for (y = 0; y < N; ++y) {
		for (x = 0; x < M; ++x) {
			if (grass[y][x] > min(colh[x], rowh[y])) {
				return false;
			}
		}
	}
	return true;
}


int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		int N = 0, M = 0;
		getline(cin, s);
		{
			stringstream ss(s);
			ss >> N >> M;
		}
		if (N <= 0 || M <= 0) {
			break;
		}

		for (int i = 0; i < N; ++i) {
			getline(cin, s);
			stringstream ss(s);
			for (int j = 0; j < M; ++j) {
				ss >> grass[i][j];
			}
		}

		string ans = solve(N, M) ? "YES" : "NO";
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}

	return 0;
}

