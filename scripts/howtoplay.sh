__GAME_PATH__
cd $game_path

lvl=$(cat data/current_level)
less "data/levels/docs/${lvl}"
