class Solution {
public:

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
int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{ 
   int n=intervals.size();
	struct meeting meet[n];
	int c = 1;
	// Creating pairs of meeting(start,end) and position
	for (int i = 0; i < n; i++) 
	{ 
		meet[i].start = intervals[i][0]; 
		meet[i].end = intervals[i][1]; 
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
		if (meet[i].start >= prev_end) 
		{ 
			m.push_back(meet[i].pos); 
			prev_end = meet[i].end; 
			c++;
		} 
	} 
	return n-c;
}

    
};


----------------------------------------------------------------



class Solution {
public:
   int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b){
                return a[1] < b[1];
            });
        
        int discarded = 0;
        int last_end = INT_MIN;
        
        for(vector<int> interval : intervals){
            if(last_end > interval[0])
                ++discarded;
            else
                last_end = interval[1];
        }
        
        return discarded;
    }

    
};