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

test_location="${repo_location}.test/"
test_input_prefix="${test_location}input_"
test_output_prefix="${test_location}bonus/result_"
test="basic 3elements"

pushswap=${repo_location}pushswap
checker=${repo_location}checker

make -C ${repo_location} bonus

for t in $(echo $test); do
	i=1;
	while IFS= read -r input; do
		echo "- ${BLUE}${t}_${i}${NC}\c"
		spectedResult=${test_output_prefix}${t}_$i
		if [ $i -lt 10 ]; then
			spectedResult=${test_output_prefix}${t}_0$i
		fi
		cat $spectedResult | $checker $input 2> error.tmp > success.tmp
		if [ "$(cat success.tmp)" = "OK" ]; then
			echo " ${GREEN}[OK]${NC}"
		else
			echo " ${RED}[FAIL]${NC}"
			cat error.tmp
			echo "-----------"
			echo "Test made:"
			echo "cat $spectedResult | ./checker $input"
		fi
		i=$((i + 1))
		rm -f error.tmp success.tmp
	done < "$test_input_prefix$t"
done
