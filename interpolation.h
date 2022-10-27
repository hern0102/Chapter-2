#ifndef interpolation_h
#define interpolation_h


#endif /* interpolation_h */
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>

#define M 1000

using namespace std;

const double epsilon = 10 * numeric_limits<double>::epsilon();

void double_to_string(double num, string &str){
 stringstream ss;
 ss << num;
 ss >> str;
}

class Function{
public:
    virtual double operator () (const double &x) const = 0;
    virtual double diff (const double &x) const{
        return ((*this)(x+epsilon)-(*this)(x-epsilon)) / (2*epsilon);
    }
};

class Newton{
private:
    int n;
    double a[M][M];
    Function &f;
public:
    Newton(Function &f):f(f){}
    
    void insert_nodes(){
        cout<<"Please enter the amount of nodes :";
        cin>>n;
        for(int i=1;i<=n;i++){
            cout<<"x"<<i<<"=";
            cin>>a[i][0];
            cout<<"f(x"<<i<<")=";
            cin>>a[i][1];
        }
        cout<<endl;
    }
    void diff_table(){
        for(int j=1;j<n;j++){
               for(int i=1;i<=n-j;i++){
                   if(j==1){
                       a[i][j+1]=(a[i+1][j]-a[i][j])/(a[i+1][0]-a[i][0]);
                   }
                   else{
                       a[i][j+1]=(a[i+1][j]-a[i][j])/(a[i+j][0]-a[i][0]);
                   }
               }
           }

        cout<<"Divided Difference Table"<<endl;
        cout<<"x\tf(x)"<<endl;
        for(int i=1;i<=n;i++){
            cout<<a[i][0]<<"\t";
            for(int j=1;j<=n-i+1;j++){
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    void newtonpolynomial_explicit(){
        string s1[n],s2[n];
        stringstream str1[n],str2[n];
        cout<<"The newton polynomial is ";
            for(int j=0;j<n;j++){
                if(j==0){
                    cout<<a[1][1];
                    continue;
                }
                double_to_string(a[1][j+1], s2[j]);
                double_to_string(a[j][0], s1[j]);
                cout<<"+("<<s2[j]<<")";
                for(int k=j;k!=0;k--){
                    cout<<"*[x-("<<s1[k]<<")]";
                }
            }
        
        cout<<endl;
    }
    void calculate(){
        double x;
        cout<<"Please enter a variable value :"<<endl;
        cin>>x;
        double result=0,total=0;
        for(int j=0;j<n;j++){
            if(j==0){
                total=total+a[1][1];
                continue;
            }
            result=a[1][j+1];
            for(int k=j;k!=0;k--){
                result=result*(x-a[k][0]);
            }
            total=total+result;
        }
        cout<<"\nThe appoximate value is: "<<total<<endl;
    }
};

class Hermite{
private:
    double a[M][M];
    int n;
    double t[M];
    Function &f;
    //Function &f1;
    double fact(int n){
        double x=1;
        for(int i=1;i<=n;i++){
            x=x*i;
        }
        return x;
    }
public:
    Hermite(Function &f):f(f){}
    void insert_nodes(){
        cout<<"Please enter the amount of nodes :";
        cin>>n;
        for(int i=1;i<=n;i++){
            cout<<"x"<<i<<"=";
            cin>>a[i][0];
            cout<<"f(x"<<i<<")=";
            cin>>a[i][1];
            t[i]=a[i][1];
        }
        for(int i=1;i<=n;i++){
            if(a[i][0]==a[i+1][0]){
                a[i][2]=a[i+1][1];
                a[i+1][1]=a[i][1];
            }
        }
        cout<<endl;
    }
    
    
    void diff_table(){
        for(int j=1;j<n;j++){
               for(int i=1;i<=n-j;i++){
                   if(j==1){
                       if((a[i+1][0]-a[i][0])==0){
                           continue;
                       }
                       else{
                           a[i][j+1]=(a[i+1][j]-a[i][j])/(a[i+1][0]-a[i][0]);
                       }
                   }
                   else{
                       if((a[i+j][0]-a[i][0])==0){
                           continue;
                       }
                       else{
                           a[i][j+1]=(a[i+1][j]-a[i][j])/(a[i+j][0]-a[i][0]);
                       }
                   }
               }
           }

        cout<<"Divided Difference Table"<<endl;
        cout<<"x\tf(x)"<<endl;
        for(int i=1;i<=n;i++){
            cout<<a[i][0]<<"\t";
            for(int j=1;j<=n-i+1;j++){
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void newtonpolynomial_explicit(){
        string s1[n],s2[n];
        stringstream str1[n],str2[n];
        cout<<"The hermite polynomial is ";
            for(int j=0;j<n;j++){
                if(j==0){
                    cout<<a[1][1];
                    continue;
                }
                double_to_string(a[1][j+1], s2[j]);
                double_to_string(a[j][0], s1[j]);
                cout<<"+("<<s2[j]<<")";
                for(int k=j;k!=0;k--){
                    cout<<"*[x-("<<s1[k]<<")]";
                }
            }
        cout<<endl;
    }
    void calculate(){
        double x;
        cout<<"Please enter a variable value :"<<endl;
        cin>>x;
        double result=0,total=0;
        for(int j=0;j<n;j++){
            if(j==0){
                total=total+a[1][1];
                continue;
            }
            result=a[1][j+1];
            for(int k=j;k!=0;k--){
                result=result*(x-a[k][0]);
            }
            total=total+result;
        }
        cout<<"\nThe appoximate value is: "<<total<<endl;
    }
};
