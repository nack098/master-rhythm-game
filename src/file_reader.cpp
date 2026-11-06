#include "file_reader.h"
#include "error.h"
#include <filesystem>

namespace NakuyaMaster {
FileReader::FileReader() {}
FileReader::FileReader(FileReader &&other) : FileReader() { swap(other); }

void FileReader::open(std::filesystem::path path) {
    std::filesystem::path full = std::filesystem::absolute(path);
    ensure(std::filesystem::exists(full), "file at {} is not exist",
           full.string());
    stream_.clear();
    stream_.open(full);
    ensure(stream_.is_open(), "unable to open file");
}

bool FileReader::is_end() { return stream_.eof(); }

std::string &FileReader::read_line() {
    std::getline(stream_, buf_);
    return buf_;
}

void FileReader::swap(FileReader &other) noexcept {
    std::ranges::swap(other.stream_, stream_);
    std::ranges::swap(other.buf_, buf_);
}
} // namespace NakuyaMaster
