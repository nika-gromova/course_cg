#ifndef MATHS_H
#define MATHS_H

#define EQ_EPS 1e-90
#define	is_zero(x)	(((x) > -EQ_EPS && (x) < EQ_EPS))

int solve_quadric(double &t1, double &t2, double params[3]);
int SolveQuartic(double c[5], double s[4]);


double min(double x0, double y0);

double check_value(double value);

#endif // MATHS_H
