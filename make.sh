#!/bin/bash
export gtksrc=$1
export gtkpro=`basename $1 .c`pro
if [ "$1" != "clean" ];then
	make
else
	make clean
fi
