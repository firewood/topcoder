#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	std::cin >> s;
	std::cout << "yukicoder"[s.find('?')] << std::endl;
	return 0;
}
