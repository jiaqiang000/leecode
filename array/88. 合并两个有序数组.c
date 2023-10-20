#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  https://leetcode.cn/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
      // p1和p2分别作为nums1和nums2数组的指针。
      int p1 = 0, p2 = 0;
      // 创建一个sorted数组，用于存放合并后的结果。
      int sorted[m + n];
      // cur用于暂存当前要加入sorted数组中的元素。
      int cur = 0;
      // 循环条件：p1和p2中至少有一个指针没有遍历完其对应的数组。
      while (p1 < m || p2 < n)
      {
            // 以下条件判断用于选择哪个数组的元素应加入sorted数组。
            if (p1 >= m){
                  // 如果nums1已经遍历完，那么选取nums2中的元素。
                  sorted[cur] = *(nums2 + p2);
                  p2++;cur++;
            } else if (p2 >= n){
                  // 如果nums2已经遍历完，那么选取nums1中的元素。
                  sorted[cur] = *(nums1 + p1);
                  p1++;cur++;
            } else if (*(nums1 + p1) < *(nums2 + p2)){
                  sorted[cur] = *(nums1 + p1);
                  p1++;cur++;
            } else {
                  sorted[cur] = *(nums2 + p2);
                  p2++;cur++;
            }      
      }
      // 数组复制    
      for (size_t i = 0; i < nums1Size; i++)
      {
            nums1[i] = sorted[i];
      }
}
int main()
{
      int nums1[6] = {1,2,3,0,0,0}; 
      int m = 3; 
      int nums2[3] = {2,5,6};
      int n = 3;
      m = 3;
      int test1[6] = {1,2,3,0,0,0}; 
      int test2[6] = {1,2,3,0,0}; 

      merge(nums1, sizeof(nums1)/sizeof(int), m, nums2, sizeof(nums2)/sizeof(int), n);
      for (int  i = 0; i < sizeof(nums1)/sizeof(int); i++)
      {
            printf("%d\n", nums1[i]);
      }
      
      return 0;
}