rm result.txt
touch result.txt
for file in `ls maps`
do
	echo $file >> result.txt
	./cub3D maps/$file >> result.txt
	sleep 0.2
	echo >> result.txt
	echo ============ >> result.txt
done