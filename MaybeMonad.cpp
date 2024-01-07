#include <functional>
#include <stdio.h>
#include <iostream>
using namespace std;


// Haskell's Maybe rephrased in C++.
template<typename T>
class Optional {
  bool b;
  T val;
public:
  Optional() : b(false) {}
  Optional(T v) : val(v), b(true) {}
  bool isJust() { return b; }
  bool isNothing() { return !b; }
  T fromJust() { return val; }


  template<typename S>
  Optional<S> bind(function<Optional<S>(T)> f) {
     if (this->isNothing()) {
       return *this;
     } else {
       auto v = this->fromJust();
       return f(v);
     }
  }

  void print() {
      if (this->isNothing()) {
        cout << "\n Invalid result";
      } else {
        cout << "\n" << this->fromJust();
      }
  }

  // Assumes type T supports division.
  Optional<T> div(T x) {
     if (this->isNothing() || x == 0) {
       return *this;
     } else {
       auto v = this->fromJust();
       return Optional(v/x);
     }
  }
}; // Optional class

template<typename T>
Optional<T> ret(T x) {
    return Optional<T>(x);
}

template<typename T>
Optional<T> fail() {
    return Optional<T>();
}


// Fail safe integer division

Optional<int> divSafe(int x, int y) {
  if (y == 0) {
    return Optional<int>();
  } else {
    return Optional<int>(x / y);
  }
}

// (x/y)/z

Optional<int> example(int x, int y, int z) {y

  auto res = divSafe(x,y);
  if (res.isNothing()) {
    cout << "\n Invalid result";
  }
  auto res2 = divSafe(res.fromJust(),z);

  return res2;

}


// Optional is a monad.
// Use functional composition.

Optional<int> exampleM(int x, int y, int z) {

  return divSafe(x,y).bind<int>([z](int res) -> Optional<int> {
      return divSafe(res,z).bind<int>([](int res2) -> Optional<int> { return ret(res2);});});

}

// Method chaining instead of functional composition.
Optional<int> exampleM2(int x, int y, int z) {

  return Optional<int>(x).div(y).div(z);

}



int main() {
  int x,y,z;
  x = 12; y = 2; z = 3;
  example(x,y,z).print();

  exampleM(x,y,z).print();

  exampleM2(x,y,z).print();


}