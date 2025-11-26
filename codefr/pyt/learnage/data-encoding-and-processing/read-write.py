import csv
from collections import namedtuple

with open('physics_particles.csv') as f:
	f_csv = csv.reader(f)
	headings = next(f_csv)
	Row = namedtuple('Row', headings)
	for r in f_csv:
		row = Row(*r)
		print(row.charge)
		
print("\nReading the data as a sequence of dictionaries:")

with open('physics_particles.csv') as f:
	f_csv = csv.DictReader(f)
	for row in f_csv:
		print(f'{row['name']} \t {row['mass']}')

