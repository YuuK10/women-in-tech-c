#!/bin/zsh

__GAME_PATH__
cd $game_path

echo -n "What language should be installed ? (en/fr) : "
read language

while [[ "$language" != "en" && "$language" != "fr" ]]
do
	echo -n "Please choose only between en (english) or fr (french) : "
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
