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
  i32 N, M;
  cin >> N >> M;
  vector<string> player(N);
  rep(i, N) {
    cin >> player[i];
  }

  i32 sum = 0;
  rep(i, N) {
    for (i32 j = i + 1; j < N; j++) {
      bool is_count = true;
      rep(k, M) {
        if (!(player[i][k] == 'o' || (player[i][k] == 'x' && player[j][k] == 'o'))) {
          is_count = false;
          break;
        }
      }
      sum += is_count;
    }
  }

  cout << sum << endl;
}