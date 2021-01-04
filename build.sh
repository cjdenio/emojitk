#!/bin/bash

rm -rf packages/
mkdir -p packages/emojitk/
mkdir -p bin/src/

emojicodec -r -p emojitk main.🍇

mv documentation.json packages/emojitk/

mv 🏛 packages/emojitk/
mv libemojitk.a packages/emojitk/

for f in src/*.cpp
do
        echo "👷 building file $f"
	g++-10 -c $f `pkg-config gtkmm-3.0 --cflags --libs` -o "bin/$f.o" -fpermissive -I/usr/local/include
done

# ar rcs packages/emojitk/libemojitk.a Application.o Button.o Label.o Widget.o Window.o
ar rcs packages/emojitk/libemojitk.a bin/src/*.o

rm main.o
rm -rf bin/
