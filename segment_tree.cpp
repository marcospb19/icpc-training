#include <cassert>
/*
    `Segment Tree` template with O(n) building and O(log n) queries

    !!!!!!!
    Note: inner implementation is 1-indexed and the outer-interface is 0-indexed!
    !!!!!!!
*/
///
#define combine(a, b) ((a) + (b))
#define NEUTRAL 0

template <typename T>
struct SegmentTree {
    T *t;
    int n;
    int cap;

    SegmentTree(int temp) {
        t = new T[cap = 2 * (n = temp)];
    }

    void operator()(int temp) {
        n = temp;
        assert(n < cap * 2);
    }

    T &leaf(int i) {
        return t[n + i];
    }

    // Query range [l, r)
    T query(int l, int r) {
        assert(0 <= l && l < r && r <= n);
        int ans = NEUTRAL;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                ans = combine(ans, t[l++]);
            }
            if (r & 1) {
                ans = combine(ans, t[--r]);
            }
        }
        return ans;
    }

    void modify(int pos, T value) {
        assert(0 <= pos and pos < n);
        at(pos) = value;

        for (int i = (pos + n) >> 1; i >= 1; i >>= 1) {
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
        }
    }

    T &at(int index) {
        return t[n + index];
    }

    void build() {
        for (int i = n - 1; i >= 1; i--) {
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
        }
    }
    // int main() {
    //     SegmentTree<int> st(1e5);
    //     int n;
    //     cin >> n;
    //     st(n);
    //     for (int i = 0; i < n; i++) {
    //         cin >> st.leaf(i);
    //     }
    //     st.build();
    // }

    // .query(l, r) and .modify(pos, val)
    //
    // How to drive from 1-indexed
    // st.query(pos - 1, pos); // Segment [pos, pos + 1) == [pos, pos]
    // st.modify(pos - 1, val);
    //
    // How to drive from 0-indexed
    // st.query(pos, pos + 1); // Segment [pos, pos + 1) == [pos, pos]
    // st.modify(pos, val);
};
