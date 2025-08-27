DEFAULT_GOAL := all

all: grep
grep: grep/main.cpp
	g++ ./grep/main.cpp -O2 -o ./build/grep.exe
