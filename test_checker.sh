#!/bin/sh

# Colors:
NC='\033[0m' # No Color
RED='\033[1;31m';
YELLOW='\033[1;33m';
GREEN='\033[1;32m';
BLUE='\033[1;34m';

test_location=".test/bonus/"
test_input_prefix="${test_location}input_"
test_output_prefix="${test_location}result_"
test="basic"

for t in $(echo $test); do
	i=1;
	while IFS= read -r input; do
		echo "- ${BLUE}${t}_${i}${NC}\c"
		spectedResult=${test_output_prefix}${t}_$i
		if [ $i -lt 10 ]; then
			spectedResult=${test_output_prefix}${t}_0$i
		fi
		cat $spectedResult | ./checker $input
		echo " ${GREEN}[OK]${NC}"
		i=$((i + 1))
	done < "$test_input_prefix$t"
done