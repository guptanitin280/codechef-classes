//link:- https://binarysearch.com/problems/Insertion-Index-in-Sorted-List
bool func(int i,vector<int>&nums,int target){
    return nums[i]<=target;
}
int solve(vector<int>& nums, int target) {
    int l=-1; // always returns 1
    int r=nums.size(); // always returns 0
    // 111110000000000
    while(l+1<r){
        int mid=(l+r)/2;
        if(func(mid,nums,target)){
            l=mid;
        }else{
            r=mid;
        }
    }
    return l+1;

}