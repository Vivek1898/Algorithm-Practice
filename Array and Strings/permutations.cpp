//Iterative
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        queue<vector<int>>permut;
        permut.push(vector<int>());
        
        for(auto curr:nums){
            int n=permut.size();
            for(int i=0;i<n;i++){
                vector<int>oldPermut=permut.front();
                permut.pop();
                for(int j=0;j<=oldPermut.size();j++){
                      vector<int>newPermut(oldPermut);
                      newPermut.insert(newPermut.begin()+j,curr);
                    
                    if(newPermut.size()==nums.size()){
                        res.push_back(newPermut);
                    }else{
                         permut.push(newPermut);
                    }
                }
            }
        }
        return res;
        
    }
};

//Recursive


class Solution {
public:
      void helper(vector<int>& nums,int idx,vector<int>& currPerm,vector<vector<int>>& res){
         if(idx == nums.size()){
            res.push_back(currPerm);
            return ;
        }else{
             for(int i=0;i<=currPerm.size();i++)
             {
                vector<int> newPerm(currPerm);
                newPerm.insert(newPerm.begin()+i,nums[idx]); 
                 helper(nums,idx+1,newPerm,res);
             }
         }
    }  
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
         vector<int> currPerm;
        helper(nums,0,currPerm,res);
        return res;   
    }
    
  
};


//STL

class Solution {
public:
     
    
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return res;   
    }
    
  
};