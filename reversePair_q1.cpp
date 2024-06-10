class Solution {
public:
   void merge(vector<int>& nums,int s,int mid,int e)
   {
            int len1=mid-s+1;
            int len2=e-mid;
        vector<int>temp1(len1);
        vector<int>temp2(len2);
        int k=s;

        for(int i=0;i<len1;i++)
            temp1[i]=nums[k++];

        for(int i=0;i<len2;i++)
        temp2[i]=nums[k++];

         k=s;
         int i=0;int j=0;
        while(i<len1 && j<len2)
        {
            if(temp1[i]<=temp2[j])
                nums[k++]=temp1[i++];   
            else
                nums[k++]=temp2[j++];
            
        }

        while(i<len1)
            nums[k++]=temp1[i++];
        
        while(j<len2)
           nums[k++]=temp2[j++];    
         
   }

   int countPairs(vector<int>& nums,int s, int mid,int e)
   {
        int r=mid+1;
        int cnt=0;
        for(int i=s;i<=mid;i++)
        {
            while(r<=e && nums[i]>2*(1LL)*nums[r])
            r++;
            cnt+=r-(mid+1);
        }
       return cnt;
   }
   int mergeSort(vector<int>& nums,int s,int e)
   {
       int c=0;
       if(s>=e)
       return c;
       int mid=s+(e-s)/2;
       c+=mergeSort(nums,s,mid);
       c+=mergeSort(nums,mid+1,e);
       c+=countPairs(nums,s,mid,e);
       merge(nums,s,mid,e);
       return c;
   }
    int reversePairs(vector<int>& nums) {
      
      ios::sync_with_stdio(NULL);
      cin.tie(NULL);cout.tie(NULL);
      
      return mergeSort(nums,0,nums.size()-1);    
    }
};
          
           //Method1
    /* int count=0;
        for(long i=0;i<nums.size();i++)
        {
            for(long j=i+1;j<nums.size();j++)
            {
               
                if(nums[i]>1LL*2*nums[j])
                count++;
                
            }
        }
        return count;  */
