#!/bin/sh

# Colors:
NC='\033[0m' # No Color
RED='\033[1;31m';
YELLOW='\033[1;33m';
GREEN='\033[1;32m';
BLUE='\033[1;34m';

executable=./push_swap
checker=./checker
visualizer=./visualize.sh

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
	n_steps=$($executable $input | wc -l)
	if [ $n_steps -gt $max ]; then
		echo "${RED}[KO]${NC}"
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
		echo "${RED}[FAIL]${NC} The checker does not exist."
		echo "Please compile the project before running the tests."
		echo "make bonus"
		return
	fi


	single_test "basic" "1 3 2" 3 2
	file_test ".test/input_3elements" 3 2
	file_test ".test/input_5elements" 12 8
}

main $@