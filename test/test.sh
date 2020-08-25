for((i = 1; ; i++)); do
	echo $i
	./gen $i > IN
	./a < IN > out1
	./brute < IN > out2
	diff -w out1 out2 || break
done
