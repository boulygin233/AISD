#include <iostream>
#include <vector>

using std::vector;
using std::swap;
using std::cin;
using std::cout;

unsigned int a, b;
unsigned int cur = 0;

unsigned int nextRand() {
    cur = cur * a + b;
    return cur >> 8;
}

int main() {
    unsigned m, q;
    cin >> m >> q >> a >> b;
    unsigned const n = (1 << 24);
    vector<long long> segments(n + 1, 0);
    unsigned add, l, r;
    for (int i = 0; i < m; ++i) {
        add = nextRand();
        l = nextRand();
        r = nextRand();
        if (l > r) {
            swap(l, r);
        }
        segments[l] += add;
        segments[r + 1] -= add;
    }
    long long curr = 0;
    long long part_sum = 0;
    vector<unsigned> partial_sums(n, 0);
    for (int i = 0; i < n; ++i) {
        curr += segments[i];
        part_sum += curr;
        partial_sums[i] = part_sum;
    }
    unsigned result = 0;
    for (int i = 0; i < q; ++i) {
        l = nextRand();
        r = nextRand();
        if (l > r) {
            swap(l, r);
        }
        if (l == 0) {
            result += partial_sums[r];
        } else {
            result += partial_sums[r] - partial_sums[l - 1];
        }
    }
    cout << result;
}

