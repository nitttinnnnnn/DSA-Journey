class Solution {
public:
    bool check(vector<int>& nums) {
        int len = 0;
        int n = nums.size();
        for(int i=2; i<2*n; i++){
            if(nums[(i-1)%n] <= nums[i%n]){
                len++;
            }
            else{
                len = 0;
            }
            if(len == n-1){
                return true;
            }
        }
        return n==1;  
    }
};



