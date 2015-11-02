#!/bin/bash

COUNTER=0

while [ $COUNTER -lt 1024 ]
do
	wget http://localhost:8000/Makefile
	rm Makefile.1
	COUNTER=$[COUNTER + 1]
	sleep .1
done
