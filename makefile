#PROJETO EDB

PROG = funcionEAnalizer
CC = g++
CPPFLAGS = -O0 -g -W -Wall -std=c++11 -pedantic
OBJS = main.o linear_s_i.o binary_s_i.o binary_s_r.o ternary_s_i.o ternary_s_r.o jump_s.o fibonacci_s.o
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
	
jump_s.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)jump_s.cpp

fibonacci_s.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)fibonacci_s.cpp

clean:
	rm -f $(BIN_DIR)*.o $(PROG)