#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int L = atoi(s.c_str());
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		ss >> v[i];
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		if (sum + v[i] > L) {
			break;
		}
		++ans;
		sum += v[i];
	}
	cout << ans << endl;
	return 0;
}
