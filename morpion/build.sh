g++ -c morpion.cc `pkg-config --libs --cflags  gtkmm-3.0`
g++ -o main main.cc morpion.o `pkg-config --libs --cflags gtkmm-3.0`
./main