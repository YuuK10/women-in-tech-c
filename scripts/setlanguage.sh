#!/bin/zsh

__GAME_PATH__
cd $game_path

if [[ -z "$1" ]]
then
	echo -n "What language should be installed ? (en/fr) : "
	read language
else
	language=$1
fi

while [[ "$language" != "en" && "$language" != "fr" ]]
do
	echo -n "Please choose only between 'en' or 'fr' : "
	read language
done

mkdir -p data/config 2>&1 > /dev/null
touch data/config/language
echo $language > data/config/language

if [[ "$language" == "en" ]]
then
	echo "The language has been set to english"
elif [[ "$language" == "fr" ]]
then
	echo "La langue est maintenant configurée en français"
fi

lvl=$(cat data/current_level)

rm src/player_function.c 2>&1 > /dev/null
cp data/samples/$language/$lvl.c src/player_function.c 2>&1 > /dev/null
