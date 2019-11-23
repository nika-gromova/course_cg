#ifndef MATHS_H
#define MATHS_H

#define EQ_EPS 1e-90
#define	is_zero(x)	(((x) > -EQ_EPS && (x) < EQ_EPS))

int solve_quadric(double &t1, double &t2, double params[3]);

double min(double x0, double y0);

#endif // MATHS_H
