include ../config_host.mak

SUB_DIR := instructions

obj := generator.o

all: $(obj)
	for subdir in $(SUB_DIR); do \
		make -C $$subdir; \
	done

$(obj):%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE_DIR) -o $(OBJ_DIR)/common/$@
