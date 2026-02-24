#pragma once

#include <chrono>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

namespace ORB_SLAM3
{
namespace shutdown_trace
{

inline auto monotonic_us() -> std::uint64_t {
    using namespace std::chrono;
    return duration_cast<microseconds>(steady_clock::now().time_since_epoch())
        .count();
}

inline auto tid_string() -> std::string {
    std::ostringstream oss;
    oss << std::this_thread::get_id();
    return oss.str();
}

inline void log(const char* tag, const std::string& msg) {
#ifdef ORBROS_SHUTDOWN_TRACE
    std::cerr << "[ORBROS_SHUTDOWN_TRACE] t_us=" << monotonic_us()
              << " tid=" << tid_string() << " tag=" << tag << " " << msg
              << std::endl;
#else
    (void)tag;
    (void)msg;
#endif
}

}  // namespace shutdown_trace
}  // namespace ORB_SLAM3
