build: encode decode

encode: encode.cpp
	g++ -o release/encode encode.cpp

decode: decode.cpp
	g++ -o release/decode decode.cpp
