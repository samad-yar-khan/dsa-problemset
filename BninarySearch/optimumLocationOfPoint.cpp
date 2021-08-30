#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-6


//https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/

class Line{

    public:
    //AX + BY + C=0
    double A ;
    double B ;
    double C ;

    Line(double A,double B,double C){
        this->A = A;
        this->B = B;
        this->C = C;
    }

    void printLine(){
        cout<<A<<"x + "<<B<<"y + "<<C<<" = 0\n";
    }

    double getX(double y){
        double ans = (-1*(C) - 1*(B*y))/A;
        return ans;
    }

    double getY(double x){
        double ans = (-1*(C) - 1*(A*x))/B;
        return ans;
    }

};

//calcuates distance between two poits
double distance(double a , double b , double x , double y){
    double ans = sqrt(((a-x)*(a-x)) + ((b-y)*(b-y)));
    return ans;
}

//calculates the sum of  ditances of all points from a given point
double distanceSum(vector<pair<double , double>> points , double x , double y){

    double sum = 0;
    for(int i = 0 ; i<points.size() ; i++){
        sum += (distance(points[i].first , points[i].second , x , y));
    }
    return sum;

}


double optimalDistance(Line L , vector<pair<double, double>> points){

    sort(points.begin() , points.end());

    //this l is the lower bond for ternar search
    double l = -1e6;
    //uppper bound for ternary search
    double r = 1e6;

    //we can caclaet the min and max value of x of the foot of penpendicalrs drawn from ppoibts to the line

    for(int i = 0 ; i < points.size() ; i++){
        double p = points[i].first;
        double q = points[i].second;

        //formula to find x coordinate of the foor of perpendiclar drawn from a point to line
        double h = (p/L.A) - ((L.A*p + L.B*q + L.C) / sqrt(pow(L.A,2) + pow(L.B,2)));
        if(h < l ){
            l = h ;
        }
        if(h > r){
            r= h;
        }
    }

    double ans = 0;

    //TERNARY SEARCH
    while(r-l > EPS){

        // cout<<l<<","<<r<<'\n';

        //first to see the 1/3 poit from l to r
        double m1X = l+((r-l)/3);
        //the 2/3 point going from l to r
        double m2X = r-((r-l)/3);

        //finding y coordinatees of points
        double m1Y = L.getY(m1X);
        double m2Y = L.getY(m2X);

        double S1 = distanceSum(points , m1X , m1Y);
        double S2 = distanceSum(points , m2X , m2Y);

        ans = min(S1,S2);

        if(S1==S2){
            l = m1X;
            r = m2Y;
        }else if(S1>S2){
            l = m1X;
        }else{
            r = m2X;
        }

    }

    return ans;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setprecision(4);    

    int T = 0;
    cin>>T;
    while(T--){

        int a=0;
        int b=0;
        int c=0;
        //line is of form 
        //ax + by + c=0
        cin>>a>>b>>c;

        Line L(a,b,c);

        int N = 0 ;
        //enter the number of points
        cin>>N;

        //enter points
        vector<pair<double,double>> points ;
        for(int i = 0 ;i < N ; i++){
            double x = 0;
            double y = 0;
            cin>>x>>y;
            points.push_back(make_pair(x,y)); 
        }

        cout<<optimalDistance(L , points)<<"\n";

    
    }


    
}





