/*
Google Code Jam 2013 Qualification Round 
Problem D. Treasure
*/

#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> IntVec;
typedef set<int> IntSet;


struct node {
	int open;
	char inside[40];
	IntSet queued;
	node() {
		memset(inside, 0, sizeof(inside));
	}
};
typedef vector<node> NodeVec;


struct route {
	int distance;
	int visited;
	char history[20];
	char keys[40];
	route() : distance(0), visited(0) {
		memset(history, 0, sizeof(history));
		memset(keys, 0, sizeof(keys));
	}
};
typedef vector<route> RouteQueue;

struct solver {
	int K;
	int N;
	NodeVec nodes;
	bool dfs(route &current, int next_node);
	IntVec solve();
};

bool solver::dfs(route &current, int next_node)
{
	node &next = nodes[next_node];
	if (current.keys[next.open] <= 0) {
		return false;
	}
	int mask = current.visited | (1 << next_node);
	if (current.visited == mask || next.queued.find(mask) != next.queued.end()) {
		return false;
	}
	next.queued.insert(mask);
	current.visited = mask;
	current.history[current.distance++] = next_node;
	current.keys[next.open] -= 1;
	int i;
	for (i = 0; i < 40; ++i) {
		current.keys[i] += next.inside[i];
	}
	if (current.distance >= N) {
		return true;
	}
	for (i = 0; i < N; ++i) {
		if ((mask & (1 << i)) == 0) {
			route r = current;
			if (dfs(r, i)) {
				current = r;
				return true;
			}
		}
	}
	return false;
}

IntVec solver::solve()
{
	IntVec ans;
	int i, j, k, l;
	string s;
	getline(cin, s);
	{
		stringstream ss(s);
		ss >> K >> N;
	}
	if (K <= 0 || N <= 0) {
		return ans;
	}

	char keys[40] = {};
	getline(cin, s);
	{
		stringstream ss(s);
		for (i = 0; i < K; ++i) {
			ss >> k;
			keys[k-1] += 1;
		}
	}

	nodes.resize(N);
	for (i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		ss >> k;
		nodes[i].open = k - 1;
		ss >> k;
		for (j = 0; j < k; ++j) {
			ss >> l;
			nodes[i].inside[l-1] += 1;
		}
	}

	for (i = 0; i < N; ++i) {
		route current;
		memcpy(current.keys, keys, sizeof(keys));
		if (dfs(current, i)) {
			for (i = 0; i < N; ++i) {
				ans.push_back(current.history[i]);
			}
			return ans;
		}
	}

	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 0; t < T; ++t) {
		cout << "Case #" << (t+1) << ":";
		solver x;
		IntVec ans = x.solve();
		if (ans.size() <= 0) {
			cout << " IMPOSSIBLE";
		} else {
			for (int i = 0; i < (int)ans.size(); ++i) {
				cout << " " << (ans[i] + 1);
			}
		}
		cout << endl;
	}

    return 0;
}

