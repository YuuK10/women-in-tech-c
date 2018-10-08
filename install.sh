#!/bin/zsh

echo "First compilation..."
make all

echo "Configuring scripts..."

game_path=$(pwd)
game_path_exp=$(sed 's/\//\\\//g' <<< $game_path)
expr="s/.*__GAME_PATH__/game_path=\'${game_path_exp}\/\'/"

#if [[ "$uname" == "Darwin" ]]; then
	sed -i "" ${expr} scripts/*
#else
#	sed -i ${expr} scripts/*
#fi

echo "Creating saves directory..."
mkdir data/saves

echo "Initializing game..."
rm src/player_function.c 2>&1 > /dev/null
lvl=$(cat data/current_level)
cp data/samples/$lvl.c src/player_function.c

echo "Creating alias"
echo "alias playgame='$game_path/scripts/playgame.sh'" >> ~/.zshrc
echo "alias editcode='$game_path/scripts/editcode.sh'" >> ~/.zshrc
echo "alias howtoplay='$game_path/scripts/howtoplay.sh'" >> ~/.zshrc
echo "alias nextlevel='$game_path/scripts/nextlevel.sh'" >> ~/.zshrc
echo "alias resetlevel='$game_path/scripts/resetlevel.sh'" >> ~/.zshrc
echo "alias resetgame='$game_path/scripts/resetgame.sh'" >> ~/.zshrc
source ~/.zshrc
reset
echo "Installation complete."
