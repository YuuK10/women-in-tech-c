#!/bin/zsh

echo "First compilation..."
make all

echo "Configuring scripts..."

game_path=$(pwd)
game_path_exp=$(sed 's/\//\\\//g' <<< $game_path)
expr="s/.*__GAME_PATH__/game_path=\'${game_path_exp}\/\'/"

if [[ "$uname" == "Darwin" ]]; then
	sed -i "" ${expr} scripts/*
else
	sed -i ${expr} scripts/*
fi

echo "Creating alias"
echo "alias playgame='$game_path/scripts/playgame.sh'" >> ~/.zshrc
echo "alias editcode='$game_path/scripts/editcode.sh'" >> ~/.zshrc
echo "alias howtoplay='$game_path/scripts/howtoplay.sh'" >> ~/.zshrc
echo "alias nextlevel='$game_path/scripts/nextlevel.sh'" >> ~/.zshrc
source ~/.zshrc
reset
echo "Installation complete."
