all: create
	cmake --build build

create:
	cmake -B build

clean:
	@echo "Clean up..."
	@rm -rf build