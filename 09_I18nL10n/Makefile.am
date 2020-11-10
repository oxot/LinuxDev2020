bin_PROGRAMS=guess
pkgdata_DATA=ru/LC_MESSAGES/guess.mo

ru/LC_MESSAGES/guess.mo: gueRu.po
		mkdir -p `dirname $@`
		msgfmt $< -o $@

gueRu.po:	gues.pot
		msgmerge -U $@ $<

gues.pot:	guess.pot guess.c
		xgettext -k_ -c guess.c -o guess.new.pot
		cp guess.pot gues.pot
		msgmerge -U gues.pot guess.new.pot

gitclean:	maintainer-clean
	git clean -fd