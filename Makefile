# CC = g++
# LD = g++

PATH_LIB = lib
PATH_SDL = $(PATH_LIB)/SDL

BIN = build
SRC = src
OBJ = obj
SRC_FILES = $(wildcard $(SRC)/*.cpp)
# SRC_FILES += $(wildcard $(SRC)/*.h)
OBJ_FILES = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRC_FILES))
OUT = $(BIN)/out

LDFLAGS = -lm
LDFLAGS += -lSDL2
LDFLAGS += -lSDL2_image


# lib-sdl:
	# mkdir -p $(BIN)/sdl
# 	cmake -S $(PATH_SDL) -B $(BIN)/sdl
# 	cd $(BIN)/sdl && make -j 10
# 	chmod +x $(BIN)/sdl/sdl2-config
# 	mkdir -p $(BIN)/lib
# 	cp $(BIN)/sdl/libSDL2.a $(BIN)/lib


# libs: lib-sdl

vectorsandbox: $(OBJ_FILES)
	echo "Start"
	g++ $(OBJ_FILES) $(LDFLAGS) -o $(OUT)
	# $@ $^
	# g++ $(SRC)/*.cpp -o $(BIN)/out $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp
	g++ -c -g -o $@ $<
