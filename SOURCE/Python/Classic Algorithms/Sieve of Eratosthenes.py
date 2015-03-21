# Sieve of Eratosthenes: The sieve of Eratosthenes is one of the most efficient ways
# to find all of the smaller primes (below 10 million or so).
import math

def sieve(n):
	prime = [False] * n
	
	i = 2
	while i < n:
		prime[i] = True
		i += 1
	
	i = 2
	while (i * i) < n:
		if prime[i]:
			j = 0
			while (i * i + i * j) < n:
				prime[i * i + i * j] = False
				j += 1
		
		i += 1
	
	i = 2
	while i < n:
		if prime[i]:
			yield i
		
		i += 1

def main():
	while True:
		try:
			l = int(input("Enter length: "))
		except ValueError:
			print("Enter a valid number.\n")
			continue
		break
	
	for _ in sieve(l):
		print(_)

if __name__ == "__main__":
	main()