def matchcase(word):
	def replace(m):
		text = m.group()
		if text.isupper():
			return word.upper()
		elif text.islower():
			return text.lower()
		elif text[0].isupper():
			return word.capitalize()
		else:
			return word
	return replace
