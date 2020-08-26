include ./config_host.mak

TARGET := ut

all:$(TARGET)

common-subdir = random-generator \
								tools
ut-only-subdir = unit-tests

common:
	test -d $(OBJ_DIR)/$@ || mkdir -p $(OBJ_DIR)/$@
	for dir in $(common-subdir) ; do \
		make -C $$dir; \
	done

ut-only:
	test -d $(OBJ_DIR)/$@ || mkdir -p $(OBJ_DIR)/$@
	for dir in $(ut-only-subdir) ; do \
		make -C $$dir; \
	done

distorm-32: distorm/src/*.c
	make -f Makefile.distorm

ut:common ut-only distorm-32
	$(CC) $(CFLAGS) $(OBJ_DIR)/common/*.o $(OBJ_DIR)/ut-only/*.o -L$(LIB_DIR) -ldistorm3 -o ut

clean:
	/bin/rm -rf ut
	/bin/rm -rf $(OBJ_DIR)/*.o
	/bin/rm -rf $(OBJ_DIR)/common/*.o
	/bin/rm -rf $(OBJ_DIR)/ut-only/*.o
	/bin/rm -rf $(LIB_DIR)/{*.a}
	make -f Makefile.distorm clean

.PHONY: all clean
