// B.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	set<int> s(d.begin(), d.end());
	cout << s.size() << endl;
	return 0;
}
