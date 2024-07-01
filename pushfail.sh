#!/bin/bash

eval "$(ssh-agent -s)"
ssh-add ~/Documents/git/keys/key_ssh
