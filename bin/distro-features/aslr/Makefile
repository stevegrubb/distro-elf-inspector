CFLAGS=-g -W -Wall -Wundef
LIBS=
CC=gcc

all:
	$(CC) $(CFLAGS) exec.c -o exec $(LIBS)
	$(CC) $(CFLAGS) heap.c -o heap $(LIBS)
	$(CC) $(CFLAGS) mmap.c -o mmap $(LIBS)
	$(CC) $(CFLAGS) so.c -o so $(LIBS)
	$(CC) $(CFLAGS) stack.c -o stack $(LIBS)
	$(CC) $(CFLAGS) -DPIE -fPIE exec.c -o pie-exec -pie $(LIBS)
	$(CC) $(CFLAGS) -DPIE -fPIE exec.c -o now-exec -pie -Wl,-z,relro -Wl,-z,now $(LIBS)
	$(CC) $(CFLAGS) -DPIE -fPIE so.c -o pie-so -pie $(LIBS)
	$(CC) $(CFLAGS) -DPIE -fPIE heap.c -o pie-heap -pie $(LIBS)
	$(CC) $(CFLAGS) -DPIE -fPIE stack.c -o pie-stack $(LIBS)
	$(CC) $(CFLAGS) -DPIE -fPIE mmap.c -o pie-mmap $(LIBS)

	$(CC) $(CFLAGS) bits.c -o bits $(LIBS)

clean:
	rm -f exec heap mmap so stack pie-exec pie-so pie-heap bits *.log *.o
	rm -f now-exec pie-stack pie-mmap
