#include <iostream>
#include <cstdint>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
	set<int64_t> s[2];
	int64_t A;
	cin >> A;
	int prev = 0, curr = 1;
	for (int64_t i = 3; i <= A; i = (i - 1) * (i - 1) + 1) {
		prev ^= 1, curr ^= 1;
		s[curr] = s[prev];
		s[curr].insert(i);
		for (int64_t k : s[prev]) {
			if (i * k <= A) {
				s[curr].insert(i * k);
			}
		}
	}
	s[prev] = s[curr];
	for (int64_t i = 2; i <= A; i *= 2) {
		s[curr].insert(i);
		for (int64_t k : s[prev]) {
			if (i * k <= A) {
				s[curr].insert(i * k);
			}
		}
	}
	cout << (s[curr].size() - 1) << endl;
	return 0;
}
