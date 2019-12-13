#include <iostream>
#include <vector>

using std::vector;

class Treap {
private:
    int x;
    int y;
    Treap *left_child;
    Treap *right_child;
public:
    Treap(int key, int priority) : x(key), y(priority), left_child(nullptr), right_child(nullptr) {}

    void Merge(Treap *L, Treap *R) {
        if (L == nullptr || R == nullptr) {
            if (L == nullptr) {
                *this = *R;
            } else {
                *this = *L;
            }
        } else {
            if (L->y > R->y) {
                Merge(*(L->right_child), L->right_child, R);
                T = *L;
            } else {
                Merge(*(R->left_child), L, R->left_child);
                T = *R;
            }
        }
    }

    static void Split(Treap *T, int x0, Treap *L, Treap *R) {
        if (T == nullptr) {
            L = R = nullptr;
        } else {
            if (x0 > T->x) {
                Split(T->right_child, x0, T->right_child, R);
                L = T;
            } else {
                Split(T->left_child, x0, L, T->left_child);
                R = T;
            }
        }
    }

    void Insert() {

    }
};
