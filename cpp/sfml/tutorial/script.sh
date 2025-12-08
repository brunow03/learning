#! /bin/bash

# for n in {9..25}; do
#     mkdir example_$n
#     cp -r ./base/* -t ./example_$n/;
# done

# for n in {9..25}; do
#     cd example_$n
#     ./configure.sh
#     # ./build.sh
#     cd ..
# done

# for n in {1..9}; do
#     mv example_$n tutorial_$n
# done

for n in {1..9}; do
    mv tutorial_$n tutorial_0$n
done
