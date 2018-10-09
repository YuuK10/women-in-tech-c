__GAME_PATH__
cd $game_path

lvl=$(cat data/current_level)
echo "Recompiling level ${lvl}, please wait..."
errors=$(make 2>&1)

if [ -z "$errors" ]
then
	> data/error
	./game "${lvl}" 2>data/exec_error;
	response=$(cat data/exec_error)
	if [ -n "$response" ]
	then
		echo "\033[0;35mWell well... You program times out. If you have a loop inside,"
		echo "you definitely should check its condition :D"
	fi
else
	echo "\033[0;35mOh, it looks like you have errors in your code. You should recheck it :)"
fi
