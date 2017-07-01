// C.

#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int n, a;
	list<int> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (i % 2) {
			v.push_back(a);
		} else {
			v.push_front(a);
		}
	}
	if (n % 2) {
		list<int>::iterator it;
		for (it = v.begin(); it != v.end(); ++it) {
			cout << *it << " ";
		}
	} else {
		list<int>::reverse_iterator it;
		for (it = v.rbegin(); it != v.rend(); ++it) {
			cout << *it << " ";
		}
	}
	cout << endl;
	return 0;
}
