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

void calculatenodes(Function &f,int n){
    double x[n+1],y[n+1];
    cout<<"The amount of nodes are "<<n+1<<endl;
    for(int i=0;i<=n;i++){
        x[i]=-5+10.0*i/n;
        y[i]=func1(x[i]);
        cout<<"x"<<i+1<<"="<<x[i]<<endl;
        cout<<"y"<<i+1<<"="<<y[i]<<endl;
    }
    cout<<endl;
}
int main() {
    //calculatenodes(func1,2);
    //calculatenodes(func1,4);
    //calculatenodes(func1,6);
    calculatenodes(func1,8);
    Newton N(func1);
    N.insert_nodes();
    N.diff_table();
    N.newtonpolynomial_explicit();
    //if there is a need for estimation of a value,feel free to use "calculate" function
    //N.calculate();
}

