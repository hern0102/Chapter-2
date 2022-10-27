#include <iostream>
#include <sstream>
#include <cmath>
#include "interpolation.h"
#define M 1000

using namespace std;
const double pi=acos(-1);
class Func2 : public Function{
public:
    double operator () (const double &x) const{
        return 1/(1+25*x*x);
    }
} func2;

void calculatenodes_chebyshev(Function &f,int n){
    double x[n+1],y[n+1];
    cout<<"The amount of nodes are "<<n<<endl;
    for(int i=1;i<=n;i++){
        x[i]=cos(((2*i-1)*pi)/(2*n));
        y[i]=func2(x[i]);
        cout<<"x"<<i<<"="<<x[i]<<endl;
        cout<<"y"<<i<<"="<<y[i]<<endl;
    }
    cout<<endl;
}
int main() {
    Newton N_(func2);
    //calculatenodes_chebyshev(func2, 5);
    //calculatenodes_chebyshev(func2, 10);
    //calculatenodes_chebyshev(func2, 15);
    calculatenodes_chebyshev(func2, 20);
    N_.insert_nodes();
    N_.diff_table();
    N_.newtonpolynomial_explicit();
    //if there is a need for estimation of a value,feel free to use 'calculate' function
    //H.calculate();
}


