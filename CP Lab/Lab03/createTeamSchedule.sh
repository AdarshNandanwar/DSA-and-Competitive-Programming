cut -d ',' -f 3 worldCup.txt | cut -d ' ' -f 1 | cat > c.txt
sort -u c.txt | cat > sort.txt
while read line
do
	grep $line worldCup.txt | cat > $line.txt
done < sort.txt
