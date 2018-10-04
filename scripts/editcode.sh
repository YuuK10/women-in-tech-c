#!/bin/sh
game_path="/Users/lsiquet/Documents/Projects/women-in-tech-c/"
cd $game_path
player_file_path="src/"
player_sample_path="sample/$(cat ../data/current_level)"
check_file="$(ls $player_file_path | grep player_function.c)"
if [ $check_file ]
then
	vim $player_file_path$check_file
else
	cp $player_sample_path $player_file_path
	mv $player_file_path$(cat ../data/current_level) $player_file_path$(echo player_function.c)
fi
