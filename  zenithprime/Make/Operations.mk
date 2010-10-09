
#Clean
clean:
	@$(DELETE) $(SILENT) obj$(SLASH)*.*
	@$(DELETE) $(SILENT) bin$(SLASH)*
	@echo CLEANED

#Default Build of Excutable
build:
	@SOMEONE SET US UP THE BOMB
		
#Execute
run:
	@echo ALL YOUR BASE ARE BELONG TO US



#TESTING

#All Testing	
test: BattleBoard_test DeviceTest LoaderTest
	@echo ALL TESTS COMPLETE

BattleBoard_test: obj$(SLASH)BattleBoard.o
	@echo TESTING BattleBoard

DeviceTest: obj$(SLASH)Mouse.o obj$(SLASH)Keyboard.o
	@echo TESTING Devices

LoaderTest: obj$(SLASH)OBJloader.o obj$(SLASH)OBJModel.o
	@echo TESTING Loaders