#PROJETO EDB

PROG = funcionEAnalizer
CC = g++
CPPFLAGS = -O0 -g -W -Wall -std=c++11 -pedantic
OBJS = main.o linear_s_i.o binary_s_i.o binary_s_r.o ternary_s_i.o ternary_s_r.o
HEADER = ./include/header.h
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o $(BIN_DIR)

main.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)main.cpp

linear_s_i.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)linear_s_i.cpp

binary_s_i.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)binary_s_i.cpp

binary_s_r.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)binary_s_r.cpp

ternary_s_i.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)ternary_s_i.cpp

ternary_s_r.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)ternary_s_r.cpp
	
clean:
	rm -f $(BIN_DIR)*.o $(PROG)