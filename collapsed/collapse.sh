#!/bin/bash

# Usage: ./fetch_files.sh /path/to/source /path/to/destination

SRC="$1"
DST="$2"

# Check arguments
if [[ -z "$SRC" || -z "$DST" ]]; then
    echo "Usage: $0 <source_directory> <destination_directory>"
    exit 1
fi

# Create destination folder if it doesn't exist
mkdir -p "$DST"

# Copy all files (recursively) into destination folder
# while handling duplicate filenames by renaming them
find "$SRC" -type f | while read -r file; do
    base=$(basename "$file")
    dest="$DST/$base"
    
    # If a file with the same name exists, append a counter
    if [[ -e "$dest" ]]; then
        counter=1
        while [[ -e "$DST/${base%.*}_$counter.${base##*.}" ]]; do
            ((counter++))
        done
        dest="$DST/${base%.*}_$counter.${base##*.}"
    fi
    
    cp "$file" "$dest"
done

echo "All files copied from '$SRC' to '$DST'."
