arm-none-eabi-objdump -t "$1" | grep "$2$" | awk '{print $1;}' | tr -d '\n' # Print address of label $2
