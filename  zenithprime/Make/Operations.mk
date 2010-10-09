
#Clean
clean:
	@$(DELETE) $(SILENT) obj$(SLASH)*.*
	@$(DELETE) $(SILENT) bin$(SLASH)*
	@echo CLEANED

#Default Build of Excutable
bin:

		
#Execute
run:



#TESTING

#All Testing	
test: BattleBoard_test

BattleBoard_test: obj/BattleBoard.o
	@echo TESTING BattleBoard