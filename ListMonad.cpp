#include <vector>
#include <functional>
#include <iostream>
#include <ostream>
template <typename T>
class MonadicList
{
    std::vector<T> list;

public:
    MonadicList() {}
    MonadicList(T v) { list.push_back(v); }
    MonadicList(std::vector<T> pList) : list(pList) {}
    typename std::vector<T>::iterator begin() { return list.begin(); }
    typename std::vector<T>::iterator end() { return list.end(); }
    typename std::vector<T>::iterator begin() const { return list.begin(); }
    typename std::vector<T>::iterator end() const { return list.end(); }

    void push_back(const T &element)
    {
        list.push_back(element);
    }

    template <typename S>
    MonadicList<S> mBind(std::function<MonadicList<S>(T)> f)
    {
        MonadicList<S> result;
        for (const T &item : *this)
        {
            MonadicList<S> temp = f(item);
            for (const S &val : temp)
            {
                result.push_back(val);
            }
        }
        return result;
    }

    void print() const {
        for (const auto &element : list) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

MonadicList<int> squareAndCube(int n) {
    MonadicList<int> result;
    result.push_back(n);
    result.push_back(n*n);
    result.push_back(n*n*n);
    return result;
}

std::function<MonadicList<int>(int)> squareAndCubeFunc = squareAndCube;

int main() {
    MonadicList<int> myList(2);
    MonadicList<int> resList = myList.mBind(squareAndCubeFunc).mBind(squareAndCubeFunc);
    // Add code to use resList as needed
}
