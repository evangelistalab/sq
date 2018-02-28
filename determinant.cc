#include "determinant.h"

determinant::determinant(int nso) : occupation_(nso) {}

bool determinant::operator<(const determinant &other) const {
  return occupation_ < other.occupation_;
}

std::string
determinant::str() const { // const here means I am not changing the object
  std::string s;
  s += '|';
  for (auto &n : occupation_) {
    if (n == 0) {
      s += '0';
    }
    if (n == 1) {
      s += '1';
    }
  }

  //  Matrix sum;
  //  vector<Matrix> vm;
  //  for (Matrix mat : vm) { // bad, I am copying the matrix
  //  for (Matrix &mat : vm) { // ok, I am just getting a reference to the
  //  matrix
  //    sum += mat;
  //  }

  s += '>';
  return s;
}

double determinant::cre(int p) {
  if (occupation_[p] == 1) {
    return 0.0;
  }
  occupation_[p] = 1;
  return slater_sign(p);
}

double determinant::ann(int p) {
  if (occupation_[p] == 0) {
    return 0.0;
  }
  occupation_[p] = 0;
  return slater_sign(p);
}

double determinant::slater_sign(int p) const {
  double sign = 1.0;
  for (int n = 0; n < p; n++) {
    if (occupation_[n] == 1)
      sign *= -1.0;
  }
  return sign;
}
