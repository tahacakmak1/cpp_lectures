SOURCES := $(shell find lecture* -type f \( -name '*.cpp' -o -name '*.h' -o -name '*.c' \) -print)

format:
	clang-format -i -style=file $(SOURCES)

cleanup:
	find lecture* -type f \( -name '*.o' -o -name '*.s' -o -name 'out' \) -delete
	rm -rf build build-*
