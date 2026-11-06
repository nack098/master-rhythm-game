#ifndef NAKUYA_FILE_READER
#define NAKUYA_FILE_READER
#include <filesystem>
#include <fstream>
#include <string>

namespace NakuyaMaster {
class FileReader {
  public:
    FileReader();
    FileReader(FileReader &&other);
    FileReader(const FileReader &) = delete;
    FileReader &operator=(const FileReader &) = delete;

    void open(std::filesystem::path path);
    bool is_end();
    std::string &read_line();
    void swap(FileReader &other) noexcept;

  private:
    std::ifstream stream_;
    std::string buf_;
};
} // namespace NakuyaMaster
#endif
