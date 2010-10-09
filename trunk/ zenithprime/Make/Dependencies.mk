obj/BattleBoard.o : $(VIEW_INC)$(SLASH)BattleBoard.h $(VIEW_SRC)$(SLASH)BattleBoard.cpp
	@gcc $(COMP_FLAGS) -c -o obj$(SLASH)BattleBoard.o $(VIEW_SRC)$(SLASH)BattleBoard.cpp -I$(ALL_INC)
	@echo BattleBoard Built
