// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string c;
	cin >> c;
	const string vowel = "aiueo";
	cout << (vowel.find(c) != string::npos ? "vowel" : "consonant") << endl;
	return 0;
}
