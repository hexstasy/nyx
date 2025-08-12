includeDir=./include
bin=./bin/nyx
files=./cli.c ./main.c ./nyx_err.c ./create_point.c

build:
	mkdir -p bin
	gcc -o ${bin} -lsodium -I ${includeDir} ${files}