from urllib import request, parse

# Base URL being accessed
url = 'http://httpbin.org/get'

# Dictionary of query paramenter (if any)
parms = {
	'name1' : 'value1',
	'name2' : 'value2'
}

# Encode the query string
querystring = parse.urlencode(parms)

# Make a GET request and read the responde
u = request.urlopen(url + '?' + querystring)
resp = u.read()

# Make a POST request and read the response
u2 = request.urlopen(url, querystring.encode('ascii'))
resp2 = u.read()