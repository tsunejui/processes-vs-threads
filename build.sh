#! /bin/sh

dir=apps
for full_path in "$dir"/*; do
    name=${full_path##*/}
    bin_name=${name%.*}
    bin_path="bin/$bin_name"
    echo $bin_path
    gcc -o $bin_path -lpthread $full_path
done