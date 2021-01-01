build:
	@rm -rf packages/
	@mkdir -p packages/emojitk/
	emojicodec -p emojitk main.🍇
	
	@mv 🏛 packages/emojitk/
	@mv libemojitk.a packages/emojitk/

	g++-10 -c src/Application.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Application.o -fpermissive -I/usr/local/include
	g++-10 -c src/Button.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Button.o -fpermissive -I/usr/local/include
	g++-10 -c src/Label.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Label.o -fpermissive -I/usr/local/include
	g++-10 -c src/Widget.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Widget.o -fpermissive -I/usr/local/include
	g++-10 -c src/Window.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Window.o -fpermissive -I/usr/local/include

	ar rcs packages/emojitk/libemojitk.a Application.o Button.o Label.o Widget.o Window.o

	@rm Application.o Button.o Label.o Widget.o Window.o
	@rm main.o
