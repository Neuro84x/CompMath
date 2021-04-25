#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>


using namespace std;


double func(double x)
{
    return (sin(M_PI * x / 180) - 1 / x);
}

double MetodPItter(double x0, double x1, double eps)
{
    double left = x0, right = x1, x, fl, fr, f;
    int iter = 0;
    cout << "x0= " << x0 << " x1= " << x1 << " ";
    do {
        x = (left + right) / 2;
        f = func(x);
        if (f > 0) right = x;
        else left = x;
        iter++;
        cout << "\nX = " << x << endl;
    } while (fabs(f) > eps && iter < 20000);
    cout << iter << " iterations" << endl;
    return x;
}

double MetodHorde(double x0, double x1, double eps)
{
    double x = x1, f0, f;
    int iter = 0;
    cout << "x0= " << x0 << " x1= " << x1 << " ";
    do {
        f = func(x);
        f0 = sin(M_PI * x0 / 180) - 1 / x0;
        x = x - f / (f - f0) * (x - x0);
        iter++;
        cout << "\nX = " << x << endl;
    } while (fabs(f) > eps && iter < 20000);
    cout << iter << " iterations" << endl;
    return x;
}

double MetodNute(double x, double eps)
{
    double f, df; int iter = 0;
    cout << "x0= " << x << " ";
    do {
        f = func(x);
        df = M_PI / 180 * cos(M_PI * x / 180) + 1 / (x * x);
        x = x - f / df;
        iter++;
        cout << "\nX = " << x << endl;
    } while (fabs(f) > eps && iter < 20000);
    cout << iter << " iterations" << endl;
    return x;
}


int main()
{
    //cout << "X = " << MetodPItter(1.0, 10.0, 0.000001);

    //cout << "X = " << MetodHorde(1.0, 10.0, 0.000001);

    //cout << "X = " << MetodNute(1, 0.000001);


    cin.get(); 
    return 0;
}