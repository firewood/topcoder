// B. 

#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	set<string> m;
	bool ans = true;
	char prev = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if ((prev && prev != s[0]) || m.find(s) != m.end()) {
			ans = false;
		}
		prev = s.back();
		m.insert(s);
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
