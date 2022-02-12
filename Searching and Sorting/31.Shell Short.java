class Solution {
    public void swap(int[] nums1,int a,int b){
        int t=nums1[a];
        nums1[a]=nums1[b];
        nums1[b]=t;
    }
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
          for(int gap=(m+n+1)/2;gap>=1;gap/=2 ){
            for(int i=0,j=gap;j<m+n;i++,j++){
                    if(nums1[i]>nums1[j]){
                    swap(nums1,i,j);
                }
            }
        }
        for(int i=0,j=1;j<m+n;i++,j++){
            
                if(nums1[i]>nums1[j]){
                    swap(nums1,i,j);
                }
            
        }
    }
}