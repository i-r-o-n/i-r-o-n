#!/bin/bash

key="$2"
count=$(echo "$1" | tr -cd "$key" | wc -c)
echo "The character '$key' occurs $count times in the text."
