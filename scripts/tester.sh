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
		echo "$executable $input | pbcopy"
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
			echo "${GREEN}[Outstanding]${NC}\c"
		else
			echo "${GREEN}[OK]${NC}\c"
		fi
		echo " -> $n_steps"
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
		single_test "$(printf "%03d" $i): {$line}" "$line" $max $outstanding ||
		break
		i=$((i+1))
	done < $file
}

random_test() {
	tests=$1
	max=$2
	limit=$3
	outstanding=$4

	avg=0
	# echo "- ${BLUE}$tests Random tests with $max elements${NC}"
	echo "- ${BLUE}$max elements${NC} ($tests tests)"
	i=0;
	for i in $(seq 1 $tests); do
		input=$(ruby -e "puts (1..$max).to_a.shuffle.join(' ')")

		$executable $input | $checker $input 2> error.tmp > success.tmp
		check=$(cat success.tmp)
		fail=$(cat error.tmp)
		rm -f error.tmp success.tmp
		if [ ! "$check" = "OK" ]; then
			echo " ${RED}[Not sorted]${NC}"
			echo "$executable $input | pbcopy"
			echo "$executable $input | $checker $input"
			echo "$visualizer $input"
			echo "Fail error: $fail"
			return 1
		fi

		n_steps=$($executable $input | wc -l | xargs)
		avg=$(($avg + $n_steps))
	done
	avg=$(($avg / $tests))
	
	echo "  - Average: ${YELLOW}$avg${NC} moves \c"
	
	if [ $limit -lt 0 ]; then
		getRange $avg "$outstanding"
	else
		if [ $avg -gt $limit ]; then
			echo "${RED}[KO]${NC} -> $avg/$limit steps"
		else
			if [ ! "$outstanding" = "" ] && [ $outstanding -ge $avg ]; then
				echo "${GREEN}[Outstanding]${NC}"
			else
				echo "${GREEN}[OK]${NC}"
			fi
		fi
	fi
	return $avg
}

getRange() {
	value=$1
	range=$2

	max=0
	for v in $range; do
		max=$(($max + 1))
	done

	i=$max
	prev="0"
	for v in $range; do
		if [ $value -lt $v ]; then
			echo "-> ${GREEN}$i${NC}/$max ${GREEN}[OK]${NC} (${YELLOW}$prev${NC} - ${YELLOW}$v${NC})"
			return
		fi
		i=$(($i - 1))
		prev="$v"
	done
	echo "${RED}[KO] -> more than $v${NC}"
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

	# file_test "${repo_location}.test/input_3elements" 3 2
	file_test "${repo_location}.test/input_5elements" 12 8
	# random_test 20 5  12 8
	# if [ "$1" == "--full" ]; then
	# 	random_test 20 4  12 8
	# 	random_test 20 6  12 8
	# fi
	random_test 20 100 -1 "700 900 1100 1300 1500"
	# if [ "$1" == "--full" ]; then
	# 	random_test 10 99 -1 "700 900 1100 1300 1500"
	# 	random_test 10 101 -1 "700 900 1100 1300 1500"
	# fi
	random_test 20 500 -1 "5500 7000 8500 100000 11500"
	# if [ "$1" == "--full" ]; then
	# 	random_test 20 499 -1 "5500 7000 8500 100000 11500"
	# 	random_test 20 501 -1 "5500 7000 8500 100000 11500"
	# fi
}

trap "rm -f error.tmp success.tmp; return" 2
main $@