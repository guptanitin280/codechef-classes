// https://binarysearch.com/problems/K-Distinct-Groups
//11111100000000
bool func(int num_of_group,vector<int>&counts,int k){
    int sum=0;
    for(auto &c:counts){
        sum+=min(c,num_of_group);
    }
    return (sum/k)>=num_of_group;
}
int solve(vector<int>& counts, int k) {
    int l=0;
    int r=0;
    for(auto &c:counts){
        r+=c;
    }
    r+=1;
    while(l+1<r){
        int mid=(l+r)/2;
        if(func(mid,counts,k)){
            l=mid;
        }else{
            r=mid;
        }
    }
    return l;
}