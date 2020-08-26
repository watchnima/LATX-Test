CC = $(shell which gcc)

LD = $(shell which ld)

CFLAGS = -m32 -g

SRC_PATH = /home/lawrence/Workspace/git/LATX-Test

OBJ_DIR = $(SRC_PATH)/obj

LIB_DIR = $(OBJ_DIR)/lib

INCLUDE_DIR = $(SRC_PATH)/include

# all objects list
random-generator-obj =
unit-tests-obj =
