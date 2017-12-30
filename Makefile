LIB = my_library.txt
OBJS = media_library.o Media.o Library.o
CC = g++ -std=c++11
CFLAGS = -c -Wall

all: media

media: $(OBJS)
	$(CC) $(OBJS) -o media
	./media $(LIB)

media_library.o: media_library.cpp
	$(CC) $(CFLAGS) media_library.cpp

Media.o: Media.cpp Media.h
	$(CC) $(CFLAGS) Media.cpp

Library.o: Library.cpp Library.h
	$(CC) $(CFLAGS) Library.cpp

clean:
	rm -rf *o media
