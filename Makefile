MKDIR = mkdir -p --

DAYS = $(shell find . -maxdepth 1 -type d -name '[0-9][0-9]')

.PHONY: all clean new

all:
	(for i in $(DAYS); do (pushd "$$i"; $(MAKE)); done)

clean:
	(for i in $(DAYS); do $(MAKE) -C $$i clean; done)

new:
	$(MKDIR) $(NEXT)
	cp base/mk $(NEXT)/Makefile
	cp base/cxx $(NEXT)/01.cxx
	cp base/hxx $(NEXT)/common.hxx

$(V).SILENT:
