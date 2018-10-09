#!/bin/zsh

__GAME_PATH__
cd $game_path

lang=$(cat data/config/language)

echo "WARNING : This command will reset all the game, including your progression."
echo "Are you ABSOLUTELY SURE that you want to reset the game ?"
echo -n "(Y/n) : "
read answer

while [[ "$answer" != "Y" && "$answer" != "n" ]]
do
	echo -n "Please only type Y or n : "
	read answer
done

if [[ "$answer" == "Y" ]]
then
	git show HEAD:data/current_level > data/current_level
	git show HEAD:data/data_level > data/data_level
	lvl=$(cat data/current_level)
	rm src/player_function.c 2>&1 > /dev/null
	cp data/samples/$lang/$lvl.c src/player_function.c 2>&1 > /dev/null
fi
