#
#
# date: 2019/11/28
# authors: Roger Shanahan

# all: polynomial

all: polynomial
		./polynomial		

polynomial: assignment.h assignment.c assignmentMain.c
		gcc -Wall -ggdb -std=c11 -o $@ $^

clean:
		rm -f polynomial *.o *~ *#

