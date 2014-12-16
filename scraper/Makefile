TARGETS=weather
CC=gcc
LIBS=-lcurl -lrt
CFLAGS=-I/usr/include/mysql -DBIG_JOINS=1 -fno-strict-aliasing -g -DNDEBUG  
MYSQLLIBS=-L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl



all: $(TARGETS)

weather: main.o scraper.o temperature.o locationId.o humidity.o checkSql.o sqlQuery.o toCentigrade.o writequeue.o filter.o
	$(CC) -o  $@ $(CFLAGS) $^ $(LIBS) $(MYSQLLIBS)  
test: weather
	./weather -c Argentina -s Mendoza
clean:
	rm -f weather *.o
