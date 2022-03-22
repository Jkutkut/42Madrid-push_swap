#!/bin/sh

# Colors:
NC='\033[0m' # No Color
RED='\033[1;31m';
YELLOW='\033[1;33m';
GREEN='\033[1;32m';
BLUE='\033[1;34m';

executable=./ft_pushswap

run_test() {
	echo "$1"
	echo "./ft_pushswap $2 2> output.tmp"
	./ft_pushswap $2 2 | grep "Error" > output.tmp
	if [ ! "$(cat output.tmp)" = "" ]; then
		echo "Error"
	fi
	rm output.tmp
}

input_file="test/invalid_input"
while IFS= read -r line; do
	test_name=$(echo $line | cut -d: -f2)
	input=$(echo $line | cut -d: -f2)
	run_test $input
	# if [ "$(run_test $input)" = "Error" ]; then
	# 	echo "${GREEN}[OK]${NC}"
	# else
	# 	echo "${RED}[FAIL]${NC}"
	# fi
done < "$input_file"

