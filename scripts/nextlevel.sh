#!/usr/bin/env zsh

__GAME_PATH__
cd $game_path

lvl=$(cat data/current_level)
level_line=$(grep $lvl data/data_level)
level_status=$(echo $level_line | cut -f2)

if [[ "$level_status" == '1' ]]
then
    next_level_line=$(grep -A 1 $lvl data/data_level | tail -n 1)
    next_level_name=$(echo $next_level_line | cut -f1)

	if [[ "$next_level_name" = "$lvl" ]]
	then
		less data/levels/docs/victory
	else
    	echo $next_level_name > data/current_level
    	echo "Next level : $next_level_name"

    	src_path="src/"
    	save_path="data/saves/"
    	sample_path="data/samples/"

    	mv src/player_function.c "${save_path}${lvl}.c"
    	cp "${sample_path}${lvl}.c" src/player_function.c
	fi
else
    echo "You did not finish the current level yet."
fi
