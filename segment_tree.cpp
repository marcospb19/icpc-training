/*
    Generic `Segment Tree` with O(n) building and O(log n) queries
    Note that the implementation is 1-indexed and the interface is 0-indexed

    The memory leak is actually an performance feature :D, yeah, I'm serious
*/

#include <assert.h>
#include <string.h>

#include <iostream>
using namespace std;

///
#define combine(a, b) ((a) * (b))
#define NEUTRAL int(1)

template <typename T>
struct SegmentTree {
    T* t;
    int n;

    SegmentTree(int temp) {
        t = new T[n = temp];
    }

    void operator()(int temp) {
        n = temp;
    }

    T& leaf(int i) {
        return t[n + i];
    }

    // Query range [l, r)
    T query(int l, int r) {
        assert(r <= n);
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
        at(pos) = value;

        for (int i = (pos + n) >> 1; i >= 1; i >>= 1) {
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
        }
    }

    T& at(int index) {
        return t[n + index];
    }

    void build() {
        for (int i = n - 1; i >= 1; i--) {
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
        }
    }
};
///

int main() {
    SegmentTree<int> st(1e5);

    int n;
    cin >> n;

    st(n);

    for (int i = 0; i < n; i++) {
        cin >> st.leaf(i);
    }

    st.build();
}

/*
        Generic `Segment Tree` with O(n) building and O(log n) queries
        Note that the implementation is 1-indexed and the interface is 0-indexed
*/

#include <assert.h>
#include <string.h>

#include <iostream>
using namespace std;

///
#define combine(a, b) ((a) + (b))
#define NEUTRAL int(0)

template <typename T>
struct SegmentTree {
    T* t;
    int n;

    // Query range [l, r)
    T query(int l, int r) {
        assert(r <= n);
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
        at(pos) = value;

        for (int i = (pos + n) >> 1; i >= 1; i >>= 1) {
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
        }
    }

    T& at(int index) {
        return t[n + index];
    }

    void build() {
        for (int i = n - 1; i >= 1; i--) {
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
        }
    }
};
///

int main() {
    int n = 4;
    int list[4] = {1, 2, 3, 4};

    SegmentTree<int> st(n);

    for (int i = 0; i < n; i++) {
        st.at(i) = list[i];
    }

    st.build();

    cout << st.query(0, 4) << endl;
}
