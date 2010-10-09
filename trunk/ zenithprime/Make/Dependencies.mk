# VIEW OBJECT FILES
obj$(SLASH)BattleBoard.o : $(VIEW_INC)$(SLASH)BattleBoard.h $(VIEW_SRC)$(SLASH)BattleBoard.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)BattleBoard.o $(VIEW_SRC)$(SLASH)BattleBoard.cpp $(ALL_INC)
	@echo BattleBoard Built

# LOADER OBJECT FILES
obj$(SLASH)OBJloader.o :  $(LOADER_INC)$(SLASH)OBJloader.h $(LOADER_SRC)$(SLASH)OBJloader.cpp obj$(SLASH)OBJModel.o $(MATH_OBJ)
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)OBJloader.o $(LOADER_SRC)$(SLASH)OBJloader.cpp $(ALL_INC)
	@echo OBJloader Built
	
obj$(SLASH)OBJModel.o :  $(LOADER_INC)$(SLASH)OBJModel.h $(LOADER_SRC)$(SLASH)OBJModel.cpp $(MATH_OBJ)
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)OBJModel.o $(LOADER_SRC)$(SLASH)OBJModel.cpp $(ALL_INC)
	@echo OBJModel Built
	
# DEVICE OBJECT FILES
obj$(SLASH)Mouse.o : $(DEVICE_INC)$(SLASH)Mouse.h $(DEVICE_SRC)$(SLASH)Mouse.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)Mouse.o $(DEVICE_SRC)$(SLASH)Mouse.cpp $(ALL_INC)
	@echo Mouse Built
	
obj$(SLASH)Keyboard.o : $(DEVICE_INC)$(SLASH)Keyboard.h $(DEVICE_SRC)$(SLASH)Keyboard.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)Keyboard.o $(DEVICE_SRC)$(SLASH)Keyboard.cpp $(ALL_INC)
	@echo Keyboard Built

# MATH OBJECT FILES
obj$(SLASH)Vector3.o : $(MATH_INC)$(SLASH)Vector3.h $(MATH_SRC)$(SLASH)Vector3.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)Vector3.o $(MATH_SRC)$(SLASH)Vector3.cpp $(ALL_INC)
	@echo Vector3 Built

obj$(SLASH)Vector2.o : $(MATH_INC)$(SLASH)Vector2.h $(MATH_SRC)$(SLASH)Vector2.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)Vector2.o $(MATH_SRC)$(SLASH)Vector2.cpp $(ALL_INC)
	@echo Vector2 Built
	
obj$(SLASH)int3.o : $(MATH_INC)$(SLASH)int3.h $(MATH_SRC)$(SLASH)int3.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)int3.o $(MATH_SRC)$(SLASH)int3.cpp $(ALL_INC)
	@echo int3 Built
		
obj$(SLASH)Face.o : $(MATH_INC)$(SLASH)Face.h $(MATH_SRC)$(SLASH)Face.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)Face.o $(MATH_SRC)$(SLASH)Face.cpp $(ALL_INC)
	@echo Face Built	
	
obj$(SLASH)Matrix.o : $(MATH_INC)$(SLASH)Matrix.h $(MATH_SRC)$(SLASH)Matrix.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)Matrix.o $(MATH_SRC)$(SLASH)Matrix.cpp $(ALL_INC)
	@echo Matrix Built