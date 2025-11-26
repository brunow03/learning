#!/bin/bash
# to tar: to make a compressed version of some file

for file in logfiles/*.log
do
	tar -czvf $file.tar.gz $file
	rm $file
done
