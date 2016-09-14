#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= 10; ++i) {
        printf("%d x %d = %d\n", N, i, N * i);
    }
    return 0;
}
