#__GAME_PATH__

#cd $game_path

lvl=$(cat data/current_level)
echo "Recompiling level ${lvl}, please wait..."
make re
make clean
./game "$lvl"
