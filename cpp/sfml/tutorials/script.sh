#! /bin/bash

# for n in {9..25}; do
#     mkdir example_$n
#     cp -r ./base/* -t ./example_$n/;
# done

# for n in {10..25}; do
#     cd example_$n
#     ./configure.sh
#     # ./build.sh
#     cd ..
# done

# for n in {1..9}; do
#     mv example_$n tutorial_$n
# done

# for n in {1..9}; do
#     mv tutorial_$n tutorial_0$n
# done

# for n in {01..25}; do
#     [ "$n" = "02" ] && continue
#     echo $n
#     cd ./tutorial_$n
#     rm -rf build
#     # cmake -S . -B build
#     ./configure.sh
#     cd ..
# done

# echo "SUCCESS!!!!"

# for n in {01..25}; do
#     echo $n   
#     cd ./tutorial_$n
#     ls condigure.sh
#     cd ..
# done

# for n in {01..25}; do
#     echo $n
#     rm tutorial_$n/Textures/*.svg
#     # cp -r base/Textures -t ./tutorial_$n
# done

# for n in {18..24}; do
#     mkdir tutorial_$n
#     cp -r base/* -t tutorial_$n/
#     cd tutorial_$n
#     ./configure.sh
#     cd ..
# done

# for n in {01..24}; do
#     [ "$n" = "02" ] && continue
#     cp -r base/Fonts -t tutorial_$n/
# done

for n in {01..24}; do
    [ "$n" = "02" ] && continue
    cp base/run.sh -t tutorial_$n/
done
