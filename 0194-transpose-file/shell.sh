# Read from the file file.txt and print its transposed content to stdout.
#!/usr/bin/env bash

numCol=`head -n 1 file.txt | wc -w`

for i in $(seq 1 $numCol);
do
    echo `cut -d ' ' -f $i file.txt | tr '\n' ' '`
done;
