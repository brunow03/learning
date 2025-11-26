import pygame
import os

class Settings():
	"""A class to store all settings for Alien Invasion"""

	def __init__(self):
		"""Initialize the game's static settings."""
		# Screen settings
		self.screen_width = 1200
		self.screen_height = 800 * (1000/1200)
		self.bg = pygame.transform.scale(pygame.image.load("images/stars.bmp"), (self.screen_width, self.screen_height))
		self.bg_color = (230, 230, 230)

		# Bullet settings
		self.bullet_width = 3
		self.bullet_height = 15
		self.bullet_color = 0, 0, 255
		#self.bullet_color = 60, 60, 60
		self.bullets_allowed = 3

		# Alien settings
		self.fleet_drop_speed = 10

		# How quickly the game speeds up
		self.speedup_scale = 1.1
		# How quickly the alien point values increase
		self.score_scale = 1.5

		# Ship settings
		self.ship_limit = 3

		# Sound effects
		self.shooting_sound = pygame.mixer.Sound("sound-effects/shoot.wav")
		self.alien_explosion = pygame.mixer.Sound("sound-effects/expl2.wav")
		#self.alien_explosion.set_volume(0.6)

		self.initialize_dynamic_settings()


	def initialize_dynamic_settings(self):
		"""Initialize settings that change throughout the game."""
		self.ship_speed_factor = 1.5
		self.bullet_speed_factor = 3
		self.alien_speed_factor = 0.3

		# fleet_direction of 1 represents right; -1 represents left.
		self.fleet_direction = 1

		# Scoring
		self.alien_points = 50

	def increase_speed(self):
		"""Increase speed settings and alien point values."""
		self.ship_speed_factor *= self.speedup_scale
		self.bullet_speed_factor *= self.speedup_scale
		self.alien_speed_factor *= self.speedup_scale

		self.alien_points = int(self.alien_points * self.score_scale)

