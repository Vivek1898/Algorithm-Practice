/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class compare {
public:
    bool operator()(const Interval &a, const Interval &b) {
        if (a.start != b.start) {
            return a.start < b.start;
        } else {
            return a.end < b.end;
        }
    }
};

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        priority_queue<int, vector<int>, std::greater<int>> pq;
        sort(intervals.begin(), intervals.end(), compare());
        
        pq.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};
