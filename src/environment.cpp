#include "environment.h"
#include "error.h"

#ifdef WIN32
#include <windows.h>
static inline std::filesystem::path get_binary_win32_impl() {
    wchar_t path[MAX_PATH] = {0};
    NakuyaMaster::ensure(::GetModuleFileNameW(NULL, path, MAX_PATH) > 0,
                         "GetModuleFileNameW error {}", ::GetLastError());
    return path;
}
#else
#include <limits.h>
#include <unistd.h>
static inline std::filesystem::path get_binary_unix_impl() {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    ensure(count > 0, "unable to get binary path");
    return std::string(result, count);
}
#endif

namespace NakuyaMaster {
Environment::Environment(std::filesystem::path path) {
    old_cwd_ = std::filesystem::current_path();
    set_path(path);
}
Environment::~Environment() { set_path(old_cwd_); }

void Environment::set_path(std::filesystem::path to) {
    std::filesystem::current_path(to);
}

std::filesystem::path get_binary_path() {
#ifdef WIN32
    return get_binary_win32_impl();
#else
    return get_binary_unix_impl();
#endif
}
} // namespace NakuyaMaster
