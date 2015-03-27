alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

def encrypt(text, shift):
	if not (1 < shift < 25):
		raise ValueError("Shift key must be between 1 and 25.")
	
	i, enc = 0, ""
	text = text.upper()
	
	while i < len(text):
		if not (text[i].upper() in alphabet):
			enc += text[i]
		else:
			enc += alphabet[(alphabet.index(text[i]) + shift) % 26]
		i += 1
	
	return enc

def decrypt(text, shift):
	if not (1 < shift < 25):
		raise ValueError("Shift key must be between 1 and 25.")
	i, enc = 0, ""
	
	while i < len(text):
		if not (text[i].upper() in alphabet):
			enc += text[i]
		else:
			enc += alphabet[(alphabet.index(text[i].upper()) - shift) % 26]
		i += 1
	
	return enc

def main():
	while True:
		print("Encryption (E) or Decryption (D)?")
		
		i = input("> ")
		if i == "E" or i == "e":
			print(encrypt(input("Enter text to encrypt: "), int(input("Enter key: "))))
		elif i == "D" or i == "d":
			print(decrypt(input("Enter text to decrypt: "), int(input("Enter key: "))))

if __name__ == "__main__":
	main()