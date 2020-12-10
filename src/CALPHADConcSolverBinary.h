#ifndef included_CALPHADConcSolverBinary
#define included_CALPHADConcSolverBinary

#include "DampedNewtonSolver.h"

namespace Thermo4PFM
{

class CALPHADConcSolverBinary : public DampedNewtonSolver
{
public:
    CALPHADConcSolverBinary(const bool with_third_phase = false);

    virtual ~CALPHADConcSolverBinary(){};

    int ComputeConcentration(double* const conc, const double c0,
        const double hphi, const double heta, const double RTinv,
        const double* const Lmix_L_, const double* const Lmix_A_,
        const double* const Lmix_B_, const double* const fA,
        const double* const fB);

protected:
    double fA_[3];
    double fB_[3];

    // 4 L coefficients for 3 possible phases (L, A and B)
    double Lmix_L_[4];
    double Lmix_A_[4];
    double Lmix_B_[4];
    double RTinv_;

private:
    void computeXi(const double* const c, double xi[3]) const;

    void computeDxiDc(const double* const c, double dxidc[3]) const;

    // virtual functions inherited from DampedNewtonSolver
    void RHS(const double* const x, double* const fvec);

    void Jacobian(const double* const x, double** const fjac);

    double c0_;
    double hphi_;
    double heta_;
    bool with_third_phase_;
};
}
#endif
