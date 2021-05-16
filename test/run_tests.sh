#!/bin/bash

for EXE in "$@"
do
	echo "Testing $EXE"
	$EXE
	exit_code=$?
	if [ $exit_code -ne 0 ];
	then
		echo "$EXE failed: return code $exit_code"
		exit $exit_code
	fi
done

