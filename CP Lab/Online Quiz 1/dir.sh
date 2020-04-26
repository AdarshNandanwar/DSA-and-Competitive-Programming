echo "Enter the string"
read str
n=`expr $(ls */| grep / | grep -c $str)`
if [ $n -eq 0 ]
then
echo "The entered string $str is not a directory under the current working
directory"
else
echo "The entered string $str is a directory under the current working directory"
fi
