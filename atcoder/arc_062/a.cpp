// A.

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	set<int> s;
	for (int i = 0; i < 3; ++i) {
		int c;
		cin >> c;
		s.insert(c);
	}
	cout << s.size() << endl;
	return 0;
}
