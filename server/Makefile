TARGETS=server
CC=gcc
LIBS=-lcurl 
CFLAGS=-I/usr/include/mysql -DBIG_JOINS=1 -fno-strict-aliasing -g -DNDEBUG  
MYSQLLIBS=-L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl


all: $(TARGETS)

server: checkSql.o sqlQuery.o doprocessing.o server2.o sockparser.o serverlog.o clientlog.o filter.o
	$(CC) -o  $@ $(CFLAGS) $^ $(LIBS) $(MYSQLLIBS)  
test: server
	./server -c port.conf 
clean:
	rm -f server *.o
