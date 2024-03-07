#!/bin/sh
username="ryanoasis"
repository="nerd-fonts"

latest_release=$(curl -s "https://api.github.com/repos/${username}/${repository}/releases/latest" | jq -r '.tag_name')
echo "found fonts version $latest_release"

download_url="https://github.com/${username}/${repository}/releases/download/${latest_release}/JetBrainsMono.zip"

if [ -z "$latest_release" ]; then
    echo "Error: Unable to retrieve the latest release version."
    exit 1
fi

if [ -z "$download_url" ]; then
    echo "Error: Unable to construct the download URL."
    exit 1
fi

# Download the file
curl -LO "${download_url}"

unzip "*.zip" "*.ttf" "*.otf" -d ${HOME}/.fonts
sudo fc-cache -f -v
