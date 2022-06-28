#!/bin/sh

# Colors:
NC='\033[0m' # No Color
RED='\033[1;31m';
YELLOW='\033[1;33m';
GREEN='\033[1;32m';
BLUE='\033[1;34m';

repo_location=./
if [ ! -f "$repo_location/Makefile" ]; then
	repo_location=../
fi

executable=${repo_location}push_swap


checker=${repo_location}checker
os=$(uname -s)
if [ ! -f $checker ]; then
	if [ "$1" == "--linux" ]; then
		checker=${repo_location}checker_linux
	elif [ "$1" == "--mac" ]; then
		checker=${repo_location}checker_mac
	elif [ "$os" = "Linux" ]; then
		checker=${repo_location}checker_linux
	elif [ "$os" = "Darwin" ]; then
		checker=${repo_location}checker_mac
	fi
fi

visualizer=${repo_location}scripts/visualize.sh

single_test() {
	name="$1"
	input="$2"
	max=$3
	outstanding=$4

	echo "  - ${BLUE}$name${NC} \c"
	$executable $input | $checker $input 2> error.tmp > success.tmp
	check=$(cat success.tmp)
	fail=$(cat error.tmp)
	rm -f error.tmp success.tmp
	if [ ! "$check" = "OK" ]; then
		echo " ${RED}[FAIL]${NC}"
		echo "$executable $input"
		echo "$executable $input | $checker $input"
		echo "$visualizer $input"
		echo "Fail error: $fail"
		return 1
	fi
	n_steps=$($executable $input | wc -l | xargs)
	if [ $n_steps -gt $max ]; then
		echo "${RED}[KO]${NC} -> $n_steps steps"
	else
		if [ ! "$outstanding" = "" ] && [ $outstanding -ge $n_steps ]; then
			echo "${GREEN}[Outstanding]${NC}"
		else
			echo "${GREEN}[OK]${NC}"
		fi
	fi
}

file_test() {
	file="$1"
	filename=$(basename $file)
	max=$2
	outstanding=$3

	echo "- ${BLUE}$filename${NC}"
	echo "Testing $name: maximum: $max outstanding: $outstanding"
	i=0
	while read line; do
		# If the line is empty, skip it:
		if [ "$line" = "" ]; then
			continue
		fi
		single_test "$i: {$line}" "$line" $max $outstanding ||
		break
		i=$((i+1))
	done < $file
}

random_test() {
	tests=$1
	max=$2

	avg=0
	echo "- ${BLUE}$tests Random tests${NC}"
	for i in {0..$tests}; do
		input=$(ruby -e "puts (0..$max).to_a.shuffle.join(' ')")

		$executable $input | $checker $input 2> error.tmp > success.tmp
		check=$(cat success.tmp)
		fail=$(cat error.tmp)
		rm -f error.tmp success.tmp
		if [ ! "$check" = "OK" ]; then
			echo " ${RED}[Not sorted]${NC}"
			echo "$executable $input"
			echo "$executable $input | $checker $input"
			echo "$visualizer $input"
			echo "Fail error: $fail"
			return 1
		fi

		n_steps=$($executable $input | wc -l | xargs)
		avg=$(($avg + $n_steps / $tests))
	done
	echo "Executed $tests random tests. Avg: $avg moves"
}

main() {
	# Check if the executable exists:
	if [ ! -f $executable ]; then
		echo "${RED}[FAIL]${NC} The executable does not exist."
		echo "Please compile the project before running the tests."
		echo "make re"
		return
	fi

	# Check if the checker exists:
	if [ ! -f $checker ]; then
		echo "${RED}[FAIL]${NC} The checker '$checker' does not exist."
		echo "Please compile the project before running the tests."
		echo "make bonus"
		return
	fi

	random_test 10 3
	random_test 10 5
	random_test 10 10
	random_test 1 25
	random_test 1 50
	random_test 1 100
	# file_test "${repo_location}.test/input_3elements" 3 2
	# file_test "${repo_location}.test/input_5elements" 12 8
	# random_test 100 700 900 1100 1300 1500
	# random_test 500 5500 7000 8500 10000 11500
}

trap "rm -f error.tmp success.tmp; return" 2
main $@