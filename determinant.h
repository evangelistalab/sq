#ifndef DETERMINANT_H
#define DETERMINANT_H

#include <string>
#include <vector>

/// The type used to represent determinants
using det_t = std::vector<int>;

/// A class to represent a determinant
class determinant {

public:
  // ==> Constructor <==

  /// Create a determinant with nso spin orbitals
  determinant(int nso);

  // ==> Interface <==

  bool operator<(const determinant& other) const; // a < b = a.operator<(b);

  /// Get the occupation vector
  const det_t &occupation() const { return occupation_; }

  /// Return a string representation of the determinant
  std::string str() const;

  /// Create an electron in spin orbital p
  double cre(int p);

  /// Annihilate an electron in spin orbital p
  double ann(int p);

  /// Compute the slater sign
  double slater_sign(int p) const;

private:
  det_t occupation_;
};

#endif // DETERMINANT_H
