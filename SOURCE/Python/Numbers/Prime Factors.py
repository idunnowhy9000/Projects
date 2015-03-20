# Prime Factorization: Have the user enter a number
# and find all Prime Factors (if there are any) and display them.

# Original algorithm: http://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
import math

def primeFact(n):
	while n % 2 == 0:
		yield n
		n /= 2
	
	i = 3
	while i <= math.sqrt(n):
		while n % i == 0:
			yield i
			n /= i
		
		i += 2
	
	if n > 2:
		yield n

def main():
	while True:
		try:
			l = int(input("Enter number: "))
		except ValueError:
			print("Enter a valid number.\n")
			continue
		break
	
	for _ in primeFact(l):
		print(int(_))

if __name__ == "__main__":
	main()