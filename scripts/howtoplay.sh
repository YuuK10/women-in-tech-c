__GAME_PATH__
cd $game_path

lvl=$(cat data/current_level)
cat "data/levels/docs/${lvl}" | less
