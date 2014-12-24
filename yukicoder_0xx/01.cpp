#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef vector<int> IntVec;
typedef vector<III> IIIVec;

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
	IIIVec v[64];
	for (int i = 0; i < V; ++i) {
		if (Y[i] <= C) {
			v[S[i] - 1].push_back(III(-Y[i], II(T[i] - 1, M[i])));
		}
	}
	int ans = 1 << 30;
	priority_queue<III> q;
	for (int i = 0; i < v[0].size(); ++i) {
		q.push(v[0][i]);
	}
	while (q.size() > 0) {
		III current = q.top();
		q.pop();
		int pos = current.second.first;
		if (pos == N - 1) {
			ans = min(ans, current.second.second);
		}
		for (int i = 0; i < v[pos].size(); ++i) {
			III &e = v[pos][i];
			int cost = current.first + e.first;
			if (-cost <= C) {
				int time = current.second.second + e.second.second;
				q.push(III(cost, II(e.second.first, time)));
			}
		}
	}
	cout << (ans < (1<<30) ? ans : -1) << endl;
	return 0;
}
