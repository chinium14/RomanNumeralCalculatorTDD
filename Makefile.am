AUTOMAKE_OPTIONS = subdir-objects
TESTS = RomanCheck
#RomanNumeralCalculatordir = /Users/Shuai/Documents/RomanNumeralCalculatorTDD/lib
#RomanNumeralCalculator_LTLIBRARIES= libRomanNumeralCalculator.la
#libRomanNumeralCalculator_la_SOURCES = \
 #       src/Roman.h
check_PROGRAMS = RomanCheck
RomanCheck_SOURCES = \
	test/test_main.c \
        src/Roman.h
RomanCheck_CFLAGS = @CHECK_CFLAGS@
RomanCheck_LDADD = @CHECK_LIBS@

#bin_PROGRAMS = RomanNumeralCalculator
#RomanNumeralCalculator_SOURCES = \
#	test/test_main.c \
#        src/Roman.h
ACLOCAL_AMFLAGS = -I m4
