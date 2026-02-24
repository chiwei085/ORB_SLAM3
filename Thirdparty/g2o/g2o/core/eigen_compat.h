// g2o Eigen compatibility helpers for newer Eigen versions.
#ifndef G2O_EIGEN_COMPAT_H
#define G2O_EIGEN_COMPAT_H

namespace g2o {

// Eigen::AlignedBit is deprecated in newer Eigen.
// Keep the historical bit value to preserve semantics without referencing the deprecated name.
inline constexpr unsigned kEigenAlignedBit = 0x80u;

}  // namespace g2o

#endif
