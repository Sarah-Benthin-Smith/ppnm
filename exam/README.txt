The Gauss-Newton algorithm

The method is used to solve non-linear least squares problems. It is an extension to Newtons method for finding the minima of a non-linear function.
I will be using alterations of code created in homeworks OLS and Minimization.
This includes the minimizers.cc and minimizers.h in Minimization, where the Hessian algorithm has been removed and the Gauss-Newton has been added instead.
It also includes the qr decomposition used in various handins, here no alterations has been made - it is the same for the matrix class and the lsfit.

Log-linear fit (OLS):
a = 142.404 +/- 3.81977
lambda = 0.170624+/-0.00341594
Half-life = 4.06242+/-0.0813307 days

Direct nonlinear fit (Gauss-Newton, 5 iterations):
a = 142.298 +/- 3.84052
lambda = 0.170662 +/- 0.00339129
Half-life = 4.06153 +/- 0.0807083 days

Modern Value = 3.6316 days
Difference from modern value: 5.32695 sigma

The fit created with Gauss Newton and the fit created with OLS has both been plotted together to notice similarities - they are pretty much identical.

 I have done what the question asked, so I would give myself 10/10.