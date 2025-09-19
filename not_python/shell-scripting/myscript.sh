#!/bin/bash

command=/usr/bin/htop

if [ -f command ]
then
	echo "$command is avaiable, let's run it..."
else
	echo "$command is NOT avaiable, installing it..."
	sudo apt update && sudo apt install -y htop
fi

$command
