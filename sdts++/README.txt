Generation of the lexer and parser from the original Makefile.am file:

# XXX Ugh.  automake wasn't properly generating these files, so I'm having
# XXX to do them by hand.  Moreover, there's the obvious dependency on
# XXX GNU bison and flex; mind, since no one should be changing these files
# XXX anyway, this shouldn't be a problem.

io/FormatLexer.c : io/FormatLexer.ll
	flex  -B -Psio_8211_yy $<
	mv lex.sio_8211_yy.c $@

io/FormatParser.c : io/FormatParser.yy
	bison --defines -p sio_8211_yy $< -o $@

The *.c files are included in the original library sources.

Changes:

We generate .cc files:

  flex++ -B --outfile=FormatLexer.cc io/FormatLexer.ll

  bison --defines -p sio_8211_yy --output=FormatParser.cc io/FormatParser.yy



