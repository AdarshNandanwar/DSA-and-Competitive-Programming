echo 'enter first number:'
read a
echo 'enter second number:'
read b
echo 'enter third number:'
read c
if test $a -gt $b -a $a -gt $c
then
	echo $a is the largest
else
	if [ $b -gt $c ]
	then
		echo $b is the largest
	else
		echo "$c is the largest"
	fi
fi
