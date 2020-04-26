cut -d ' ' -f 2 Course_marks.txt > t1.txt
while read l
do
	if test $l==O 
	then
		echo "10"|cat>>m1.txt
	elif test $l==A
	then
		echo "5"|cat>>m1.txt
	elif test $l==E
	then
		echo "2"|cat>>m1.txt
	fi
done < t1.txt
