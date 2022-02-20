 static bool compare( pair<int,int> &a, pair<int,int> &b){

        if(a.second<b.second)return true;
        if(a.second > b.second) return false;
        
       return a.first < b.first;

}

int maxMeetings(int start[], int end[], int n)
   {
       // Your code here
       int c=1;
       vector<pair<int,int>> Intervals;
       for(int i=0;i<n;i++)
       Intervals.push_back({start[i],end[i]});
       sort(Intervals.begin(),Intervals.end(),compare);
       int j=0;
      for(int i=1;i<n;i++)
         {
          if(Intervals[i].first>Intervals[j].second)
          {
          j=i;
          c++;
          }
      }
      return c;
   }

//2nd


int maxMeetings(int start[], int end[], int n)
    {
       // Your code here
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++){
           v.push_back({end[i],start[i]});
       }
       sort(v.begin(),v.end());
       int ans = 0;
       int en = 0;
       for(int i=0;i<n;i++){
           if(v[i].second > en){
               ans++;
               en = v[i].first;
           }
       }
       
       return ans;
    }