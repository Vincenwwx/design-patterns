project = VisitorPattern

all: create
	cmake --build build

create:
	cmake -B build -DPROJECT_NAME=$(project)

run:
	@./build/$(project)

clean:
	@echo "Clean up"
	@rm -rf build

.PHONY: create, check, all, clean