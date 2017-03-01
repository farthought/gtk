${gtkpro}:${gtksrc}
	gcc $< -o $@ `pkg-config --cflags --libs gtk+-2.0`
.PHONY:
clean:
	rm *pro

