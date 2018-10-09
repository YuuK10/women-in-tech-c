#!/bin/zsh

__GAME_PATH__
cd $game_path

lvl=$(cat data/current_level)
lang=$(cat data/config/language)

echo "Are you sure to want to reset the level ${lvl} ?"
echo "Be aware that you will lose all your code for this level.\n"
echo -n "(Y/n) : "
read  answer

while [[ "$answer" != "Y" && "$answer" != "n" ]]
do
	echo -n "Please only type Y or : "
	read answer
done

if [[ "$answer" == "Y" ]]
then
	rm src/player_function.c 2>&1 > /dev/null
	cp data/samples/$lang/$lvl.c src/player_function.c 2>&1 > /dev/null
fi
