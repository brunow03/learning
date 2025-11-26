def city_country(city, country, population = None):
	"""Receive a city and its country and returns it in City, Country format"""
	if population:
		result_string = city.title() + ', ' + country.title() + ' - population ' + str(population)
	else:
		result_string = city.title() + ', ' + country.title()
	return result_string
