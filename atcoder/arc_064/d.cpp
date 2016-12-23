// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	list<char> v;
	for (char c : s) {
		v.push_back(c);
	}
	list<char>::iterator curr = v.begin();
	++curr;
	bool ans = false;
	while (true) {
		list<char>::iterator prev = curr;
		--prev;
		list<char>::iterator next = curr;
		++next;
		if (next == v.end()) {
			break;
		}
		if (*prev != *next) {
			ans = !ans;
			v.erase(curr);
			curr = next;
			if (prev != v.begin()) {
				curr = prev;
			}
		} else {
			curr = next;
		}
	}
	cout << (ans ? "First" : "Second") << endl;
	return 0;
}
