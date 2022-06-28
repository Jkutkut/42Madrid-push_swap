#!/bin/sh

repo_location=./
if [ ! -f "$repo_location/Makefile" ]; then
	repo_location=../
fi

visualizer_dir=$repo_location.visualizer

VISUALIZER() {
	ARGS="$@";
	open "https://GlaceCoding.github.io/tools/pushswap/visualizer/?size=15&speed=150&args=$ARGS&queue="$(./push_swap $ARGS | tr '\n' ',')
}

visualizeRandom() {
	min=$1
	max=$2
	VISUALIZER $(ruby -e "puts ($min..$max).to_a.shuffle.join(' ')")
}

small() {
	visualizeRandom -1 1
}

medium() {
	visualizeRandom -3 1
}

# big() {
# 	visualizeRandom -19 20
# }

# huge() {
# 	visualizeRandom -190 200
# }

main() {
	# check_dependencies || return 1
	while [ ! "$1" = "" ]; do
		if [ "$1" = "small" ]; then
			small
		elif [ "$1" = "medium" ]; then
			medium
		# max len of url is 2048 chars
		# elif [ "$1" = "big" ]; then
		# 	big
		# elif [ "$1" = "huge" ]; then
		# 	huge
		else
			VISUALIZER $@
			break
		fi
		shift
	done
	
}

make -C $repo_location
main $@

