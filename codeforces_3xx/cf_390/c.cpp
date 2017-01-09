// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;

typedef map<string, int> StrIntMap;

vector<string> split(const char *delim, const string &words) {
	vector<string> res;
	char buffer[65536];
	strcpy(buffer, words.c_str());
	char *word = strtok(buffer, delim);
	while (word != NULL) {
		res.push_back(word);
		word = strtok(NULL, delim);
	}
	return res;
}

bool solve(vector<string> &names, vector<string> &chats) {
	int N = (int)names.size();
	int C = (int)chats.size();

	StrIntMap name2id;
	name2id["?"] = -1;
	for (int i = 0; i != names.size(); ++i) {
		name2id[names[i]] = i;
	}

	int user_ids[100];
	vector<int> user_can[100];
	for (int i = 0; i < C; ++i) {
		int pos = (int)chats[i].find(':');
		string name = chats[i].substr(0, pos);
		chats[i] = chats[i].substr(pos);
		user_ids[i] = name2id[name];
		if (user_ids[i] == -1) {
			set<int> s;
			for (int j = 0; j < N; ++j) {
				s.insert(j);
			}
			if (i > 0) {
				s.erase(user_ids[i - 1]);
			}
			for (auto w : split(" .,:!?", chats[i])) {
				StrIntMap::const_iterator it = name2id.find(w);
				if (it != name2id.end()) {
					s.erase(it->second);
				}
			}
			if (s.empty()) {
				return false;
			}
			user_can[i] = vector<int>(s.begin(), s.end());
		}
	}

	for (int t = 0; t < 100000; ++t) {
		int u[100];
		int i;
		for (i = 0; i < C; ++i) {
			int a = user_ids[i];
			if (a == -1) {
				a = user_can[i][rand() % user_can[i].size()];
			}
			if (i > 0 && u[i - 1] == a) {
				break;
			}
			u[i] = a;
		}
		if (i >= C) {
			for (int i = 0; i < C; ++i) {
				cout << names[u[i]];
				cout << chats[i] << endl;
			}
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		vector<string> names, chats;
		getline(cin, s);
		int N = atoi(s.c_str());
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < N; ++i) {
			string name;
			ss >> name;
			names.push_back(name);
		}
		getline(cin, s);
		int C = atoi(s.c_str());
		for (int i = 0; i < C; ++i) {
			getline(cin, s);
			chats.push_back(s);
		}
		if (!solve(names, chats)) {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
