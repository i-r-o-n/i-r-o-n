#!/bin/sh
cd ~
rmdir Pictures Public Music Templates Videos
mkdir ~/sync

# Visual Studio Code
sudo apt-get install wget gpg git apt-transport-https curl perl

wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
rm -f packages.microsoft.gpg

# KeePassXC
sudo add-apt-repository ppa:phoerious/keepassxc -y

# Syncthing
sudo mkdir -p /etc/apt/keyrings
sudo curl -L -o /etc/apt/keyrings/syncthing-archive-keyring.gpg https://syncthing.net/release-key.gpg

echo "deb [signed-by=/etc/apt/keyrings/syncthing-archive-keyring.gpg] https://apt.syncthing.net/ syncthing stable" | sudo tee /etc/apt/sources.list.d/syncthing.list

# Signal
wget -O- https://updates.signal.org/desktop/apt/keys.asc | gpg --dearmor > signal-desktop-keyring.gpg
cat signal-desktop-keyring.gpg | sudo tee /usr/share/keyrings/signal-desktop-keyring.gpg > /dev/null

echo 'deb [arch=amd64 signed-by=/usr/share/keyrings/signal-desktop-keyring.gpg] https://updates.signal.org/desktop/apt xenial main' |\
  sudo tee /etc/apt/sources.list.d/signal-xenial.list


# Update package database
sudo apt update

# Install
sudo apt install code keepassxc syncthing signal-desktop -y


# Spotify
sudo snap install spotify -y

# Desktop Background
echo "from PIL import Image; Image.new(\"RGB\", (512, 512)).save(\"bg.png\")" > bg.py
python3 bg.pyg && rm bg.py

# Fonts
sh fonts.sh

# Terminal
sudo apt install zsh -y
chsh -s $(which zsh)

exec zsh
# logout/login might be required?
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ~/powerlevel10k
echo 'source ~/powerlevel10k/powerlevel10k.zsh-theme' >>~/.zshrc

sudo apt update && sudo apt upgrade -y

# Games
sh games.sh

# LaTeX
sh latex.sh