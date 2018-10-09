#!/bin/sh

__GAME_PATH__
cd $game_path

lvl=$(cat data/current_level)
lang=$(cat data/config/language)
check_file="$(ls src | grep player_function.c)"
if [ $check_file ]
then
	vim src/player_function.c
else
	cp samples/$lang/$lvl.c src/player_function.c
fi
