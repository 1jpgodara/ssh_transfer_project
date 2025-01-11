#include "compress.h"
#include <zlib.h>
#include <fstream>
#include <iostream>

#define CHUNK 16384

bool compressFile(const std::string& sourceFile, const std::string& destFile) {
    std::ifstream source(sourceFile, std::ios::binary);
    std::ofstream dest(destFile, std::ios::binary);

    if (!source.is_open() || !dest.is_open()) {
        std::cerr << "Error opening files for compression.\n";
        return false;
    }

    z_stream strm = {0};
    deflateInit(&strm, Z_BEST_COMPRESSION);

    char in[CHUNK];
    char out[CHUNK];
    int flush;

    do {
        source.read(in, CHUNK);
        strm.avail_in = source.gcount();
        flush = source.eof() ? Z_FINISH : Z_NO_FLUSH;
        strm.next_in = reinterpret_cast<Bytef*>(in);

        do {
            strm.avail_out = CHUNK;
            strm.next_out = reinterpret_cast<Bytef*>(out);
            deflate(&strm, flush);
            dest.write(out, CHUNK - strm.avail_out);
        } while (strm.avail_out == 0);
    } while (flush != Z_FINISH);

    deflateEnd(&strm);
    source.close();
    dest.close();

    return true;
}
