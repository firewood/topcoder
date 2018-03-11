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
    D = 1.0;
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
            string y = x.substr(i, M);
            if (s.find(y) != s.end()) {
                ok = false;
                break;
            }
            s.insert(y);
        }
    }
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
        size_t pos = ss.find(q[i]);
        if (pos == string::npos) {
            pos = rand() % N;
        }
        cout << pos << endl;
    }
    fflush(stdout);
    return 0;
}
