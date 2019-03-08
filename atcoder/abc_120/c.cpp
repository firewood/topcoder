// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int ans = 0;
	deque<char> q;
	for (char c : s) {
		q.push_front(c);
		while (q.size() >= 2 && q[0] != q[1]) {
			ans += 2;
			q.pop_front();
			q.pop_front();
		}
	}
	cout << ans << endl;
	return 0;
}
