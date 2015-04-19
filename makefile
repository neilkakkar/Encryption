.PHONY: all encrypt decrypt

all: encrypt decrypt

decrypt: matrix.o decryption.cpp
	g++ -o decrypt decryption.cpp matrix.o

encrypt: matrix.o encryption.cpp
	g++ -o encrypt encryption.cpp matrix.o

matrix.o: matrix.cpp 
	g++ -c matrix.cpp
