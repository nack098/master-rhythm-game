#ifndef NAKUYA_ENVIRONMENT
#define NAKUYA_ENVIRONMENT
#include <filesystem>
namespace NakuyaMaster {
class Environment {
  public:
    Environment(std::filesystem::path path);
    ~Environment();
    Environment(const Environment &) = delete;
    Environment &operator=(const Environment &) = delete;
    Environment(Environment &&) = delete;

    void set_path(std::filesystem::path to);

  private:
    std::filesystem::path old_cwd_;
};

std::filesystem::path get_binary_path();
} // namespace NakuyaMaster
#endif
