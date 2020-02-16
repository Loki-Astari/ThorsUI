THORSANVIL_ROOT             = $(realpath ../../)

WX_INCLUDE                  = $(shell wx-config --cxxflags)
WX_LINK                     = $(shell wx-config --libs)

TARGET                      = ThorsUI.slib

FILE_WARNING_FLAGS          = -Wno-ignored-qualifiers -Wno-unknown-pragmas
CXXFLAGS                    += $(WX_INCLUDE)
LDFLAGS                     += $(WX_LINK)

include $(THORSANVIL_ROOT)/build/tools/Makefile
