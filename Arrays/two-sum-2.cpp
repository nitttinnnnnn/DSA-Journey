// Two-Sum function that returns yes if true and returns no if not valid
// Time Complexity : O(n) + O(n*logn)

String twoSum(vector<int> nums , int target){
    int n = nums.size();
    int l = 0;
    int r = n-1;
    sort(nums.begin(),nums.end());
    while(l<r){
        int sum = nums[l] + nums[r];
        if(sum == target){
            return "YES";
        }
        else if(sum > target){
            r--;
        }
        else{
            l++;
        }
    }
    return "NO";
}
