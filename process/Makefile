TARGETS=queuetosql
CC=gcc
LIBS=-lcurl -lrt 
CFLAGS=-I/usr/include/mysql -DBIG_JOINS=1 -fno-strict-aliasing -g -DNDEBUG  
MYSQLLIBS=-L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl

#-L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl
#-I/usr/include/mysql -DBIG_JOINS=1 -fno-strict-aliasing -g -DNDEBUG



all: $(TARGETS)

queuetosql: main.o sqlQuery.o 
	$(CC) -o  $@ $(CFLAGS) $^ $(LIBS) $(MYSQLLIBS)  
test: queuetosql
	./queuetosql
clean:
	rm -f queuetosql *.o
