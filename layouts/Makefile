VARIANTS=dvorak dvp dvorak-l dvorak-r colemak
DEFAULT=qwerty

KEYFILES=$(addprefix keys/, $(addsuffix .keys, $(VARIANTS) $(DEFAULT)))
CONFILES=$(addprefix conf/, $(addsuffix .edil.conf, $(VARIANTS)))

keys/%.keys: gen-xcodes
	@mkdir -p keys
	@./gen-xcodes.sh $@

gen-xcodes: gen-xcodes.c
	@echo Compiling gen-xcodes
	@gcc -g $< -o $@ -lX11 -lxcb -lX11-xcb

conf/%.edil.conf: keys/$(DEFAULT).keys keys/%.keys ../bin/edil
	@echo Generating $@
	@mkdir -p conf
	@../bin/edil --binds | ./gen-remap.py $< $(word 2,$^) > $@

all: $(CONFILES) $(KEYFILES)

clean:
	@rm gen-xcodes
	@echo Removed gen-xcodes
	@rm -f $(CONFILES)
	@echo Removed config files
	@rm -f $(KEYFILES)
	@echo Removed keys files

.DEFAULT_GOAL=all
.PHONEY=clean all