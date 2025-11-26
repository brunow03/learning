class Admin(User):
	"""docstring for Admin"""
	def __init__(self, privileges):
		super().__init__("""USER attr""")
		self.privileges = ['can add post','can delete post','can ban user']

	def show_privileges():
		
		