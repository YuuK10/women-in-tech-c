__GAME_PATH__
cd $game_path

lvl=$(cat data/current_level)
lang=$(cat data/config/language)
cat "data/levels/docs/$lang/${lvl}" | less
