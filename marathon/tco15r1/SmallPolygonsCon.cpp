#include "stdafx.h"
#include "SmallPolygons.h"
/*
#include <Windows.h>
#include <TChar.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "SmallPolygons.h"
*/

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
#if 0

	IISet s;
	for (int i = 0; i < 20; ++i) {
		int x = (rand() * 500) / (RAND_MAX + 1);
		int y = (rand() * 500) / (RAND_MAX + 1);
		s.insert(II(x, y));
	}

	int N = 10;
	int Np = s.size();
	vector<int> points(Np);
	for (auto p : s) {
		points.push_back(p.first);
		points.push_back(p.second);
	}

	SmallPolygons sp;
	vector<string> ret = sp.choosePolygons(points, N);

#else
	string s;
	getline(cin, s);
	int Np = atoi(s.c_str());
	vector<int> points(Np);
	for (int i = 0; i < Np; ++i) {
		getline(cin, s);
		points[i] = atoi(s.c_str());
	}
	getline(cin, s);
	int N = atoi(s.c_str());

	SmallPolygons sp;
	vector<string> ret = sp.choosePolygons(points, N);
	cout << ret.size() << endl;
	for (string vertices : ret) {
		cout << vertices << endl;
	}
#endif

	return 0;
}
