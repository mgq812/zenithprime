#--------------------------------------------------------------------------------------------------
# OS Name Definitions
#--------------------------------------------------------------------------------------------------
CURRENT_OS = $(WINDOWS)
WINDOWS = Windows
LINUX = Linux

#--------------------------------------------------------------------------------------------------
# OS Specific Command Definitions
#--------------------------------------------------------------------------------------------------
ifeq ($(CURRENT_OS), $(WINDOWS))
	COMP_FLAGS =		$(WIN_COMP_FLAGS)
	COPY =				$(WIN_COPY)
	DELETE =			$(WIN_DELETE)
	DELETE_DIR =		$(WIN_DELETE_DIR)
	EXE =				$(WIN_EXE)
	MEMCHECK =			$(WIN_MEMCHECK)
	MKDIR =				$(WIN_MKDIR)
	SLASH =				$(WIN_SLASH)
	SILENT =			$(WIN_SILENT)
else
	COMP_FLAGS =		$(LINUX_COMP_FLAGS)
	COPY =				$(LINUX_COPY)
	DELETE =			$(LINUX_DELETE)
	DELETE_DIR =		$(LINUX_DELETE_DIR)
	EXE =				$(LINUX_EXE)
	MEMCHECK =			$(LINUX_MEMCHECK)
	MKDIR =				$(LINUX_MKDIR)
	SLASH =				$(LINUX_SLASH)
	SILENT =			$(LINUX_SILENT)
endif

BOTH_COMP_FLAGS =		-Wall -g

WIN_COMP_FLAGS =		$(BOTH_COMP_FLAGS)
WIN_COPY =				copy
WIN_DELETE =			del
WIN_DELETE_DIR =		rmdir /S /Q
WIN_EXE =				.exe
WIN_MKDIR =				mkdir
WIN_MEMCHECK =
WIN_SLASH =				\\
WIN_SILENT	=			/q

LINUX_COMP_FLAGS =		$(BOTH_COMP_FLAGS) -fPIC
LINUX_COPY =			cp --force
LINUX_DELETE =			rm
LINUX_DELETE_DIR =		rm -r
LINUX_EXE = 
LINUX_MKDIR =			mkdir
LINUX_MEMCHECK =		valgrind --leak-check=full --show-reachable=yes
LINUX_SLASH =			/
LINUX_SILENT =			-f