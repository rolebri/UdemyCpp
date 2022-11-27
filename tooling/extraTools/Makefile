DEBUG_FLAGS = -g3 -ggdb3 -O0 -std=c++20
RELEASE_FLAGS = -DNDEBUG -O3 -std=c++20
WARNING_FLAGS = -Wall -Wpedantic -Wshadow
SANITIZER_FLAGS = -fsanitize=address
ANALYZER_FLAGS = -fanalyzer

FLAGS = $(DEBUG_FLAGS) $(WARNING_FLAGS) $(SANITIZER_FLAGS) $(ANALYZER_FLAGS)

build:
	g++ $(FLAGS) Main.cc -o Main

run:
	env ASAN_OPTIONS="detect_leaks=1" ./Main
