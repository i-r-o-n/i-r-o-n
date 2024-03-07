#!/bin/sh 

# LaTeX
wget https://mirror.ctan.org/systems/texlive/tlnet/install-tl-unx.tar.gz # or curl instead of wget
zcat < install-tl-unx.tar.gz | tar xf -
cd install-tl-*
sudo perl ./install-tl --no-interaction

echo 'PATH="/usr/local/texlive/2023/bin/x86_64-linux:$PATH"' >>~/.zshrc