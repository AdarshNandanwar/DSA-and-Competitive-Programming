if [ $# -eq 0 ]
then
	echo "You must supply a value"
else
	if [ $1 -lt 0 -o $2 -lt 0 -o $3 -lt 0 ]
	then
		echo "Supply Positive Numbers"
	elif [ `expr $1 + $2` -gt $3 -a `expr $1 - $2` -lt $3 -a `expr $1 + $3` -gt $2 -a `expr $1 - $3` -lt $2 -a `expr $2 + $3` -gt $1 -a `expr $2 - $3` -lt $1 ]
	then
		echo "Valid Triangle"
		echo "Perimeter = `expr $1 + $2 + $3`"
		if [ $1 -eq $2 -a $1 -eq $3 ]
		then
			echo "Equilateral Triangle"
		elif [ $1 -eq $2 -o $1 -eq $3 -o $2 -eq $3 ]
		then
			echo "Isosceles Triangle"
		else
			echo "Scalene Triangle"
		fi
	else
		echo 'invalid values'
	fi
fi
