AC_INIT([UI], [0.1], [Loki.Astari@gmail.com])
AC_PREREQ([2.65])

# Set up the build system
if [[ ! -e build/Notes ]]; then
    git submodule init
    git submodule update
fi
AC_CONFIG_MACRO_DIR([build/autotools/m4])
AC_CONFIG_AUX_DIR([build/autotools/build])
AX_THOR_FUNC_BUILD


AC_CONFIG_SRCDIR([src/ThorsUI/Animateable.cpp])

# Find the C++ Copiler
# The minimumm requirements.
AC_PROG_CXX
AX_CHECK_COMPILE_FLAG([-ansi], [AC_SUBST([CXXFLAGS], ["-O3 -ansi"])])
# Check what version of the C++ language is supported
AX_THOR_FUNC_LANG_FLAG(17)

# Find the code coverage tool.
# All the testing will depend on this.
AX_THOR_PROG_COV

# Add support for shared libraries.
LT_INIT


#
# Add your defintions in here.
# Note there are some predefined macros in build/autotools/m4/
AC_CHECK_PROG(CHECK_WX_WIDGET, wx-config, yes)
AS_IF([test x"${CHECK_WX_WIDGET}" != x"yes"],
      [AC_MSG_ERROR([
This library depends on the development version of wxWidgets being installed.

Please check out https://www.wxwidgets.org/ and follow the instructions to download and install.

Current version can be installed with:

    > wget https://github.com/wxWidgets/wxWidgets/archive/v3.1.3.tar.gz
    > tar xvf v3.1.3.tar.gz
    > cd wxWidgets-3.1.3/
    > mkdir build-cocoa-debug
    > cd build-cocoa-debug
    > ../configure --enable-debug
    > make
    > sudo make install

])])



# Build all the Makefiles and configuration files.
# Used by ThorMaker
# Note: you can push the config file to sub directories in the AC_CONFIG_HEADERS macro (see example)
# Note: Local Make variables should be placed in Makefile.config.in
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_HEADERS([config.h src/ThorsUI/ThorsUIConfig.h:config.h.in])
AC_CONFIG_FILES([Makefile.extra Makefile.config:build/autotools/build/Makefile.config.in:Makefile.config.in])
AC_OUTPUT
