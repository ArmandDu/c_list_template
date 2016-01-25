##
## Makefile for wolf3d
## 
## Made by ArmandDu


TEST_MAKEFILE=	./test/


all:
	@echo "no all"

test:
	@make -C$(TEST_MAKEFILE)

clean:
	make -C$(TEST_MAKEFILE) clean

fclean:
	make -C$(TEST_MAKEFILE) fclean

.PHONY: test
