#include <iostream>
#include <map>

#include "determinant.h"
#include "sqoperator.h"

using namespace std;

int main(int argc, char *argv[]) {
  determinant d(4); // define?
  const det_t &occ = d.occupation();

  //  cout << "size of double " << sizeof(double) << endl;
  //  cout << "size of int " << sizeof(int) << endl;
  //  cout << "size of size_t " << sizeof(size_t) << endl;
  //  cout << "size of short " << sizeof(short) << endl;
  //  cout << "size of mycontainer " << sizeof(mycontainer) << endl;

  double sign = 1.0;
  sign *= d.cre(2);
  sign *= d.cre(3);

  //  std::vector<determinant> wfn_det;
  //  std::vector<double> wfn_coeff;

  //  std::vector<std::pair<double, determinant>> wfn1;

  //  std::vector<std::pair<determinant, double>> wfn2;

  //  wfn += 0.5 * d;
  //  add_det(0.5,d,wfn); // d = |1010>
  std::map<determinant, double> wfn;
  wfn[d] += 0.5;
  wfn[d] += 0.7;

  determinant d2(4);
  d2.cre(0);
  d2.cre(1);




  for (const std::pair<determinant, double> &det_c : wfn) {
    double c = det_c.second;
    const determinant &det = det_c.first;
    cout << c << " " << det.str();
  }

  // 1 - find where is d in wfn?
  // 2 - set/add coefficient

  //  sqoperator op; // define?

  //  d.apply(op); // ???
  //  op.apply_to(d);
  //  apply(std::vector<op>,d);

  //  op d -> many determinants; //
  return 0;
}
