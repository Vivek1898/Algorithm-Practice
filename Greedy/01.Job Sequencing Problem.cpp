struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
  static bool comp (Job a, Job b){
         
     return a.profit>b.profit;
  }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort (arr, arr+n,comp);
       vector<bool> slots(n,false); 
      
      int maxprofit=0; int jobAllocated=0;
      for (int i=0; i< n; i++){
      
     for (int j= arr[i].dead-1; j>=0; j--){
                 
                 if(slots[j]==false){
                 slots[j]= true;
                 maxprofit+= arr[i].profit;
                 jobAllocated++;
                 break;
                 }
            }
        }
         
     return {jobAllocated,maxprofit};
    }
    } ;