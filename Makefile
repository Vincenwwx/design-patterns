create:
	cmake -B build

build: create
	cmake --build build

test:
	./build/FactoryPattern

clean:
	@echo "Clean up"
	@rm -rf build