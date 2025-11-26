class Dog(): # is capitalized
	""" Modeling and simulations of dynamic dogs """
	def __init__(self, name, age):
		""" Initialization (AKA Constructor) """
		self.name = name
		self.age = age

	def sit(self):
		"""	Simulate a sitting dog """
		print(self.name.title() + " is now sitting.")

	def roll_over(self):
		""" Command the dog to roll over """
		print(self.name.title() + " is rolling over!")

doggo = Dog('Doggo', 4)

print("My dog's name is " + doggo.name.title() + ".")
print("My dog is " + str(doggo.age) + " years old.")