#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

set<string> m;

void dfs(string a, string b) {
	if (a.length() > 0) {
		dfs(a.substr(1), b + a.front());
		dfs(a.substr(0, a.length() - 1), b + a.back());
	} else {
		m.insert(b);
	}
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	dfs(s, "");
	cout << m.size() << endl;
	return 0;
}
