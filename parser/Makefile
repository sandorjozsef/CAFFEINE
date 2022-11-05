ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

CC = g++
CCFLAGS = -g -Wall -std=c++20

SOURCES = main.cpp
SOURCES += parser.hpp
SOURCES += parser.cpp
SOURCES += parsable.hpp
SOURCES += caff_block.hpp
SOURCES += caff_block.cpp
SOURCES += caff.hpp
SOURCES += caff_header.hpp
SOURCES += caff_header.cpp
SOURCES += caff_credits.hpp
SOURCES += caff_credits.cpp
SOURCES += caff_animation.hpp
SOURCES += caff_animation.cpp
SOURCES += ciff.hpp
SOURCES += ciff.cpp

ifeq ($(detected_OS),Linux)

TARGET = parser.out
DEL = -rm

	# Turn on all warnings to help ensure the underlying code is secure.
PROTECTIONS = -Wextra

# Warn about uses of format functions that represent possible security problems.
PROTECTIONS += -Wformat-security

# Warn on unsign/sign conversion.
PROTECTIONS += -Wconversion -Wsign-conversion

# Compile for 64-bit to take max advantage of address space (important for ASLR; more virtual address space to chose from when randomising layout).
PROTECTIONS += -m64

# Stack smashing protection.
PROTECTIONS += -fstack-protector-all

# Defeats a class of attacks called stack clashing.
PROTECTIONS += -fstack-clash-protection

# Required to obtain the full security benefits of ASLR.
PROTECTIONS += -pie -fPIE

# Buffer overflow checks
PROTECTIONS += -D_FORTIFY_SOURCE=2

# RELRO marks various ELF memory sections read­only
PROTECTIONS += -Wl,-z,relro,-z,now

# Non-executable stack. 
PROTECTIONS += -Wl,-z,noexecstack

# Enable code instrumentation of control-flow transfers to increase program security by checking that target addresses of control-flow transfer instructions (such as indirect function call, function return, indirect jump) are valid. 
PROTECTIONS += -fcf-protection=full

ENABLE_ASLR = sudo sysctl -w kernel.randomize_va_space=2

else

TARGET = parser.exe
DEL = -del

endif

$(TARGET): $(SOURCES)              
	$(CC) $(CCFLAGS) $(PROTECTIONS) $? -o $@
	$(ENABLE_ASLR)

clean:
	$(DEL) $(TARGET)