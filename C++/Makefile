build: encode.so decode.so

executables: encode.cpp decode.cpp public.h
	-mkdir release
	g++ -o release/encode encode.cpp
	g++ -o release/decode decode.cpp

encode.so: encode.cpp public.h
	g++ -shared -fPIC encode.cpp -o encode.so

decode.so: decode.cpp public.h
	g++ -shared -fPIC decode.cpp -o decode.so
