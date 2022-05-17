class Solution {
public:
      struct Points { 
	int start; 
	int end; 
	 
}; 

// Sorting Pointss based on finish time
static bool endSort(struct Points m1, Points m2) 
{ 
	return (m1.end < m2.end); 
} 
    
    int findMinArrowShots(vector<vector<int>>& intervals) {
          int n=intervals.size();
	struct Points meet[n];
	int c = 1;
	for (int i = 0; i < n; i++) 
	{ 
		meet[i].start = intervals[i][0]; 
		meet[i].end = intervals[i][1]; 
		
	} 

	sort(meet, meet + n, endSort); 

	int prev_end = meet[0].end; 
	for (int i = 1; i < n; i++) { 
		if (meet[i].start > prev_end) 
		{ 
			prev_end = meet[i].end; 
			c++;
		} 
	} 
	return c;
    }
};