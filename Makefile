##  _____   _____                    _       _
## /  __ \ |_   _|                  | |     | |
## | /  \/   | | ___ _ __ ___  _ __ | | __ _| |_ ___
## | |       | |/ _ \ '_ ` _ \| '_ \| |/ _` | __/ _ \
## | \__/\   | |  __/ | | | | | |_) | | (_| | ||  __/
##  \____/   \_/\___|_| |_| |_| .__/|_|\__,_|\__\___|
##                            | |
##                            |_|

.PHONY: help

help: ## Prints this help
	@grep -E '^([a-zA-Z_-]+:.*?)?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = "(^## |:.*?## )"}; {printf "\033[32m%-7s\033[34m %s\n", $$1, $$2}'

clean: ## Clean previous build
	@rm -rf build

build: ## Build artifact
	@mkdir -p build
	@cd build && cmake ..
	@$(MAKE) -C build

test: ## Run unit tests
	@$(MAKE) build
	@$(MAKE) -C build test

dev: ## Starts app on Docker tty
	@docker-compose -f docker-compose.yml build
	@docker-compose -f docker-compose.yml run --rm --name c_template -- app $(PARAMS)
