#include <set>

template<typename T>
std::set<T> union_sets(std::set<T> a, std::set<T> b) {
    std::set<T> result = a;
    result.insert(b.begin(), b.end());
    return result;
}

template<typename T>
std::set<T> intersection_sets(std::set<T> a, std::set<T> b) {
    std::set<T> result;
    for (const T& x : a) {
        if (b.count(x)) {
            result.insert(x);
        }
    }
    return result;
}