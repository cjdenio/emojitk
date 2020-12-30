build:
	@rm -rf packages/
	@mkdir -p packages/emojitk/
	emojicodec -p emojitk main.🍇
	
	@mv 🏛 packages/emojitk/
	@mv libemojitk.a packages/emojitk/

	g++ -c src/Application.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Application.o -fpermissive
	g++ -c src/Button.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Button.o -fpermissive
	g++ -c src/Label.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Label.o -fpermissive
	g++ -c src/Widget.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Widget.o -fpermissive
	g++ -c src/Window.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Window.o -fpermissive

	ar rcs packages/emojitk/libemojitk.a Application.o Button.o Label.o Widget.o Window.o

	@rm Application.o Button.o Label.o Widget.o Window.o
	@rm main.o