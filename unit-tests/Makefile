include ../config_host.mak

SUB_DIR := insn

obj = ut-main.o
unit-tests-obj += $(obj)

all: $(obj)
	for subdir in $(SUB_DIR); do \
		make -C $$subdir; \
	done

$(obj):%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE_DIR) -o $(OBJ_DIR)/ut-only/$@
