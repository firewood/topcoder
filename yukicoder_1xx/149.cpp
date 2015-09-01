#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int Aw, Ab, Bw, Bb, C, D;
	cin >> Aw >> Ab >> Bw >> Bb >> C >> D;
	int b = min(Ab, C);
	int w = C - b;
	Aw -= w;
	Bw += w;
	w = min(Bw, D);
	Aw += w;
	cout << Aw << endl;
	return 0;
}
