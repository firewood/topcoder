// Google Code Jam 2020 Round 1B
// Problem B. Blindfolded Bullseye

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>
#include <cmath>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

vector<int> get_ints() {
	vector<int> r;
	string s;
	getline(cin, s);
	stringstream ss(s);
	while (true) {
		string v;
		ss >> v;
		if (v.empty()) {
			break;
		}
		r.push_back(atoi(v.c_str()));
	}
	return r;
}

void solve(int A, int B) {
	double side_length = 2000000000;
	double diameter = 2.0 * A;
	double sq2 = sqrt(2);
	int min_dist = (int)((diameter - diameter / sq2) / 2);
	int max_dist = (int)(side_length - diameter / sq2);
	int cx = 0, cy = 0;
	for (int v = -1; v <= 1; v += 2) {
		for (int h = -1; h <= 1; h += 2) {
			int left = min_dist - 1, right = max_dist + 1;
			for (int i = 0; i < 30; ++i) {
				int mid = (left + right) / 2;
				int x = (1000000000 - mid) * h;
				int y = (1000000000 - mid) * v;
				printf("%d %d\n", x, y);
				fflush(stdout);
				string s;
				getline(cin, s);
				if (s == "MISS") {
					left = mid;
				}
				if (s == "HIT") {
					right = mid;
				}
				if (s == "CENTER") {
					return;
				}
			}
			cx += -left * h;
			cy += -left * v;
		}
	}
	cx /= 2;
	cy /= 2;
	for (int x = cx - 2; x <= cx + 2; ++x) {
		for (int y = cy - 2; y <= cy + 2; ++y) {
			printf("%d %d\n", x, y);
			fflush(stdout);
			string s;
			getline(cin, s);
			if (s == "CENTER") {
				return;
			}
		}
	}
	printf("0 0\n");
	fflush(stdout);
	string s;
	getline(cin, s);
}

int main(int argc, char* argv[]) {
#if defined(_WIN32) && defined(_DEBUG)
	Sleep(5000);
#endif
	vector<int> x = get_ints();
	assert(x.size() == 3);
	int T = x[0], A = x[1], B = x[2];
	for (int t = 0; t < T; ++t) {
		solve(A, B);
	}
	return 0;
}
