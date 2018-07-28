#pragma once

#include <cassert>

namespace gget {

class Error {
    [[maybe_unused]] mutable bool Handled{false};
    char const* Message{nullptr};
    const int Code{-1};

    int Line{-1};
    char const* FileName{nullptr};

    public:
    enum NE { NoError = 0 };

    static constexpr int HasError = 1;

    Error(NE)
        : Error(0) {}

    Error(int errorCode, char const* message, int const line, char const* fileName)
        : Message(message)
        , Code(errorCode)
        , Line(line)
        , FileName(fileName) {}

    Error(int const errorCode)
        : Error(errorCode, nullptr, 0, nullptr) {}

    Error(int const errorCode, char const* message)
        : Error(errorCode, message, 0, nullptr) {}

    Error(char const* message)
        : Error(HasError, message, 0, nullptr) {}

    Error(const Error&) = delete;

    Error(Error&& rhs)
#ifdef NDEBUG
        = default;
#else
        : Handled(rhs.Handled)
        , Message(rhs.Message)
        , Code(rhs.Code)
        , Line(rhs.Line)
        , FileName(rhs.FileName) {
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
    char const* GetFileName() const { return FileName; }
    int GetCode() const { return Code; }
    int GetLine() const { return Line; }
};

} // namespace gget
