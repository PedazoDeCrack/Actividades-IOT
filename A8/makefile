CC = gcc
CFLAGS = -Wall -pthread -lrt
TARGETS = write_semaphore read_semaphore

all: $(TARGETS)

write_semaphore: write_semaphore.c common.h
	$(CC) $(CFLAGS) write_semaphore.c -o write_semaphore

read_semaphore: read_semaphore.c common.h
	$(CC) $(CFLAGS) read_semaphore.c -o read_semaphore

run: all
	@echo "Abriendo read_semaphore en una terminal..."
	gnome-terminal -- ./read_semaphore
	@echo "Abriendo write_semaphore en otra terminal..."
	gnome-terminal -- ./write_semaphore

clean:
	rm -f $(TARGETS)
