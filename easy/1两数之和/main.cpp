// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

// 示例:

// 给定 nums = [2, 7, 11, 15], target = 9

// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]

#include <iostream>
using namespace std;

//逻辑暴力破解，嵌套循环 O(n^2)
class Solution_01 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> resu(2);
        for (int i = 0; i < nums.size(); i++)
        {
            int l=nums[i];
            for(int j=i+1;j<nums.size();j++){
                int r=nums[j];
                if (target==(l+r)){
                    resu[0]=l;
                    resu[1]=r;
                    return resu;
                }
            }
        }
        
    }
};
//利用空间换时间
//unordered_map hash存储，查找的时间复杂度为O(1)
//一遍hash查找O(n)
class Solution_02 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int> mp;
        for ( int i = 0 ;i < nums.size();i++ ) {
            if ( mp.find(target-nums[i]) != mp.end() ){
                return {mp.find(target-nums[i])->second,i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
int main{

}