#ifndef included_CALPHADEqConcSolverBinary
#define included_CALPHADEqConcSolverBinary

#include "NewtonSolver.h"

#include <cmath>

namespace Thermo4PFM
{

class CALPHADEqConcSolverBinary
    : public NewtonSolver<2, CALPHADEqConcSolverBinary>
{
public:
    CALPHADEqConcSolverBinary() : NewtonSolver(){};

    ~CALPHADEqConcSolverBinary(){};

    int ComputeConcentration(double* const conc);

    void setup(const double RTinv, const double* const Lmix_L,
        const double* const Lmix_A, const double* const fA,
        const double* const fB);

    void RHS(const double* const x, double* const fvec);

    void Jacobian(const double* const x, double** const fjac);

private:
    double RTinv_;
    double RT_;
    double c0_;
    double hphi_;

    // energies of 2 species (A and B), in two phase each
    double fA_[2];
    double fB_[2];

    // 4 L coefficients for 2 possible phases (L, A)
    double Lmix_L_[4];
    double Lmix_A_[4];
};
}
#endif
