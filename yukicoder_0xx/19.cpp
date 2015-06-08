#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> IntVec;

int Level[100];
int Dependencies[100];
IntVec Edges[100];
int Visited[100];
int Cleared[100];

int dfs(int a) {
	int s = Level[a] / 2;
	Visited[a] = 1;
	for (int b : Edges[a]) {
		if (!Visited[b] && !Cleared[b]) {
			s += dfs(b);
		}
	}
	return s;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int L, S;
		ss >> L >> S;
		Level[i] = L * 2;
		Dependencies[i] = S - 1;
		Edges[S - 1].push_back(i);
	}

	int tot = 0;
	int cl = 0;
	while (cl < N) {
		int n = -1;
		int s = -1;
		for (int i = 0; i < N; ++i) {
			if (!Cleared[i]) {
				memset(Visited, 0, sizeof(Visited));
				int e = dfs(i) - Level[i] / 2;
				if (e > s) {
					n = i;
					s = e;
				}
			}
		}
		tot += Cleared[Dependencies[n]] ? Level[n] / 2 : Level[n];
		Cleared[n] = 1;
		++cl;
	}
	printf("%.1f\n", (double)tot * 0.5);
	return 0;
}
