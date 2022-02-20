#!/bin/bash
while [ -n "$1" ]
do
case "$1" in
--input_folder) input=$2 ;;
--extension)  ext=$2 ;;
--backup_folder) backup=$2 ;;
--backup_archive_name) archive=$2 ;;
esac
shift 
shift
done
mkdir $backup
for file in $(find "$input" -type f -name "*.$ext")
do
newname=$(echo "$file" | sed 's|/|-|g')
cp "$file" "$backup/$newname"
done
tar -czf "$archive" "$backup/"
echo done
