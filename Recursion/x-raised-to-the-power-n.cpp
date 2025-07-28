// Leetcode 50 : pow(x,n)

class Solution {
public:
    double myPow(double x, int n) {
        double answer = 1;
        for(int i=0; i<n; i++){
            answer *= x;
        }
        if(n < 0){
            return (double) 1.00/answer;
        }
        else{
            return answer;
        }   
    }
};
