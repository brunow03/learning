#!/bin/bash

lines=$(ls -lh $1 | wc -l)

echo "You have $(($lines-1)) objects in the $1 directory."
