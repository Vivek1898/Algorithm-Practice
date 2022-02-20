

struct meeting { 
	int start; 
	int end; 
	int pos; 
}; 

// Sorting meetings based on finish time
static bool endSort(struct meeting m1, meeting m2) 
{ 
	return (m1.end < m2.end); 
} 

// Function for finding maximum meeting in one room 
int maxMeetings(int s[], int f[], int n) 
{ 
	struct meeting meet[n];
	int c = 1;
	// Creating pairs of meeting(start,end) and position
	for (int i = 0; i < n; i++) 
	{ 
		meet[i].start = s[i]; 
		meet[i].end = f[i]; 
		meet[i].pos = i + 1; 
	} 

	// Sorting of meetings in ascending order according to their finish time 
	sort(meet, meet + n, endSort); 

	// Vector for storing selected meeting. 
	vector<int> m; 

	// First meeting is always selected 
	m.push_back(meet[0].pos); 
 
	int prev_end = meet[0].end; 

	// Checking if meeting can take place or not 
	for (int i = 1; i < n; i++) { 
		if (meet[i].start > prev_end) 
		{ 
			m.push_back(meet[i].pos); 
			prev_end = meet[i].end; 
			c++;
		} 
	} 
	return c;
}

--------------------------------------------------














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