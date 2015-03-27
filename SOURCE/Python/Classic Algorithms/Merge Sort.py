# Sorting: Sorting an array using Merge Sort

# Based on http://en.wikipedia.org/wiki/Merge_sort#Top-down_implementation_using_lists's psuedocode
def merge_sort(m):
	l = len(m)

	# Base case. A list of zero or one elements is sorted, by definition.
	if l <= 1:
		return m
	
	# Recursive case. First, *divide* the list into equal-sized sublists.
	left, right = [], []
	middle = round(l / 2)
	
	i = 0
	while i < middle:
		left.append(m[i])
		i += 1
	
	i = middle
	while i < l:
		right.append(m[i])
		i += 1
	
	# Recursively sort both sublists
	left = merge_sort(left)
	right = merge_sort(right)
	
	# Then merge the now-sorted sublists.
	return merge(left, right)

def merge(left, right):
	result = []
	while len(left) != 0 and len(right) != 0:
		if left[0] <= right[0]:
			result.append(left[0])
			left = left[1:]
		else:
			result.append(right[0])
			right = right[1:]
	# either left or right may have elements left
	while len(left) != 0:
		result.append(left[0])
		left = left[1:]
	
	while len(right) != 0:
		result.append(right[0])
		right = right[1:]
	
	return result

def main():
	arr = [8, 6, 7, 5, 3, 0, 9]
	sorted = [0, 3, 5, 6, 7, 8, 9]
	
	print("Output:", merge_sort(arr))
	print("Expected:", sorted)

if __name__ == "__main__":
	main()