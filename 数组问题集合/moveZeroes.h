/************************************************************************/
/** 
* 题目：移动零
* 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
* 
* 示例 1:
* 输入: [0,1,0,3,12]
* 输出: [1,3,12,0,0]
* 说明:
* 必须在原数组上操作，不能拷贝额外的数组。
* 尽量减少操作次数。
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution 
{
	// 快慢指针移动 快指针一直移动，慢指针非0才移动
	void moveZeroes(vector<int>& nums) 
	{
		int index = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != 0)
			{
				nums[index++] = nums[i];
			}
		}

		for (int j = index; j < nums.size(); ++j)
		{
			nums[j] = 0;
		}
	}
}