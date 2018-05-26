#!/bin/sh

resultat=$(ifconfig | grep "inet " | cut -d ' ' -f2)

if [ "$resultat" = '' ]
then
	echo "Je suis perdu!"
else
	echo "$resultat"
fi
