#!/bin/zsh

if [[ -z "$1" ]]
then
  language="en"
else
  language=$1
fi

echo "First compilation..."
make all

echo "Configuring scripts..."

game_path=$(pwd)
game_path_exp=$(sed 's/\//\\\//g' <<< $game_path)
expr="s/.*__GAME_PATH__/game_path=\'${game_path_exp}\/\'/"

sed -i "" ${expr} scripts/*

echo "Creating saves directory..."
mkdir -p data/saves 2>&1 > /dev/null

echo "Creating alias"
echo "alias playgame='$game_path/scripts/playgame.sh'" >> ~/.zshrc
echo "alias editcode='$game_path/scripts/editcode.sh'" >> ~/.zshrc
echo "alias howtoplay='$game_path/scripts/howtoplay.sh'" >> ~/.zshrc
echo "alias nextlevel='$game_path/scripts/nextlevel.sh'" >> ~/.zshrc
echo "alias resetlevel='$game_path/scripts/resetlevel.sh'" >> ~/.zshrc
echo "alias resetgame='$game_path/scripts/resetgame.sh'" >> ~/.zshrc
echo "alias setlanguage='$game_path/scripts/setlanguage.sh'" >> ~/.zshrc
echo "alias help='$game_path/scripts/help.sh'" >> ~/.zshrc

echo "Configuring language..."
./scripts/setlanguage.sh $language

echo "Configuring VIM editor..."
echo "set number" >> ~/.vimrc
echo "syntax on" >> ~/.vimrc
echo "set mouse=a" >> ~/.vimrc

echo "Initializing game..."
rm -rf src/player_function.c 2>&1 > /dev/null
lvl=$(cat data/current_level)
cp data/samples/$language/$lvl.c src/player_function.c 2>&1 > /dev/null

echo "\n\n\033[0;32mInstallation complete. Please restart the terminal to play.\n"
echo "\033[0;33mNote : to activate the developper mode, you can turn the DEVELOPPER_MODE"
echo "macro to 1 in includes/game.h"
