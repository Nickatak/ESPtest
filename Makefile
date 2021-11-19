.PHONY: clean
clean:
	platformio run --target clean

.PHONY: build
build:
	platformio run

.PHONY: upload
upload:
	platformio run --target upload

.PHONY: monitor
monitor:
	platformio device monitor

