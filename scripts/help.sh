__GAME_PATH__
cd $game_path

lang=$(cat data/config/language)
cat "data/docs/$lang/help" | less
