ALL_INC = -I$(VIEW_INC) -I$(LOADER_INC) -I$(DEVICE_INC) -I$(MATH_INC)

VIEW_INC = inc$(SLASH)view
LOADER_INC = inc$(SLASH)loader
DEVICE_INC = inc$(SLASH)device
MATH_INC = inc$(SLASH)math

VIEW_SRC = src$(SLASH)view
LOADER_SRC = src$(SLASH)loader
DEVICE_SRC = src$(SLASH)device
MATH_SRC = src$(SLASH)math

VIEW_OBJ = obj$(SLASH)BattleBoard.o
LOADER_OBJ = obj$(SLASH)OBJloader.o obj$(SLASH)OBJModel.o
DEVICE_OBJ = obj$(SLASH)Mouse.o obj$(SLASH)Keyboard.o
MATH_OBJ = obj$(SLASH)Vector3.o obj$(SLASH)Vector2.o obj$(SLASH)int3.o obj$(SLASH)Face.o obj$(SLASH)Matrix.o