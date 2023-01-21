#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

double a=2.0;

double u(double x, double y){
    return 2.0;
}
double ug(double y){
    return u(-a,y) ;
}

double ud(double y){
     return u(a,y) ;
}

double derUd(double x){
    return 2.0;
}
double derUg(double x){
    return 2.0;
}

double fsecond_membre(double ug, double ud, double derivUg, double derivUd, double x, double y){
    return 2.0;
}

int main(){
    cout<<1<<endl;
}

















int main(){
    cout<<1<<endl;
}
