#!/bin/sh 

# Discord
filename="discord.deb"
curl -Lo "$filename" "https://discord.com/api/download?platform=linux&format=deb"
sudo apt install "./$filename" -y && rm "$filename"

# Steam
sudo apt install steam -y
#filename="steam.deb"
#curl -LO "$filename" "https://cdn.akamai.steamstatic.com/client/installer/steam.deb"
#sudo apt install "./$filename" -y && rm "$filename"

