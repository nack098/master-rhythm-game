#ifndef NAKUYA_EXCEPTION
#define NAKUYA_EXCEPTION

#include <cstdint>
#include <format>
#include <iterator>
#include <stacktrace>
#include <stdexcept>
#include <string>

namespace NakuyaMaster {

class Exception : public std::runtime_error {
  public:
    Exception(const std::string &what, std::uint32_t skip = 1u);

    std::string stacktrace() const;

  private:
    std::stacktrace _trace;
};

} // namespace NakuyaMaster

template <> struct std::formatter<NakuyaMaster::Exception> {
    constexpr auto parse(std::format_parse_context &ctx) {
        return std::begin(ctx);
    }

    auto format(const NakuyaMaster::Exception &obj,
                std::format_context &ctx) const {
        return std::format_to(ctx.out(), "{}\n{}", obj.what(),
                              obj.stacktrace());
    }
};
#endif
