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

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
  static bool less(Interval a, Interval b) {
        return a.start <= b.start;
    }
    
    bool canAttendMeetings(vector<Interval> &intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), less);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i-1].end > intervals[i].start) {
                return false;
            }
        }
        return true;
    }
};