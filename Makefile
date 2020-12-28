build:
	rm -rf packages/
	mkdir -p packages/emojitk/
	emojicodec -p emojitk main.🍇
	
	mv 🏛 packages/emojitk/
	mv libemojitk.a packages/emojitk/

	g++ -c main.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o gtk.a

	ar rcs packages/emojitk/libemojitk.a gtk.a

	@rm gtk.a
	@rm main.o