CC := gcc
CFLAGS := -Wall

LIB_DIR := lib
TEST_DIR := test
TEST_EXE := test
BUILD_DIR := build

INCLUDES := $(addprefix -I./,$(wildcard $(LIB_DIR)/*))

TEST_OBJS := $(notdir $(wildcard $(LIB_DIR)/*/*.c) $(wildcard $(TEST_DIR)/*.c))
TEST_OBJS := $(addprefix $(BUILD_DIR)/,$(TEST_OBJS:.c=.o))

PROG_OBJS := $(notdir $(wildcard $(LIB_DIR)/buffer/*.c)
PROG_OBJS := $(addprefix $(BUILD_DIR)/,$(PROG_OBJS:.c=.o))

all: .mkbuild $(PROG_EXE) $(TEST_EXE)
	@echo "************ The Targets ************"
	@echo "** clean: to clean"
	@echo "** check: to run the test"
	@echo "** run NUM=xxx: to run the program"
	@echo "*************************************"

$(PROG_EXE): $(PROG_OBJS)
	$(CC) $^ -lm -o $(BUILD_DIR)/$@

$(TEST_EXE): $(TEST_OBJS)
	$(CC) $^ -lm -o $(BUILD_DIR)/$@

LIB_SRC := $(LIB_DIR)/*
$(BUILD_DIR)/%.o: $(LIB_SRC)/%.c
	$(CC) -MMD $(CFLAGS) -o $@ -c $<

$(BUILD_DIR)/%.o : $(TEST_DIR)/%.c
	$(CC) -MMD $(CFLAGS) -o $@ $(INCLUDES) -c $<

run: .mkbuild $(PROG_EXE)
	@echo ""
	@echo "**************************************"
	@echo "********* Run The Program ************"
	@echo "**************************************"
	@echo ""
	@./$(BUILD_DIR)/$(PROG_EXE) $(NUM)

check: .mkbuild $(TEST_DIR)
	@echo ""
	@echo "**************************************"
	@echo "********** Run The Test **************"
	@echo "**************************************"
	@echo ""
	@./$(BUILD_DIR)/$(TEST_EXE)

-include $(OBJECTS:.o=.d)

.PHONY: clean .mkbuild check all

clean:
	@rm -rf $(BUILD_DIR)

.mkbuild:
	@mkdir -p $(BUILD_DIR)