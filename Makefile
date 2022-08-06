CC := gcc
LD := gcc

CFLAGS := -Wall -Wextra -Werror -g -pedantic
LDFLAGS :=
CPPFLAGS := `pkg-config --cflags sdl` -MMD
LDLIBS := -lcriterion -lm `pkg-config --libs sdl SDL_image`

LDFLAGS += -fsanitize=address
CFLAGS += -fsanitize=address


BUILD := build
TARGET := c-test


C_FILES := $(shell find src/utils src/ tests/ -type f -name "*.c")
O_FILES := $(C_FILES:%.c=$(BUILD)/%.o)
D_FILES := $(O_FILES:%.o=%.d)


SRCDIRS := $(shell find src/utils src/ tests/ -type d)
$(shell mkdir -p $(SRCDIRS:%=$(BUILD)/%))

all: $(TARGET)
    

run-test: $(TARGET)
	./$(TARGET)


format-check-c:
	clang-format $(C_FILES)

clean:
	${RM} -rf $(BUILD) $(TARGET)

.PHONY: all clean run-test


$(TARGET): $(O_FILES)
	$(LD) $(LDFLAGS) $(LDLIBS) -o $@ $^

$(BUILD)/%.o: ./%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<


-include $(D_FILES)
