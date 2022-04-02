#!/bin/sh

# Colors:
NC='\033[0m' # No Color
RED='\033[1;31m';
YELLOW='\033[1;33m';
GREEN='\033[1;32m';
BLUE='\033[1;34m';

executable=./push_swap

make fclean
make DEBUG=

make bonus

test() {
	name="$1"
	input="$2"
	max=$3
	outstanding=$4

	echo "- ${BLUE}$name${NC} \c"
	steps=$($executable $input)
	echo $steps | ./checker $input 2> error.tmp > success.tmp
	check=$(cat success.tmp)
	echo "'$check'"
	fail=$(cat error.tmp)
	echo "'$fail'"
	rm -f error.tmp success.tmp
	if [ ! "$check" = "OK" ]; then
		echo " ${RED}[FAIL]${NC}"
		echo "$executable $input"
		echo "$executable $input | ./checker $input"
		return
	fi
	n_steps=$(echo $steps | wc -l)
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


test "basic" "1 3 2" 3 2

# test "Simple" "1 5 2 4 3" 12 8