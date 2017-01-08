// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;

typedef map<string, int> StrIntMap;

void solve(StrIntMap names, vector<string> chats) {
	string nn[100];
	for (auto kv : names) {
		nn[kv.second] = kv.first;
	}

	vector<string> outputs = chats;
	int N = (int)names.size();
	int C = (int)chats.size();
	names["?"] = -1;
	set<int> m[100];
	int u[102];
	for (int i = 0; i < 102; ++i) {
		u[i] = -1;
	}
	for (int i = 0; i < C; ++i) {
		int pos = chats[i].find(':');
		string name = chats[i].substr(0, pos);
		u[i + 1] = names[name];
		if (u[i + 1] == -1) {
			outputs[i] = chats[i].substr(pos);
			for (int j = 0; j < N; ++j) {
				m[i].insert(j);
			}
			char w[100];
			strcpy(w, chats[i].c_str());
			const char *delim = " .,:!?";
			char *p = strtok(w, delim);
			while (p != NULL) {
				StrIntMap::const_iterator it = names.find(p);
				if (it != names.end()) {
					m[i].erase(it->second);
				}
				p = strtok(NULL, delim);
			}
		}
	}
	vector<int> vv[100];
	for (int i = 0; i < C; ++i) {
		if (u[i + 1] == -1) {
			m[i].erase(u[i]);
			m[i].erase(u[i + 2]);
			if (m[i].empty()) {
				cout << "Impossible" << endl;
				return;
			}
			vv[i] = vector<int>(m[i].begin(), m[i].end());
		}
	}

	int x[102] = { -1 };
	for (int t = 0; t < 100000; ++t) {
		int i;
		for (i = 0; i < C; ++i) {
			int a = u[i + 1];
			if (a == -1) {
				for (int j = 0; j < 10; ++j) {
					a = vv[i][rand() % vv[i].size()];
					if (a != x[i]) {
						break;
					}
				}
			}
			x[i + 1] = a;
			if (x[i] == a) {
				break;
			}
		}
		if (i >= C) {
			for (int i = 0; i < C; ++i) {
				if (u[i + 1] == -1) {
					cout << nn[x[i + 1]];
				}
				cout << outputs[i] << endl;
			}
			return;
		}
	}
	cout << "Impossible" << endl;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		map<string, int> names;
		getline(cin, s);
		int N = atoi(s.c_str());
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < N; ++i) {
			string name;
			ss >> name;
			names[name] = i;
		}
		vector<string> chats;
		getline(cin, s);
		int C = atoi(s.c_str());
		for (int i = 0; i < C; ++i) {
			getline(cin, s);
			chats.push_back(s);
		}
		solve(names, chats);
	}
	return 0;
}
