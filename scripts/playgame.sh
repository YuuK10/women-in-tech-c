__GAME_PATH__
cd $game_path

lvl=$(cat data/current_level)
echo "Recompiling level ${lvl}, please wait..."
errors=$(make 2>&1)

if [ -z "$errors" ]
then
	./game "${lvl}"
else
	echo "\033[0;35mOh, it looks like you have errors in your code. You should recheck it :)"
fi
