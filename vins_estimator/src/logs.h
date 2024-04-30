/**
 * @author: wangyifan@xiaoyubot.com
 * @filename: logs.hpp
 * @brief: the log used in the repo, change to ninebot_log by macro
 */
#ifndef VINS_ESTIMATOR_DEFINES_VINS_LOG_H_
#define VINS_ESTIMATOR_DEFINES_VINS_LOG_H_
#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

#ifndef NUMERIC_PREC
#define NUMERIC_PREC 4  // Number of decimal places.
#endif

#ifdef UNUSEDPARAM
#elif defined(__GNUC__)
#define UNUSEDPARAM(x) UNUSED_##x __attribute__((unused))
#elif defined(__LCLINT__)
#define UNUSEDPARAM(x) /*@unused@*/ x
#else
#define UNUSEDPARAM(x) x
#endif

#ifndef STREAMQUAT
#define STREAMQUAT(q)                                                        \
  std::setprecision(3) << (q).x() << " " << (q).y() << " " << (q).z() << " " \
                       << (q).w() << std::setprecision(NUMERIC_PREC)
#define STREAMQUATHEAD "xyzw"
#endif

#ifndef VINS_LIKELY
#define VINS_LIKELY(x) __builtin_expect((x), 1)
#endif  // VINS_LIKELY
#ifndef VINS_UNLIKELY
#define VINS_UNLIKELY(x) __builtin_expect((x), 0)
#endif  // VINS_UNLIKELY

#ifndef VINSINDENTIFIER
#define VINSINDENTIFIER "VINS: "
#endif  // VINSINDENTIFIER

#ifndef VINS_DEBUG_STREAM
#define VINS_DEBUG_STREAM(x)          \
  do {                                  \
    std::cout << VINSINDENTIFIER << __FUNCTION__ << "DEBUG: " << x << std::endl; \
  } while (0)
#endif  // VINS_DEBUG_STREAM

#ifndef VINS_INFO_STREAM
#define VINS_INFO_STREAM(x)          \
  do {                                 \
    std::cout << VINSINDENTIFIER << __FUNCTION__ << "INFO: " << x << std::endl; \
  } while (0)
#endif  // VINS_INFO_STREAM

#ifndef VINS_WARN_STREAM
#define VINS_WARN_STREAM(x)          \
  do {                                 \
    std::cout << VINSINDENTIFIER << __FUNCTION__ << "WARN: " << x << std::endl; \
  } while (0)
#endif  // VINS_WARN_STREAM

#ifndef VINS_ERROR_STREAM
#define VINS_ERROR_STREAM(x)          \
  do {                                 \
    std::cerr << VINSINDENTIFIER << __FUNCTION__ << "ERROR: " << x << std::endl; \
  } while (0)
#endif  // VINS_ERROR_STREAM

#ifndef VINS_DEBUG_STREAM_ONCE
#define VINS_DEBUG_STREAM_ONCE(x)                   \
  do {                                             \
    static bool __log_stream_once__hit__ = false;  \
    if (VINS_UNLIKELY(!__log_stream_once__hit__)) { \
      __log_stream_once__hit__ = true;             \
      VINS_DEBUG_STREAM(x);                         \
    }                                              \
  } while (0)
#endif  //  VINS_DEBUG_STREAM_ONCE

#ifndef VINS_INFO_STREAM_ONCE
#define VINS_INFO_STREAM_ONCE(x)                    \
  do {                                             \
    static bool __log_stream_once__hit__ = false;  \
    if (VINS_UNLIKELY(!__log_stream_once__hit__)) { \
      __log_stream_once__hit__ = true;             \
      VINS_INFO_STREAM(x);                          \
    }                                              \
  } while (0)
#endif  // VINS_INFO_STREAM_ONCE

#ifndef VINS_WARN_STREAM_ONCE
#define VINS_WARN_STREAM_ONCE(x)                    \
  do {                                             \
    static bool __log_stream_once__hit__ = false;  \
    if (VINS_UNLIKELY(!__log_stream_once__hit__)) { \
      __log_stream_once__hit__ = true;             \
      VINS_WARN_STREAM(x);                          \
    }                                              \
  } while (0)
#endif  // VINS_WARN_STREAM_ONCE

#ifndef VINS_ERROR_STREAM_ONCE
#define VINS_ERROR_STREAM_ONCE(x)                   \
  do {                                             \
    static bool __log_stream_once__hit__ = false;  \
    if (VINS_UNLIKELY(!__log_stream_once__hit__)) { \
      __log_stream_once__hit__ = true;             \
      VINS_ERROR_STREAM(x);                         \
    }                                              \
  } while (0)
#endif  // VINS_ERROR_STREAM_ONCE

