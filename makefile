.PHONY: build

build:
	g++ -I./include -o build/bin/but src/*.cpp
	set PATH=%PATH%;./build/bin/