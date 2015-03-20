# Find e to the Nth Digit: Enter a number and have the program
# generate e up to that many decimal places.

import math

def e(l):
	n = 0
	i = 0
	while i < l:
		n += 1 / math.factorial(i)
		yield n
		
		i += 1

def main():
	while True:
		try:
			l = int(input("Enter length: "))
		except ValueError:
			print("Enter a valid number.\n")
			continue
		break
	
	for _ in e(l):
		print("Estimated:", _)
	else:
		print("Final estimation:", _)

if __name__ == "__main__":
	main()