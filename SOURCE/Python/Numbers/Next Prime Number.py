# Next Prime Number: Have the program find prime numbers
# until the user chooses to stop asking for the next one.

# Uses the Lucas–Lehmer primality test, based on http://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test#The_test's pseudocode
import math

def isPrime(n):
	s = 4
	M = math.pow(2, n) - 1
	
	it = 0
	while it < (n - 2):
		s = ((s * s) - 2) % M
	
	return s == 0

def primeNumbers(l):
	for i in range(l):
		if isPrime(i):
			yield i

def main():
	l = 0
	while True:
		try:
			l = int(input("Enter number: "))
		except ValueError:
			print("Enter a valid number.\n")
			continue
		break
	
	for _ in primeNumbers(l):
		print(_)

if __name__ == "__main__":
	main()