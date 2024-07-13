#!/bin/bash

eval "$(ssh-agent -s)"
sudo ssh-add ~/Documents/git/keys/key_ssh
