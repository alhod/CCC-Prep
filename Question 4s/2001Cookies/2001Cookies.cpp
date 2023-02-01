#include<bits/stdc++.h>
#define ll long long
using namespace std;


double dist(double x, double y, double x2, double y2){
    return sqrt(pow(x-x2, 2)+pow(y-y2, 2));
}

double circumcenter(double x, double y, double x2, double y2, double x3, double y3){
    double m=abs(x-x2)/abs(y-y2);
    double m2=abs(x2-x3)/abs(y2-y3);
    double m3=abs(x3-x)/abs(y3-y);
    double b=y-(m*x);
    double b2=y2-(m2*x2);
    double b3=y3-(m3*x3);
    double negRecm=-1*(1/m);
    double negRecm2=-1*(1/m2);
    double halfx=abs(x-x2)/2;
    double halfy=abs(y-y2)/2;
    double bisB=halfy-negRecm*halfx;
    double halfx2=abs(x2-x3)/2;
    double halfy2=abs(y2-y3)/2;
    double bisB2=halfy2-negRecm2*halfx2;
    double intX=abs(bisB2-bisB)/abs(negRecm2-negRecm);
    double intY=negRecm*intX+bisB;

    return 2*dist(intX, intY, x, y);
}


int solution(){
    double n;
    cin>>n;
    vector<pair<double, double>>v(n);
    for(double i=0; i<n; i++){
        double x, y;
        cin>>x>>y;
        v[i]=pair<double, double>(x, y);
    }

    double best=0;

    for(double i=0; i<n; i++){
        for(double j=i+1; j<n; j++){
            for(double k=j+1; j<n; j++){
                best=max(best, min(dist(v[i].first, v[i].second, v[j].first, v[j].second), circumcenter(v[i].first, v[i].second, v[j].first, v[j].second, v[k].first, v[k].second)));
            }
        }
    }

    printf("%.2f", best);

    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}