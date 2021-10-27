main: main.cpp
	clang main.cpp -o main -lc++ -std=c++11 -lassimp -I/opt/homebrew/opt/assimp/include -L/opt/homebrew/opt/assimp/lib