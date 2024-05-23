import unittest
from city_functions import city_country

class CityCountriesTestCase(unittest.TestCase):
	"""Tests for city_functions.py"""

	def test_city_country(self):
		"""Do Moscow, Russia works?"""
		city_country_test = city_country('moscow', 'russia')
		self.assertEqual(city_country_test, 'Moscow, Russia')

	def test_city_country_population(self):
		"""Checks city country population this time"""
		city_country_population_test = city_country('sao paulo', 'brazil', 11000000)
		self.assertEqual(city_country_population_test, 'Sao Paulo, Brazil - population 11000000')

unittest.main()