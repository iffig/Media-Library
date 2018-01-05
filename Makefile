LIB = my_library.txt
OBJS = media_library.o Media.o Library.o Book.o Movie.o
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

Book.o: Book.cpp Book.h
	$(CC) $(CFLAGS) Book.cpp

Movie.o: Movie.cpp Movie.h
	$(CC) $(CFLAGS) Movie.cpp

clean:
	rm -rf *o media
