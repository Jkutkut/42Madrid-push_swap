#!/bin/sh

# Colors:
NC='\033[0m' # No Color
RED='\033[1;31m';
YELLOW='\033[1;33m';
GREEN='\033[1;32m';
BLUE='\033[1;34m';

executable=./ft_pushswap

run_test() {
	echo "- ${BLUE}$1${NC} \c"
	./ft_pushswap $2 > /dev/null 2> output.tmp
	if [ ! "$(cat output.tmp)" = "" ]; then
		echo "${RED}[FAIL]${NC}"
		echo "  Replicate it with"
		echo "  ./ft_pushswap $2"
	else
		echo "${GREEN}[OK]${NC}"
	fi
	rm output.tmp
}

run_invalid_test() {
	echo "- ${BLUE}$1${NC} \c"
	./ft_pushswap $2 > /dev/null 2> output.tmp
	if [ ! "$(cat output.tmp)" = "" ]; then
		echo "${GREEN}[OK]${NC}"
	else
		echo "${RED}[FAIL]${NC}"
		echo "  Replicate it with"
		echo "  ./ft_pushswap $2"
	fi
	rm output.tmp
}

echo "${BLUE}
  _____                 _ _     _ 
 |_   _|               | (_)   | |
   | |  _ ____   ____ _| |_  __| |
   | | | '_ \ \ / / _' | | |/ _' |
  _| |_| | | \ V / (_| | | | (_| |
 |_____|_| |_|\_/ \__,_|_|_|\__,_|${NC}"

input_file="test/invalid_input"
while IFS= read -r line; do
	test_name=$(echo $line | cut -d: -f1)
	input=$(echo $line | cut -d: -f2)
	run_invalid_test "$test_name" "$input"
done < "$input_file"



echo "${BLUE}
 __      __   _ _     _ 
 \ \    / /  | (_)   | |
  \ \  / /_ _| |_  __| |
   \ \/ / _' | | |/ _' |
    \  / (_| | | | (_| |
     \/ \__,_|_|_|\__,_|${NC}"

input_file="test/valid_input"
while IFS= read -r line; do
	test_name=$(echo $line | cut -d: -f1)
	input=$(echo $line | cut -d: -f2)
	run_test "$test_name" "$input"
done < "$input_file"

