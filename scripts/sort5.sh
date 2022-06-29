#!/bin/bash

echo "running"
if [ -f ./scripts/tester.sh ]; then
	./scripts/tester.sh > result.tmp
else
	tester.sh > result.tmp
fi
echo "done"
echo "$(cat result.tmp)" &&

fail=$(cat result.tmp | grep FAIL | wc -l | xargs)
ko=$(cat result.tmp | grep KO | wc -l | xargs)
ok=$(cat result.tmp | grep OK | wc -l | xargs)
out=$(cat result.tmp | grep Out | wc -l | xargs)

echo "Fails: $fail  KOs: $ko  OKs: $ok  Outstanding: $out"
rm result.tmp
