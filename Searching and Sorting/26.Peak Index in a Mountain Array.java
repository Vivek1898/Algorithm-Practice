class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int low=0,high=arr.length-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int lval=(mid-1>0)?arr[mid-1]:Integer.MIN_VALUE;
            int rval=(mid+1<arr.length)?arr[mid+1]:Integer.MIN_VALUE;
            
            if(arr[mid]>lval && arr[mid]>rval){
                return mid;
                
            }else if(lval>arr[mid]){
                high=mid-1;
            }else{
              low=mid+1;  
            }
            
        }
        return -1;
    }
}