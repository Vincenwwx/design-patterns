create:
	cmake -B build

build: create
	cmake --build build

test:
	./build/IteratorPattern

clean:
	@echo "Clean up"
	@rm -rf build