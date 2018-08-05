#pragma once

#include <cassert>

namespace gget {
class [[nodiscard]] Error {
#ifndef NDEBUG
    mutable bool Handled{false};
#endif

    char const* Message{nullptr};
    int         Code{-1};

public:
    enum DefaultErrorCodes
    {
        NoError  = 0,
        HasError = 1
    };

    Error() = default;

    Error(DefaultErrorCodes errorCode) : Error(static_cast<int>(errorCode)) {}

    Error(int errorCode, char const* message) : Message(message), Code(errorCode) {}

    Error(int const errorCode) : Error(errorCode, nullptr) {}

    Error(char const* message) : Error(HasError, message) {}

    Error(Error const&) = delete;

    Error(Error && rhs)
#ifdef NDEBUG
      = default;
#else
        : Handled(rhs.Handled), Message(rhs.Message), Code(rhs.Code) {
        assert((rhs.Handled = true));
    }

    ~Error() { assert(Handled); }
#endif

    operator bool() const {
        assert((Handled = true));
        return Code != NoError;
    }

    bool operator==(int const code) const {
        assert((Handled = true));
        return Code == code;
    }

    char const* GetMessage() const { return Message; }
    int         GetCode() const { return Code; }
};

template <typename T>
struct ErrorValue {
    Error E;
    T     Value;
};
} // namespace gget

#define __GADGET_STRINGIFY_IMPL(str) #str
#define __GADGET_STRINGIFY(str) __GADGET_STRINGIFY_IMPL(str)
#define __GADGET_ERMSG(msg, file, line) file "(" line "): " msg
#define GADGET_ERMSG(msg) __GADGET_ERMSG(msg, __FILE__, __GADGET_STRINGIFY(__LINE__))
