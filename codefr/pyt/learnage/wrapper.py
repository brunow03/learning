import time
from functools import wraps

def timethis(func):
	'''
	Decorator that reports the execution time
	'''
	@wraps(func)
	def wrapper(*args, **kwargs):
		start = time.time()
		result = func(*args, **kwargs)
		end = time.time()
		print(func.__name__, end - start)
		return result
	return wrapper

# Example use
def countdown(n):
	'''
	Counts down
	'''
	while n > 0:
		n -= 1

print(countdown(100000))
print(countdown.__name__)
print(countdown.__doc__)
print(countdown.__annotations__)
print(countdown.__wrapped__(100000))

from inspect import signature
print(signature(countdown))

# Undoig the wrapping

def add(x, y):
	return x + y

orig_add = add.__wrapped__
print(orig_add(3, 4))

# Decorators with arguments

import logging

def logged(level, name=None, message=None):
	'''
	Add logging to a function. level is the logging
	level, name is the logger name, and message is the
	log message. If name and message aren't specified,
	they default to the function's module and name.
	'''
	def decorate(func):
		logname = name if name else func.__module__
		log = logging.getLogger(logname)
		logmsg = message if message else func.__name__

		@wraps(func)
		def wrapper(*args, **kwargs):
			log.log(level, logmsg)
			return func(*args, **kwargs)
		return wrapper
	return decorate

# example use
@logged(logging.DEBUG)
def add(x, y):
	return x + y

@logged(logging.CRITICAL, 'example')
def spam():
	print('Spam!')

# Adjustable attributes at runtime

from functools import partial

def attach_wrapper(obj, func=None):
	if func is None:
		return partial(attach_wrapper, obj)
	setattr(obj, func.__name__, func)
	return func

# Enforcing type checking on a Function Using a Decorator

'''
@typeassert(int, int)
def add(x, y):
	return x + y
'''

# Implementation typeassert decorator

from inspect import signature
from functools import wraps

def typeassert(*ty_args, **ty_kwargs):
	def decorate(func):
		# If in optimized mode, disable type checking
		if not __debug__:
			return func

		# Map function argument names to supplied types
		sig  = signature(func)
		bount_types = sig.bind_partial(*ty_args, **ty_kwargs).arguments

		@wraps(func)
		def wrapper(*args, **kwargs):
			bount_values = sig.bind(*args, **kwargs)
			# Enforce type assertions across supplied arguments
			for name, value in bount_values.arguments.items():
				if name in bount_types:
					if not isinstance(value, bount_types[name]):
						raise TypeError(
							'Argument {} must be {}'.format(name, bount_types[name])
							)
			return func(*args, **kwargs)
		return wrapper
	return decorate


