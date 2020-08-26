include ../config_host.mak

obj := distorm-helper.o \
			 insn-display.o

all:$(obj)

$(obj):%.o:%.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE_DIR) -o $(OBJ_DIR)/common/$@
