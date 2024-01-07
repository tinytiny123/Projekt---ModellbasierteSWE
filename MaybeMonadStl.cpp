#include <optional>
#include <functional>
#include <iostream>

//Extending std::optional isnt really possible unless a wrapper class is used.

// divSafe function
std::optional<int> divSafe(int n, int m) {
    if (m == 0) {
        return std::nullopt;
    } else {
        return n / m;
    }
}

std::function<std::optional<int>(int, int)> divSafeFunc = divSafe;

// bind function for std::optional
template <typename T, typename Func>
auto bind(const std::optional<T>& opt, Func f) -> decltype(f(opt.value())) {
    if (opt) {
        return f(opt.value());
    } else {
        return std::nullopt;
    }
}

template <typename T, typename S>
std::optional<S> mBind(const std::optional<T>& opt, std::function<std::optional<S>(T)> f) {
    if (opt) {
        return f(opt.value());
    } else {
        return std::nullopt;
    }
}

// Using bind for functional composition
std::optional<int> exampleM(int x, int y, int z) {
    return mBind<int,int>(divSafeFunc(x, y), [z](int a) { return divSafeFunc(a, z); });
}


int main() {
    // if (result) {
    //     std::cout << "Result: " << *result << std::endl;
    // } else {
    //     std::cout << "No result (division by zero encountered)" << std::endl;
    // }
    // return 0;
}
