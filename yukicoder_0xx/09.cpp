#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> IntVec;
typedef pair<int, int> II;
typedef priority_queue<II> Queue;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	IntVec A(N), B(N);
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < N; ++i) {
			ss >> A[i];
		}
	}
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < N; ++i) {
			ss >> B[i];
		}
	}
	int ans = 1 << 30;
	for (int i = 0; i < N; ++i) {
		Queue q;
		for (int j = 0; j < N; ++j) {
			q.push(II(-A[j], 0));
		}
		for (int k = 0; k < N; ++k) {
			II x = q.top();
			q.pop();
			x.first -= B[(i + k) % N] / 2;
			x.second -= 1;
			q.push(x);
		}
		int m = 0;
		while (q.size()) {
			II x = q.top();
			q.pop();
			m = max(m, -x.second);
		}
		ans = min(ans, m);
	}
	cout << ans << endl;
	return 0;
}
