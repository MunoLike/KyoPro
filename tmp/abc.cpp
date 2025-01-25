#include <array>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

constexpr std::size_t MAX_SIZE = 400;  // 配列のサイズ

// 素数判定用の関数
constexpr bool is_prime(std::size_t n) {
    if (n < 2) return false;
    for (std::size_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// 素数配列を作成する関数
constexpr auto generate_prime_array() {
    std::array<bool, MAX_SIZE> primes = {};
    for (std::size_t i = 0; i < MAX_SIZE; ++i) {
        primes[i] = is_prime(i);
    }
    return primes;
}

constexpr auto prime_array = generate_prime_array();

int main() {
    vector<int> a;
    cout << a.back() << endl;
}
