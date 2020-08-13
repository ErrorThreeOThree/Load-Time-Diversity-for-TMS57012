for var in "$@"
do
	if [ "$1" != "$var" ]; then
		if [ "$2" != "$var" ]; then
			printf ", "
		fi
		arm-none-eabi-size -A -d $1 | grep -Po "\\$var +[0-9]+ +([0-9]+)$"  | grep -Po "[0-9]+$" | tr -d '\n'
	fi
done
#
