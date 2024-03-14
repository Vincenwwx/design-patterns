all: create
	cmake --build build

create:
	cmake -D -B build

clean:
	@echo "Clean up..."
	@rm -rf build