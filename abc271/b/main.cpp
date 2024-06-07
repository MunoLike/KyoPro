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
  i32 N, Q;
  cin >> N >> Q;
  vector<vector<i32>> A;
  rep(i, N) {
    i32 L;
    cin >> L;
    vector<i32> A_in(L);
    rep(j, L) { cin >> A_in[j]; }
    A.emplace_back(A_in);
  }

  rep(i, Q) {
    i32 S, T;
    cin >> S >> T;
    --S, --T;
    cout << A[S][T] << endl;
  }
}