echo "First compilation..."
make all

echo "Configuring scripts..."

game_path=$(pwd)

game_path_exp=$(sed 's/\//\\\//g' <<< $game_path)
exp="s/.*__GAME_PATH__/game_path=\"${game_path_exp}\/\"/"
sed -i "" $exp scripts/*

echo "Creating alias"
echo "alias playgame='$game_path/scripts/playgame.sh'" >> ~/.zshrc
echo "alias editcode='$game_path/scripts/editcode.sh'" >> ~/.zshrc
echo "alias howtoplay='$game_path/game'" >> ~/.zshrc
reset
echo "Installation complete."
