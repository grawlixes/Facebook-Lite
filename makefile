# "make" - build the program
# "./FBL" - run the program after comp/link
# "make clean" - remove everything except source files

all : FBL

FBL : main.o FBLUser.o FBLUserLL.o FBLPostLL.o FBLPost.o FBLComment.o FBLCommentLL.o
	g++ FBLComment.o FBLCommentLL.o FBLUserLL.o FBLPost.o FBLPostLL.o FBLUser.o  main.o -o  FBL

FBLUser.o : FBLUser.cpp
	g++ -c FBLUser.cpp -g

FBLUserLL.o : FBLUserLL.cpp
	g++ -c FBLUserLL.cpp -g

FBLPost.o : FBLPost.cpp
	g++ -c FBLPost.cpp -g

FBLPostLL.o : FBLPostLL.cpp
	g++ -c FBLPostLL.cpp -g

FBLComment.o : FBLComment.cpp
	g++ -c FBLComment.cpp -g

FBLCommentLL.o : FBLCommentLL.cpp
	g++ -c FBLCommentLL.cpp -g

main.o : main.cpp
	g++ -c main.cpp -g

clean :
	rm -f *.o FBL
