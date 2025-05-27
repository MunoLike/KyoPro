#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
inline S prevent_oor(S a, const T b) {
    a %= b;
    if (a < 0) {
        a += b;
    }
    return a;
}
int main() {
    int a = 10;
    cout << prevent_oor(-7, 10) << endl;
}
