# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
CC = g++
CFLAGS  = -g -Wall -std=c++11
LFLAGS  = -L/usr/lib

# All Targets
all: SPLFLIX

# Tool invocations
SPLFLIX: bin/BaseAction.o bin/ChangeActiveUser.o bin/CreateUser.o bin/DeleteUser.o bin/DuplicateUser.o bin/Exit.o bin/GenreRecommenderUser.o bin/LengthRecommenderUser.o bin/Main.o bin/PrintActionLog.o bin/PrintContentList.o bin/PrintWatchHistory.o bin/RerunRecommenderUser.o bin/Session.o bin/User.o bin/Watch.o bin/Watchable.o
	@echo 'Building target: SPLFLIX'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/splflix bin/BaseAction.o  bin/ChangeActiveUser.o  bin/CreateUser.o bin/DeleteUser.o  bin/DuplicateUser.o bin/Exit.o bin/GenreRecommenderUser.o bin/LengthRecommenderUser.o bin/Main.o bin/PrintActionLog.o bin/PrintContentList.o bin/PrintWatchHistory.o bin/RerunRecommenderUser.o bin/Session.o bin/User.o bin/Watch.o bin/Watchable.o  $(LFLAGS)
	@echo 'Finished building target: SPLFLIX'
	@echo ' '

bin/BaseAction.o: src/BaseAction.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/BaseAction.o src/BaseAction.cpp

bin/ChangeActiveUser.o: src/ChangeActiveUser.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/ChangeActiveUser.o src/ChangeActiveUser.cpp

bin/CreateUser.o: src/CreateUser.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/CreateUser.o src/CreateUser.cpp

bin/DeleteUser.o: src/DeleteUser.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/DeleteUser.o src/DeleteUser.cpp

bin/DuplicateUser.o: src/DuplicateUser.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/DuplicateUser.o src/DuplicateUser.cpp

bin/Exit.o: src/Exit.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Exit.o src/Exit.cpp

bin/GenreRecommenderUser.o: src/GenreRecommenderUser.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/GenreRecommenderUser.o src/GenreRecommenderUser.cpp

bin/LengthRecommenderUser.o: src/LengthRecommenderUser.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/LengthRecommenderUser.o src/LengthRecommenderUser.cpp

bin/Main.o: src/Main.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Main.o src/Main.cpp

bin/PrintActionLog.o: src/PrintActionLog.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/PrintActionLog.o src/PrintActionLog.cpp

bin/PrintContentList.o: src/PrintContentList.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/PrintContentList.o src/PrintContentList.cpp

bin/PrintWatchHistory.o: src/PrintWatchHistory.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/PrintWatchHistory.o src/PrintWatchHistory.cpp

bin/RerunRecommenderUser.o: src/RerunRecommenderUser.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/RerunRecommenderUser.o src/RerunRecommenderUser.cpp

bin/Session.o: src/Session.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Session.o src/Session.cpp

bin/User.o: src/User.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/User.o src/User.cpp

bin/Watch.o: src/Watch.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Watch.o src/Watch.cpp

bin/Watchable.o: src/Watchable.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Watchable.o src/Watchable.cpp

#Clean the build directory
clean: 
	rm -f bin/*
