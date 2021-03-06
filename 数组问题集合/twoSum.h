/************************************************************************/
/** 
* 题目：两数之和
* 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
* 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
*
* 示例 1:
* 给定 nums = [2, 7, 11, 15], target = 9
* 因为 nums[0] + nums[1] = 2 + 7 = 9
* 所以返回 [0, 1]
* 示例 2:
* 给定 nums = [3, 3], target = 6
* 因为 nums[0] + nums[1] = 3 + 3 = 6
* 所以返回 [0, 1]
*
* 注意：
* 因为要保存索引，所以不能排序，不要打乱顺序
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution 
{
	// 暴力解决
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> ret;
		if (nums.size() < 2)
		{
			return ret;
		}

		int len = nums.size();
		for (int i = 0; i < len - 1; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					ret.push_back(i);
					ret.push_back(j);
					break;
				}
			}
		}
		return ret;
	}

	// 一遍hash
	// 特例就是 类似[3,3] target = 6 这种情况
	vector<int> twoSum2(vector<int>& nums, int target) 
	{
		vector<int> ret;
		if (nums.size() < 2)
		{
			return ret;
		}

		map<int, int> tmp;
		for (int i = 0; i < nums.size(); ++i)
		{
			int sub = target - nums[i];
			auto iter = tmp.find(sub);
			if (iter != tmp.end())
			{
				ret.push_back((*iter).second);
				ret.push_back(i);
				break;
			} 
			else
			{
				tmp[nums[i]] = i;
			}
		}

		return ret;
	}
}