echo "2018001 Yash 8" | cat>Students.txt
echo "2018002 Smriti 9" | cat>>Students.txt
echo "2018003 Sammer 7" | cat>>Students.txt
echo "2018004 Avani 10" | cat>>Students.txt

echo "2018005 Akash 6" | cat>>Students.txt
echo "2018006 Mayank 8" | cat>>Students.txt

wc -l Students.txt | cut -d ' ' -f 1 | cat>first.txt

a=`cut -d ' ' -f 3 Students.txt | sort -run | head -2 | tail -1`
grep " $a" Students.txt | cat>second.txt

touch third.txt
cut -d ' ' -f 2 Students.txt | grep "A" | cat>temp.txt
sort -u temp.txt | cat>sort.txt
while read name
do
	grep $name Students.txt | cat>>third.txt
done < sort.txt
cut -d ' ' -f 2 Students.txt | grep "H" | cat>temp.txt
sort -u temp.txt | cat>sort.txt
while read name
do
	grep $name Students.txt | cat>>third.txt
done < sort.txt
