class IceCreamStand(Restaurant):
	"""docstring for IceCreamStand"""
	def __init__(self, flavours): #"""+ atributos pedidos pelo init da classe mãe"""
		super().__init__("""atributos do init da classe mãe""")
		self.flavours = ['vanilla','chocolat','strawberry','blue berry','lemon']
		
	def display_flavours(self):
		print("Here are the flavours: ")
		for i in range(len(self.flavours)):
			print(i + ".: " + self.flavours[i])

	