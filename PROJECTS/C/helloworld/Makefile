CC = gcc
EXEC = ./main
SRC = main.c ./src/*.c

all: clean compile run

clean:
	@echo "Cleaning..."
	rm $(EXEC) || true

compile:
	@echo "Compiling..."
	$(CC) -o $(EXEC) $(SRC)

run:
	@echo "Running..."
	$(EXEC) | tee -a $(OUTPUT_FILE) $(IGNORE)
	@rm $(EXEC)
