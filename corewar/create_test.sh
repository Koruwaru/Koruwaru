namesize=`print $1 | wc -c`
commentsize=`print $2 | wc -c`
datasize=`printf $3 | wc -c`
#datasizebin=`printf "0: %.8x" $datasize | sed -E 's/0: (..)(..)(..)(..)/0: \4\3\2\1/' | xxd -r -g0`
file=$4

write_zeros() {
	size=`printf $1 | wc -c`
	dd if=/dev/zero bs=1 count=$(($2 - $size)) >> $3
}

write_magick() {
#	python -c "print '\xf3\x83\xae'" > $1
#	sed -i '$s/.$//' $1
	dd if=/dev/zero bs=1 count=1 > $1
	printf '\xea\x83\xf3' >> $1
}

echo $namesize $commentsize $datasize
write_magick $file
printf $1 >> $file ; write_zeros $1 128 $file
printf "0: %.8x" $datasize | xxd -r -g0 >> $file
printf "CACA %s %d : " $3 datasize
printf "0: %.8x" $datasize
printf "\n"
printf $2 >> $file ; write_zeros $2 2048 $file
printf $3 >> $file
