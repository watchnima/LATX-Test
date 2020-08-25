include ./config_host.mak

TARGET := ut

all:$(TARGET)

common-subdir = random-generator
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

ut:common ut-only
	$(CC) $(CFLAGS) -o ut $(OBJ_DIR)/common/*.o $(OBJ_DIR)/ut-only/*.o

clean:
	rm -rf obj/*.o
	rm -rf common/*.o
	rm -rf ut-only/*.o
	rm $(TARGET)

.PHONY: all clean
