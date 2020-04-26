echo Enter a
read a
echo Enter b
read b
c=`expr $a \* $a + $b \* $b`
echo $c
echo Enter parameter
read p
echo `expr $c + $p`
