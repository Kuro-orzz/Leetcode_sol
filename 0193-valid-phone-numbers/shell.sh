# Read from the file file.txt and output all valid phone numbers to stdout.
cat file.txt | while read line
do
    if [[ $line =~ ^\([0-9]{3}\)\ [0-9]{3}-[0-9]{4}$ ]] || [[ $line =~ ^[0-9]{3}-[0-9]{3}-[0-9]{4}$ ]];
    then
        echo $line
    fi
done
