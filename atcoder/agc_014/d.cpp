// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

set<int> e[100001];
set<int> leaves;
set<int> hl[100001];

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].insert(b);
		e[b].insert(a);
	}
	bool first = false;
	for (int i = 1; i <= n; ++i) {
		if (e[i].size() == 1) {
			leaves.insert(i);
			hl[*e[i].begin()].insert(i);
			if (hl[*e[i].begin()].size() >= 2) {
				first = true;
			}
		}
	}
	bool f = true;
	while (f && !first && leaves.size() > 0) {
		f = false;
		set<int> nl;
		int n;
		for (int l : leaves) {
			int p = *e[l].begin();
			if (e[p].size() != 2) {
				nl.insert(l);
			} else {
				f = true;
				int a = *e[p].begin();
				int b = *e[p].rbegin();
				if (a == l) {
					a = b;
				}
				e[a].erase(p);
				if (e[a].size() == 1) {
					nl.insert(a);
					p = *e[a].begin();
					hl[p].insert(a);
					if (hl[p].size() >= 2) {
						first = true;
					}
				}
			}
		}
		leaves = nl;
	}
	cout << (first ? "First" : "Second") << endl;
	return 0;
}
