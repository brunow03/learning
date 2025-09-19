#!/bin/bash

var=1

while [ -f ./testfile ]
do
	echo "As of $(date), it exists."
done

echo "As of $(date), it has gone missing"

