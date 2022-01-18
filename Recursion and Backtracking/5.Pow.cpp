class Solution {
public:
    double helper(double x, long n){
        //For Positive cases
        if(n==0) return 1.0;
        double temp =helper(x,n/2);
        //Even Double
        if(n%2==0){
            return temp*temp;
        }else{
            return temp*temp*x;
        }
    }
    double myPow(double x, int n) {
        if(n<0){
            //return -ve POWER  1/2power 
            double temp2=helper(x, -1l * n);
            return 1/temp2;
        }
          return helper(x,n);
        
        
    }
};