echo Enter a number
read n
if test $n -lt 2
then
	echo "n must be >=2"
	exit 1
fi
a=0
b=1
for ((i=2;i<=n;i++))
do
	c=`expr $a + $b`
	a=$b
	b=$c
done
echo $n $c | cat>>result
