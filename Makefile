# CC = g++
# LD = g++

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

PATH_LIB = lib
PATH_SDL = $(PATH_LIB)/SDL

BIN = build
SRC = src
OBJ = obj
SRC_FILES = $(call rwildcard,$(SRC),*.cpp)
OBJ_FILES = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRC_FILES))
OUT = $(BIN)/out


TEST = test
TEST_OBJ = $(OBJ)/test
TEST_SRC = $(wildcard $(TEST)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST)/%.cpp,$(TEST_OBJ)/%.o,$(TEST_SRC))
TEST_OUT = $(BIN)/test

COMPFLAGS = -Wall
COMPFLAGS += -g

LDFLAGS = -lm
LDFLAGS += -lSDL2
LDFLAGS += -lSDL2_image



vectorsandbox: $(OBJ_FILES) dirs
	g++ -I$(SRC) $(OBJ_FILES) $(LDFLAGS) -o $(OUT)

$(OBJ)/%.o: $(SRC)/%.cpp
	mkdir -p $(dir $@)
	g++ -I$(SRC) -c $(COMPFLAGS) -o $@ $<

test: dirs $(TEST_OBJ_FILES) 
	g++ -I$(SRC) $(TEST_OBJ_FILES) $(LDFLAGS) -o $(TEST_OUT)
	echo $(TEST_SRC)

obj/test/%.o: $(TEST)/%.cpp
	g++ -I$(SRC) -c $(COMPFLAGS) -o $@ $<


dirs:
	mkdir -p $(BIN) $(OBJ) $(TEST_OBJ)



maketest:
	@echo TEST_OBJ: $(TEST_OBJ)
	@echo TEST_SRC $(TEST_SRC)
	@echo TEST_OBJ_FILES $(TEST_OBJ_FILES)
	@echo 
	@echo OBJ $(OBJ)
	@echo SRC $(SRC)