#ifndef VINS_DEBUG_STREAM_THROTTLE
#define VINS_DEBUG_STREAM_THROTTLE(rate, x)                               \
  do {                                                                   \
    static double __log_stream_throttle__last_hit__ = 0.0;               \
    std::chrono::time_point<std::chrono::system_clock>                   \
        __log_stream_throttle__now__ = std::chrono::system_clock::now(); \
    if (VINS_UNLIKELY(                                                    \
            __log_stream_throttle__last_hit__ + rate <=                  \
            std::chrono::duration_cast<std::chrono::seconds>(            \
                __log_stream_throttle__now__.time_since_epoch())         \
                .count())) {                                             \
      __log_stream_throttle__last_hit__ =                                \
          std::chrono::duration_cast<std::chrono::seconds>(              \
              __log_stream_throttle__now__.time_since_epoch())           \
              .count();                                                  \
      VINS_DEBUG_STREAM(x);                                               \
    }                                                                    \
  } while (0)
#endif  // VINS_DEBUG_STREAM_THROTTLE

#ifndef VINS_INFO_STREAM_THROTTLE
#define VINS_INFO_STREAM_THROTTLE(rate, x)                                \
  do {                                                                   \
    static double __log_stream_throttle__last_hit__ = 0.0;               \
    std::chrono::time_point<std::chrono::system_clock>                   \
        __log_stream_throttle__now__ = std::chrono::system_clock::now(); \
    if (VINS_UNLIKELY(                                                    \
            __log_stream_throttle__last_hit__ + rate <=                  \
            std::chrono::duration_cast<std::chrono::seconds>(            \
                __log_stream_throttle__now__.time_since_epoch())         \
                .count())) {                                             \
      __log_stream_throttle__last_hit__ =                                \
          std::chrono::duration_cast<std::chrono::seconds>(              \
              __log_stream_throttle__now__.time_since_epoch())           \
              .count();                                                  \
      VINS_INFO_STREAM(x);                                                \
    }                                                                    \
  } while (0)
#endif  // VINS_INFO_STREAM_THROTTLE

#ifndef VINS_WARN_STREAM_THROTTLE
#define VINS_WARN_STREAM_THROTTLE(rate, x)                                \
  do {                                                                   \
    static double __log_stream_throttle__last_hit__ = 0.0;               \
    std::chrono::time_point<std::chrono::system_clock>                   \
        __log_stream_throttle__now__ = std::chrono::system_clock::now(); \
    if (VINS_UNLIKELY(                                                    \
            __log_stream_throttle__last_hit__ + rate <=                  \
            std::chrono::duration_cast<std::chrono::seconds>(            \
                __log_stream_throttle__now__.time_since_epoch())         \
                .count())) {                                             \
      __log_stream_throttle__last_hit__ =                                \
          std::chrono::duration_cast<std::chrono::seconds>(              \
              __log_stream_throttle__now__.time_since_epoch())           \
              .count();                                                  \
      VINS_WARN_STREAM(x);                                                \
    }                                                                    \
  } while (0)
#endif  //  VINS_WARN_STREAM_THROTTLE

#ifndef VINS_ERROR_STREAM_THROTTLE
#define VINS_ERROR_STREAM_THROTTLE(rate, x)                               \
  do {                                                                   \
    static double __log_stream_throttle__last_hit__ = 0.0;               \
    std::chrono::time_point<std::chrono::system_clock>                   \
        __log_stream_throttle__now__ = std::chrono::system_clock::now(); \
    if (VINS_UNLIKELY(                                                    \
            __log_stream_throttle__last_hit__ + rate <=                  \
            std::chrono::duration_cast<std::chrono::seconds>(            \
                __log_stream_throttle__now__.time_since_epoch())         \
                .count())) {                                             \
      __log_stream_throttle__last_hit__ =                                \
          std::chrono::duration_cast<std::chrono::seconds>(              \
              __log_stream_throttle__now__.time_since_epoch())           \
              .count();                                                  \
      VINS_ERROR_STREAM(x);                                               \
    }                                                                    \
  } while (0)
#endif  // VINS_ERROR_STREAM_THROTTLE

#ifndef VINS_DEBUG_STREAM_COND
#define VINS_DEBUG_STREAM_COND(cond, x) \
  do {                                 \
    if (VINS_UNLIKELY(cond)) {          \
      VINS_DEBUG_STREAM(x);             \
    }                                  \
  } while (0)
#endif  // VINS_DEBUG_STREAM_COND

#ifndef VINS_INFO_STREAM_COND
#define VINS_INFO_STREAM_COND(cond, x) \
  do {                                \
    if (VINS_UNLIKELY(cond)) {         \
      VINS_INFO_STREAM(x);             \
    }                                 \
  } while (0)
#endif  // VINS_INFO_STREAM_COND

#ifndef VINS_WARN_STREAM_COND
#define VINS_WARN_STREAM_COND(cond, x) \
  do {                                \
    if (VINS_UNLIKELY(cond)) {         \
      VINS_WARN_STREAM(x);             \
    }                                 \
  } while (0)
#endif  // VINS_WARN_STREAM_COND

#ifndef VINS_ERROR_STREAM_COND
#define VINS_ERROR_STREAM_COND(cond, x) \
  do {                                 \
    if (VINS_UNLIKELY(cond)) {          \
      VINS_ERROR_STREAM(x);             \
    }                                  \
  } while (0)
#endif  // VINS_ERROR_STREAM_COND
#endif  // VINS_ESTIMATOR_DEFINES_VINS_LOG_H_