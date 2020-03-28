include <iostream>
#include <cmath>
#include <cassert>
 
using namespace std;
 
class Complex {
 public :
  Complex(double re = 0, double im = 0) : re_(re), im_(im) {}
  double GetReal() {
    return re_;
  }
  double GetImaginary() {
    return im_;
  }
  double Abs() {
    return sqrt(re_ * re_ + im_ * im_);
  }
 
  void Swap() {
    swap(im_, re_);
  }
 
  Complex operator+(const Complex &other) {
    return Complex(re_ + other.re_, im_ + other.im_);
  };
 
  friend Complex operator+(const Complex &first, const double &second);
 
  friend Complex operator+(const double &first, const Complex &second);
 
  Complex operator-(const Complex &other) {
    return Complex(re_ - other.re_, im_ - other.im_);
  };
  friend Complex operator-(const Complex &first, const double &second);
 
  friend Complex operator-(const double &first, const Complex &second);
 
  bool operator==(const Complex &other) {
    return (im_ == other.im_ && re_ == other.re_);
  }
  bool operator!=(const Complex &other) {
    return !(*this == other);
  }
  Complex operator*(const Complex &other) {
    return Complex(re_ * other.re_ - im_ * other.im_, re_ * other.im_ + im_ * other.re_);
  };
 
 private:
  double re_;
  double im_;
};
 
Complex operator+(const double &first, const Complex &second) {
  return Complex(first + second.re_, second.im_);
}
Complex operator+(const Complex &first, const double &second) {
  return second + first;
}
 
Complex operator-(const double &first, const Complex &second) {
  return Complex(first - second.re_, 0 - second.im_);
}
Complex operator-(const Complex &first, const double &second) {
  return Complex(first.re_ - second, first.im_);
}
 
int main() {
  Complex number(3, 4);
  assert(number.GetReal() == 3);
  assert(number.GetImaginary() == 4);
  assert(number.Abs() == 5);
  number.Swap();
  assert(number.GetReal() == 4);
  assert(number.GetImaginary() == 3);
  Complex a(6, 7);
  Complex a1(6, 7);
  assert(a == a1);
  assert(a != number);
  Complex b(10, 10);
  assert(number + a == b);
  assert(b - a == number);
  Complex c(5, 3);
  assert(number + 1 == c);
  assert(1 + number == c);
  Complex d(5, -3);
  assert(9 - number == d);
  assert(c - 1 == number);
  Complex h(20, 80);
  assert(b * c == h);
  cout << "Everything is ok" << endl;
  return 0;
}
