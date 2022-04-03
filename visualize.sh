#!/bin/sh

visualizer_dir=".visualizer"

check_dependencies() {
	# Check python3 dependencies
	if ! command -v python3 >/dev/null 2>&1; then
		echo "Python3 is not installed. It can be installed with"
		echo "sudo apt install python3"
		return 1
	fi
	# python3 tkinter
	if ! python3 -c "import tkinter" >/dev/null 2>&1; then
		echo "Python3 tkinter is not installed. It can be installed with"
		echo "sudo apt install python3-tk"
		return 1
	fi
	return 0
}

small() {
	python3 $visualizer_dir/pyviz.py 1 3 2
}

medium() {
	python3 $visualizer_dir/pyviz.py 2 3 1 5 4
}

big() {
	input=$(ruby -e "puts (-20..20).to_a.shuffle.join(' ')")
	python3 $visualizer_dir/pyviz.py $input
}

main() {
	check_dependencies || return 1
	# python3 $visualizer_dir/pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
	while [ ! "$1" = "" ]; do
		if [ "$1" = "small" ]; then
			small
		elif [ "$1" = "medium" ]; then
			medium
		elif [ "$1" = "big" ]; then
			big
		else
			break
		fi
		shift
	done
	python3 $visualizer_dir/pyviz.py $@
}

make
main $@
