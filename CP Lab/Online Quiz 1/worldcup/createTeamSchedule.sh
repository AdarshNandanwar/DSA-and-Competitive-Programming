cut -d ',' -f 3 worldCup.txt | cut -d ' ' -f 1 | sort -u | cat>list.txt
while read c
do
	grep $c worldCup.txt | cat>$c.txt
done < list.txt

