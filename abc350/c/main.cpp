#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
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
inline S chmax(S &a, T b) {
  if (a < b) {
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

int main() {
  i32 N;
  cin >> N;
  vector<i32> arr(N + 1), idxes(N + 1);
  vector<pair<i32, i32>> hist;
  rep1(i, N) cin >> arr[i], idxes[arr[i]] = i;

  auto op = [&](i32 i, i32 j) {
    swap(idxes[arr[i]], idxes[arr[j]]);
    swap(arr[i], arr[j]);
    hist.emplace_back(i, j);
  };

  rep1(i, N) {
    if (arr[i] != i) {
      op(i, idxes[i]);
    }
  }

  cout << hist.size() << endl;
  for (auto [x, y] : hist) {
    cout << x << " " << y << "\n";
  }
}