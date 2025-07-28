// Leetcode 50 : pow(x,n)

class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        double answer = 1;

        if(power < 0){
            power = -(power);
        }
        while(power > 0){
            if(power%2 != 0){
                answer = answer * x;
                power--;
            }
            else{
                x = x*x;
                power = power / 2;
            }
        }
        if(n < 0){
            answer = 1/answer;
        }
        return answer;
    }
};
