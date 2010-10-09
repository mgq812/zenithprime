obj/BattleBoard.o : $(VIEW_INC)$(SLASH)BattleBoard.h $(VIEW_SRC)$(SLASH)BattleBoard.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)BattleBoard.o $(VIEW_SRC)$(SLASH)BattleBoard.cpp -I$(ALL_INC)
	@echo BattleBoard Built

obj/OBJloader.o :  $(LOADER_INC)$(SLASH)OBJloader.h $(LOADER_INC)$(SLASH)OBJloader.cpp obj/OBJModel.o
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)OBJloader.o $(LOADER_SRC)$(SLASH)OBJloader.cpp -I$(ALL_INC)