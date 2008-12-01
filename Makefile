#############################################################################
# Makefile for building: QtView
# Generated by qmake (2.01a) (Qt 4.4.3) on: Mon Dec 1 15:22:21 2008
# Project:  QtView.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.4.3/bin/qmake -unix CONFIG+=debug_and_release -o Makefile QtView.pro
#############################################################################

first: release
install: release-install
uninstall: release-uninstall
MAKEFILE      = Makefile
QMAKE         = /usr/local/Trolltech/Qt-4.4.3/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		release \
		debug

release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: QtView.pro  /usr/local/Trolltech/Qt-4.4.3/mkspecs/linux-g++/qmake.conf /usr/local/Trolltech/Qt-4.4.3/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/debug_and_release.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.4.3/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.4.3/lib/libQtCore.prl
	$(QMAKE) -unix CONFIG+=debug_and_release -o Makefile QtView.pro
/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/g++.conf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/release.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/debug_and_release.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.4.3/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.4.3/lib/libQtCore.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -unix CONFIG+=debug_and_release -o Makefile QtView.pro

qmake_all: FORCE

make_default: release-make_default debug-make_default FORCE
make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile

release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
