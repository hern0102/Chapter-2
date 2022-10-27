#include <iostream>
#include <sstream>
#include <cmath>
#include "interpolation.h"
#define M 1000
using namespace std;

class Func1 : public Function{
public:
    double operator () (const double &x) const{
        return 1/(1+x*x);
    }
} func1;

int main(){
    Hermite H10(func1);
    H10.insert_nodes();
    H10.diff_table();
    H10.newtonpolynomial_explicit();
    H10.calculate();
}
 

