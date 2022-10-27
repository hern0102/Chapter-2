#include <iostream>
#include <sstream>
#include <cmath>
#include "interpolation.h"
#define M 1000

using namespace std;
const double pi=acos(-1);
class Func4 : public Function{
public:
    double operator () (const double &x) const{
        return x;
    }
} func4;
int main(){
    Newton N2(func4);//the function is randomly chosen
    N2.insert_nodes();
    N2.diff_table();
    N2.newtonpolynomial_explicit();
    N2.calculate();
    
}
