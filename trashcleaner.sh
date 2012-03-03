#!/bin/bash
#Program:
#	To automatically remove the bin files and object file in Mingorithm.
#Warning:
#	DO NOT change the location of this script in case of removing unexpected files.
#History:
#	2012/02/20	Ming	First release
function startclear {
	echo "Cleaning $(pwd)"
	echo *.o
	for var in $(ls)
	do
		if [ -d $var ]; then
			#echo "$var is a directory."
			cd $var
			startclear
			cd ..
		elif [ "$var" == "trashcleaner.sh" ]; then
			continue
		elif [ -x $var ] && [ ! "$var" == "*.py" ]; then
			echo "$var is a binary file, remove it!"
			rm $var
		elif [ "$var" == "*.o" ]; then
			echo "$var is an object file, remove it!"
			#rm $var
		fi
	done
}
startclear

