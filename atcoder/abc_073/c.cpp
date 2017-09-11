// C.

#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	int n, a;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (s.find(a) == s.end()) {
			s.insert(a);
		} else {
			s.erase(a);
		}
	}
	cout << s.size() << endl;
	return 0;
}
