#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>
using namespace std;
class point
{
    private:
        double xval;
        double yval;
    public:
        point(double x = 0.0, double y = 0.0){xval = x ; yval = y ;}
        double getx(){return xval;}
        double gety(){return yval;}
};

inline double point_dist(point &a, point &b)
{
    return pow((pow((a.getx() - b.getx()), 2.0) + pow(a.gety() - b.gety(), 2.0)), 0.5);
}
ostream &operator<<(ostream &out, point &a)
{
    cout << '(' << a.getx() << ',' << a.gety() << ')' << '\t';
    return out;
}
int main(void)
{   
    srand(clock());
    point a(3.5, 2.7), b(6.5, 4.1);
    cout << point_dist(a, b) <<endl;
    cout << a << b;
    int plus = 0;
    //Randomize 8 points.
    point set_a[8];
    for(int i = 0; i < 8; i++, plus++){
        auto r1 = static_cast<double> (rand()) / static_cast<double> (RAND_MAX / 30); 
        auto r2 = static_cast<double> (rand()) / static_cast<double> (RAND_MAX/ 30); 
        point r(r1, r2);
        set_a[i] = r;
        cout << set_a[i];
    }
    return 0;
}