#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> m;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string k, v;
        cin >> k >> v;
        m[k] = v;
    }
    while (true) {
        string k;
        cin >> k;
        if (k.empty()) {
            break;
        }
        string v = m[k];
        cout << (v.empty() ? "Not found" : (k + "=" + v)) << endl;
    }
    return 0;
}
