// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
	set<string> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string x;
		cin >> x;
		s.emplace(x);
	}
	cout << s.size() << endl;
	return 0;
}
