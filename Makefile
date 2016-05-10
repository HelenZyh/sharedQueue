SER_BIN=shm_ser
CLI_BIN=shm_cli
SER_SRC=comm.cpp shm_ser.cpp
CLI_SRC=comm.cpp shm_cli.cpp

INCLUDE=-I./
CC=g++
FLAGS=-g

.PHONY:all
all:$(SER_BIN) $(CLI_BIN)

$(SER_BIN):$(SER_SRC)
	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)

$(CLI_BIN):$(CLI_SRC)
	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)

.PHONY:clean
clean:
	rm -f $(SER_BIN) $(CLI_BIN)
