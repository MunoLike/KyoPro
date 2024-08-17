#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (i32 i = 1; i <= (n); (i)++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const i32 dx[] = {0, 1, 0, -1, -1, 1, 1, -1};

template <class S, class T>
inline S prevent_oor(S a, const T b) {
  a %= b;
  if (a < 0) {
    a += b;
  }
  return a;
}

template <class S, class T>
inline S chmax(S& a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}

template <class S, class T>
inline S chmin(S& a, T b) {
  if (a > b) {
    a = b;
  }
  return a;
}

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

typedef struct _point {
  i32 a, b;
} Point;

bool is_collisioned(Point& a1, Point& a2) {
  if (a1.a > a1.b) swap(a1.a, a1.b);
  if (a2.a > a2.b) swap(a2.a, a2.b);

  if (a1.b <= a2.a || a1.a >= a2.b) {
    return false;
  } else {
    return true;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  i32 A[6], B[6];
  rep(i, 6) cin >> A[i];
  rep(i, 6) cin >> B[i];

  Point C1[3] = {{A[0], A[3]}, {A[1], A[4]}, {A[2], A[5]}}, C2[3] = {B[0], B[3], {B[1], B[4]}, {B[2], B[5]}};

  bool isc = true;

  rep(i, 3) {
    isc &= is_collisioned(C1[i], C2[i]);
  }
  cout << (isc ? "Yes\n" : "No\n");
}