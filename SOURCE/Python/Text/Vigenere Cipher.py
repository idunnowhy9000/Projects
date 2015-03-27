alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

def encrypt(text, shift):
	i, enc = 0, ""
	text, shift = text.upper(), shift.upper()

	while i < len(text):
		enc += alphabet[(alphabet.index(text[i]) + alphabet.index(shift)) % 26]
		i += 1
	
	return enc

def decrypt(text, shift):
	pass

def main():
	while True:
		print("Encryption (E) or Decryption (D)?")
		
		i = input("> ")
		if i == "E" or i == "e":
			print(encrypt(input("Enter text to encrypt: "), input("Enter key: ")))
		elif i == "D" or i == "d":
			print(decrypt(input("Enter text to decrypt: "), input("Enter key: ")))

if __name__ == "__main__":
	main()