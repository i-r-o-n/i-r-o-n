#!/bin/bash
#args: $1:head $2:file_type
for file in *."$2"; do
  new_name="$1${file}"
  mv "$file" "$new_name"
done
