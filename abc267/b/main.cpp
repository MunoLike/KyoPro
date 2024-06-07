#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const i32 dx[] = {0, 1, 0, -1, -1, 1, 1, -1};

inline int64_t div_floor(int64_t a, int64_t b) {
  if (b < 0) {
    a *= -1;
    b *= -1;
  }
  if (a < 0) {
    return (a + 1) / b - 1;
  } else {
    return a / b;
  }
}

inline int64_t div_ceil(int64_t a, int64_t b) {
  return div_floor(a + b - 1, b);
}

int main() {
  string S;
  cin >> S;
  if (S[0] == '1') {
    cout << "No\n";
    return 0;
  }

  vector<bool> column(7);
  column[0] = S[6] == '1';
  column[1] = S[3] == '1';
  column[2] = S[1] == '1' or S[7] == '1';
  column[3] = S[0] == '1' or S[4] == '1';
  column[4] = S[2] == '1' or S[8] == '1';
  column[5] = S[5] == '1';
  column[6] = S[9] == '1';

  rep(i, 7) {
    for (i32 j = i + 2; j < 7; j++) {
      if (column[i] and column[j]) {
        bool ok = false;
        for (i32 k = i + 1; k < j; k++) {
          ok |= !column[k];
        }
        if (ok) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";
}