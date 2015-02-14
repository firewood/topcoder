#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	int C = atoi(s.c_str());
	getline(cin, s);
	int V = atoi(s.c_str());
	IntVec S(V), T(V), Y(V), M(V);
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < V; ++i) {
			ss >> S[i];
		}
	}
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < V; ++i) {
			ss >> T[i];
		}
	}
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < V; ++i) {
			ss >> Y[i];
		}
	}
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < V; ++i) {
			ss >> M[i];
		}
	}

	IntVec y[50][50];
	IntVec m[50][50];
	for (int i = 0; i < V; ++i) {
		int s = S[i] - 1, t = T[i] - 1;
		y[s][t].push_back(Y[i]);
		m[s][t].push_back(M[i]);
	}
	int cost[50][301];
	memset(cost, 0x3f, sizeof(cost));
	cost[0][0] = 0;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < y[j][i].size(); ++k) {
				int c = y[j][i][k];
				for (int l = 0; l <= (C - c); ++l) {
					cost[i][l + c] = min(cost[i][l + c], cost[j][l] + m[j][i][k]);
				}
			}
		}
	}

	int ans = 1 << 29;
	for (int i = 0; i <= C; ++i) {
		ans = min(ans, cost[N - 1][i]);
	}

	cout << (ans < (1<<29) ? ans : -1) << endl;
	return 0;
}
