include ../../config_host.mak

obj := test-arith.o \
			 code-cache.o
unit-tests-obj += $(obj)

all: $(obj)

$(obj):%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE_DIR) -o $(OBJ_DIR)/ut-only/$@
