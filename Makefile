includeDir=./include
bin=./bin/nyx
files=./cli.c ./main.c ./nyx_err.c

build:
	mkdir bin
	gcc -o ${bin} -lsodium -I ${includeDir} ${files}