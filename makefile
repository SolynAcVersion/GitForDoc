CXX      = g++
CXXFLAGS = -std=c++17 -I. -I./include -I./minizip
LDFLAGS  = -ljsoncpp -lz -fpermissive  -Wwrite-strings

SRCS = g4d.cpp src/ylfile.cpp \
       minizip/ioapi.c \
       minizip/mztools.c \
       minizip/unzip.c \
       minizip/zip.c

TARGET = g4d

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)
