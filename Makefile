DEFAULT_GOAL := all

all: grep sort
grep: grep/main.cpp
	g++ ./grep/main.cpp -O2 -o ./build/grep.exe
sort: sort/main.cpp
	g++ ./sort/main.cpp -O2 -o ./build/sort.exe
