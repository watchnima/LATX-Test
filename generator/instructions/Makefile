include ../../config_host.mak

obj := gen-insn.o \
			 gen-prefix.o \
			 gen-opcode.o \
			 gen-operands.o

all: $(obj)

$(obj):%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE_DIR) -o $(OBJ_DIR)/common/$@
