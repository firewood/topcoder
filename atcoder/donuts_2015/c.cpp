// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef DEBUG
    char w[1024];
    getcwd(w, 1024);
    freopen("./in_c.txt", "r", stdin);
#endif
    int n, h;
	cin >> n;
	stack<int> q;
	for (int i = 0; i < n; ++i) {
        cout << q.size() << endl;
		cin >> h;
        while (!q.empty() && q.top() < h) {
            q.pop();
        }
        q.push(h);
	}
	return 0;
}
