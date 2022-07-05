#!/bin/sh

SPEED=50

repo_location=./
if [ ! -f "$repo_location/Makefile" ]; then
	repo_location=../
fi

visualizer_dir=$repo_location.visualizer

VISUALIZER() {
	ARGS="$@";
	if [ "$(uname -s)" = "Darwin" ]; then
		echo "./push_swap $ARGS | pbcopy"
		./push_swap $ARGS | pbcopy
		echo "output copied to mac clipboard"
	elif [ "$(uname -s)" = "Linux" ]; then
		echo "./push_swap $ARGS | xclip -selection clipboard"
		./push_swap $ARGS | xclip -selection clipboard &&
		echo "Output copied to linux clipboard" ||
		echo "xclip is not installed. If you want to use it:\n  sudo apt install xclip -y"
	fi
	open "https://GlaceCoding.github.io/tools/pushswap/visualizer/?size=15&speed=$SPEED&args=$ARGS"
}

visualizeRandom() {
	min=$1
	max=$2
	input=$(ruby -e "puts ($min..$max).to_a.shuffle.join(' ')")

	VISUALIZER $input
}

small() {
	visualizeRandom -1 1
}

medium() {
	visualizeRandom -3 1
}

big() {
	visualizeRandom 1 100
}

huge() {
	visualizeRandom 1 500
}

main() {
	# check_dependencies || return 1
	while [ ! "$1" = "" ]; do
		if [ "$1" = "small" ]; then
			small
		elif [ "$1" = "medium" ]; then
			medium
		elif [ "$1" = "big" ]; then
			big
		elif [ "$1" = "huge" ]; then
			huge
		else
			VISUALIZER $@
			break
		fi
		shift
	done
	
}

make -C $repo_location
main $@

