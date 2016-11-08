#include <iostream>
#include <sstream>
int main(int argc, char *argv[]) {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::string s;
		std::cin >> s;
		int w[1000];
		for (int i = 0; i != s.length(); ++i) {
			w[i] = s[i] - '0';
		}
		for (int i = s.length(); i > 1; --i) {
			for (int j = 1; j < i; ++j) {
				int a = w[j - 1] + w[j];
				w[j - 1] = (a / 10) + (a % 10);
			}
		}
		std::cout << w[0] << std::endl;
	}
	return 0;
}
