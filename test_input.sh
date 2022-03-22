#!/bin/bash

executable=./ft_pushswap

run_test() {
	./ft_pushswap $@
}

input="test/invalid_input"
while IFS= read -r line; do
	run_test $line
done < "$input"

