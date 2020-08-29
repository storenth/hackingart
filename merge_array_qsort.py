#!/usr/bin/python3

"""Merge sorted array challenge by Kirill Zhdanov to Huawei"""

# x and y arrays initial state
target_array = [100, 200, 300, 0, 0, 0]
input_array = [200, 500, 600]
buffer = 0

# helpers variables
merge_len = len(target_array)
input_len = len(input_array)
merge_index = merge_len - 1
index = merge_len - input_len

# Insert y in x array
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
