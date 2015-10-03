#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

typedef pair<int, string> IS;
typedef vector<IS> isvec;
typedef map<string, int> strintmap;
typedef set<string> StrSet;
typedef vector<string> StrVec;

static string query_url = "http://game.coderunner.jp/query?token=";
static string token = "PFORDSHYVNJC2G3XQ5NVNBUS74PU6SV2";

string query(string str) {
	FILE *f = _popen(("curl.exe -s \"" + query_url + token + "&" + str + "\"").c_str(), "r");
    if (f == NULL) {
        perror("error!");
    }
    char buf[1024];
    string res;
    while (!feof(f)) {
        if (fgets(buf, 1024, f) == NULL) break;
        res += (string)(buf);
    }
    _pclose(f);
    return res;
}

int main() {
	srand(GetTickCount());

	FILE *out = fopen("points3.txt", "wt");
	if (!out) {
		return 0;
	}

	static int dist[1000][1000];
	memset(dist, -1, sizeof(dist));
	while (1) {
		int p = (rand() * 1000) / (RAND_MAX + 1);
		int q = (rand() * 1000) / (RAND_MAX + 1);
		int a = min(p, q);
		int b = max(p, q);
		if (a == b) {
			continue;
		}
		if (dist[a][b] >= 0) {
			continue;
		}
		char w[256];
		sprintf(w, "v=%d,%d", a, b);
		string res = query(w);
		if (res.empty() || res[0] < '0') {
			Sleep(100);
			continue;
		}
		int d = atoi(res.c_str());
		dist[a][b] = d;
		cout << w << "," << d << endl;
		fprintf(out, "%d %d %d\n", a, b, d);
		fflush(out);
		Sleep(950);

		if (_kbhit()) {
			break;
		}
	}

	return 0;
}
