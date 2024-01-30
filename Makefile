project = StrategyPattern

create:
	cmake -B build -DPROJECT_NAME=$(project)

run:
	@./build/$(project)

all: create
	cmake --build build

clean:
	@echo "Clean up"
	@rm -rf build

.PHONY: create, check, all, clean