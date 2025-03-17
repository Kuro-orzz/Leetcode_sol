# Read from the file file.txt and output the tenth line to stdout.
if [ $(wc -l < file.txt) -ge 10 ];
then
    cat file.txt | head | tail -n 1
fi