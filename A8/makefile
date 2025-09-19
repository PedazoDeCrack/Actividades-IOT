# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -Wextra -std=c11

# Ejecutables
READER = reader
WRITER = writer

# Archivos fuente
READER_SRC = read.c
WRITER_SRC = write.c

# Regla por defecto
all: $(READER) $(WRITER)

# Compilar reader
$(READER): $(READER_SRC)
	$(CC) $(CFLAGS) -o $(READER) $(READER_SRC)

# Compilar writer
$(WRITER): $(WRITER_SRC)
	$(CC) $(CFLAGS) -o $(WRITER) $(WRITER_SRC)

# Limpiar archivos generados
clean:
	rm -f $(READER) $(WRITER)
