#!/usr/bin/python3

"""Merge sorted array challenge by Kirill Zhdanov to Huawei:
Given two sorted integer arrays x and y, merge y into x as one sorted array.
The number of elements initialized in x and y are m and n respectively.
You may assume that x has enough space to hold additional elements from y. It's size is m + n.
Array values fall into [-10^9, 10^9] range.

Example:
    Input:
        x = [100,200,300,0,0,0], m = 3
        y = [200,500,600], n = 3

    Output:
        [100,200,200,300,500,600]"""

# x and y arrays initial state
target_array = [100, 200, 300, 0, 0, 0]
input_array = [200, 500, 600]

# helpers variables
merge_len = len(target_array)
input_len = len(input_array)
merge_index = merge_len - 1
index = merge_len - input_len

# Insert y in x array because known m and n
for i in range(merge_index, -1, -1):
	if (i - index) > -1:
		target_array[i] = input_array[i-index]

def quicksort(array):
    """Quick sort implementation.
    Args:
        List need to be sorted
    Returns:
        Sorted list"""
    if len(array) < 2:
        # base case, arrays with 0 or 1 element are already "sorted"
        return array
    else:
        # recursive case
        pivot = array[0]
        # sub-array of all the elements less than the pivot
        less = [i for i in array[1:] if i <= pivot]
        # sub-array of all the elements greater than the pivot
        greater = [i for i in array[1:] if i > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)

print(quicksort(target_array)) # stdout sorted list
