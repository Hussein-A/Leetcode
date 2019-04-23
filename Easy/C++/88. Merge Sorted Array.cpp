//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//Stats: 
//Speed: 4ms; Memory: 790.5kb

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size1 = nums1.size();
        int size2 =nums2.size();
        int j =0;
        int i = size1-1;
        while (j<size2){
            nums1[i--]=nums2[j++];
        }
        sort(nums1.begin(),nums1.end());
    }
};
