TARGET=Electronics
OBJECTS=main.o Electronics.o

CXX=g++

SLURM_FLAGS=--partition=cfds --nodes=1 --ntasks-per-node=1 --time=5 --cpus-per-task=1 --mem=1G

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS)

clean:
	rm -rf $(TARGET) $(OBJECTS)

test: $(TARGET)
	salloc $(SLURM_FLAGS) ./$(TARGET)
