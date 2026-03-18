class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        mpp={0:-1}
        pre=0; res=0
        for j in range(len(nums)):
            if nums[j]==0:
                nums[j]=-1
        #print(nums)
        for i in range(len(nums)):
            pre+=nums[i]
            #mpp[pre]=i
            if pre in mpp:
                res=max(res,i-mpp[pre])
            else:mpp[pre]=i
        return res