#include "maths.h"
#include "math.h"
#define EQ_EPS 1e-90

#define	is_zero(x)	((x) > -EQ_EPS && (x) < EQ_EPS)

int solve_quadric(double &t1, double &t2, double params[])
{
    double a = params[0];
    double b = params[1];
    double c = params[2];
    double a2 = 2 * a;
    double b_a2 = -b / a2;;
    double disc = b * b - 4 * a * c;
    if (is_zero(disc))
    {
        t1 = t2 = b_a2;
        return 1;
    }
    else if (disc > 0.0)
    {
        double sdisc_a2 = sqrt(disc) / a2;
        t1 = b_a2 - sdisc_a2;
        t2 = b_a2 + sdisc_a2;
        return 2;
    }
    else
        return 0;
}

inline double min(double x0, double x1) {
    return ((x0 < x1) ? x0 : x1);
}
