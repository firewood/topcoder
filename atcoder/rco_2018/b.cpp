#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <sys/stat.h>

using namespace std;

int N;
int M;
int Q;
string S;
long double D;
vector<string> q;

int main(int argc, const char * argv[]) {
    cout.precision(10);
    string filename = argv[1] ? argv[1] : "";
    struct stat _stat;
    if (stat(filename.c_str(), &_stat) == 0) {
        freopen(filename.c_str(), "r", stdin);
    }
    cin >> N >> M >> Q;

    S = string(N, 'a');
	D = 4.8;
    bool ok = false;
    while (!ok) {
        for (int i = 0; i < N; ++i) {
            S[i] = 'a' + (rand() % 26);
        }
        random_shuffle(S.begin(), S.end());
        string x = S + S;
        set<string> s;
        ok = true;
        for (int i = 0; i < N; ++i) {
            string y = x.substr(i, M-3);
            if (s.find(y) != s.end()) {
                ok = false;
                break;
            }
            s.insert(y);
        }
    }

	string temp;
	for (char c : S) {
		int len = (rand() % 2) + 2;
		temp += string(len, c);
	}
	S = temp.substr(0, S.length());

    cout << S << endl;
    cout << D << endl;
    fflush(stdout);

    string ss = S + S;
    q.clear();
    for (int i = 0; i < Q; ++i) {
        string s;
        cin >> s;
        q.push_back(s);
    }

	for (int i = 0; i < Q; ++i) {
		int pos[8] = {};
		int mn = 1 << 30;
		int mni = 0;
		string target = q[i];
		for (int i = 1; i < (int)ss.length(); ++i) {
			for (int j = M; j >= 0; --j) {
				if (ss[i] == target[j]) {
					if (j == 0) {
						pos[j] = i;
					} else if (pos[j] < pos[j - 1]) {
						pos[j] = pos[j - 1];
						if (j == M - 1) {
							int len = i - pos[j] + 1;
							if (len < mn) {
								mn = len;
								mni = pos[j];
							}
						}
					}
				}
			}
		}
		cout << ((int)(mni - D * 0.5 + N) % N) << endl;
    }
    fflush(stdout);
    return 0;
}
