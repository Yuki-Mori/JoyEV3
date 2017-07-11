#!/bin/bash
if test $# -lt 1
then
	echo Class name is not specified
else
	CRDATE=`date '+%Y/%m/%d'`
	echo "/*" >> $1.h
	echo " * File:   $1.h" >> $1.h
	echo " * Author: Yuki Mori" >> $1.h
	echo " *" >> $1.h
	echo " * Created on ${CRDATE}" >> $1.h
	echo " */" >> $1.h
	
	echo "/*" >> $1.cpp
	echo " * File:   $1.cpp" >> $1.cpp
	echo " * Author: Yuki Mori" >> $1.cpp
	echo " *" >> $1.cpp
	echo " * Created on ${CRDATE}" >> $1.cpp
	echo " */" >> $1.cpp
fi