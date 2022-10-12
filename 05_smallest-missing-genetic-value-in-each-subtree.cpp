 https://leetcode.com/contest/weekly-contest-258/problems/smallest-missing-genetic-value-in-each-subtree/

class Solution {
public:
    void dfs(int i,vector<int>child[], vector<int>& nums, vector<int>& seen){
        if(seen[nums[i]]==0){
            for(auto &u:child[i])
                dfs(u,child,nums,seen);
            seen[nums[i]]=1;
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& par, vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1),seen(100002,0);
        vector<int>child[n];
        for(int i=1;i<n;i++){
            child[par[i]].push_back(i);
        }
        int ind1=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ind1=i;
                break;
            }
        }
        if(ind1== -1)return res;
        int i=ind1;
        int low=1;
        while(i>=0){
            dfs(i,child,nums,seen);
            while(seen[low])low++;
            res[i]=low;
            i=par[i];
        }
        return res;
        
    }
};