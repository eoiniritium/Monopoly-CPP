default:
	g++ main.cpp -o main.exe -O2 --static -static-libgcc -static-libstdc++ -Wall -Wno-missing-braces -I include/raylib/include -L include/raylib/lib/ -lraylib -lopengl32 -lgdi32 -lwinmm -I include -L include
	./main.exe

compile:
	g++ main.cpp -o main.exe -O2 --static -static-libgcc -static-libstdc++ -Wall -Wno-missing-braces -I include/raylib/include -L include/raylib/lib/ -lraylib -lopengl32 -lgdi32 -lwinmm -I include -L include

run:
	./main.exe

darwin:
	g++ main.cpp `pkg-config --libs --cflags raylib` -o main.exe -O2 --static -static-libgcc -static-libstdc++ -Wall -Wno-missing-braces -I include -L include -Wc++11-extensions