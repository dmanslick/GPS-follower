#ifndef UTILS_H
#define UTILS_H

namespace Utils {
  bool isApproxEqual(double value, double tolerance, double desired) {
    return value >= desired - tolerance && value <= desired + tolerance;
  }
}

#endif