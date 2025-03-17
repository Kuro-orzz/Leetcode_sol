# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | xargs | tr ' ' '\n' | sort | uniq -c | sort -rhk1 | awk '{print $2, $1}'