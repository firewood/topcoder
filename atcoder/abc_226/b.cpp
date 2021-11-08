#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	string x;
	getline(cin, x);
	int64_t N = stoll(x);
	set<string> s;
	for (int i = 0; i < N; i++) {
		getline(cin, x);
		s.insert(x);
	}
	cout << s.size() << endl;
	return 0;
}
