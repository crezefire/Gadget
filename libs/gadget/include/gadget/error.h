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
  static constexpr int NoError = 0;

  explicit Error(int errorCode, char const* message, int line, char const* fileName)
      : Message(message)
      , Code(errorCode)
      , Line(line)
      , FileName(fileName) {}

  explicit Error(int errorCode)
      : Error(errorCode, nullptr, 0, nullptr) {}

  explicit Error(int errorCode, char const* message)
      : Error(errorCode, message, 0, nullptr) {}

  Error(const Error&) = delete;

  Error(Error&& rhs)
      : Handled(rhs.Handled)
      , Message(rhs.Message)
      , Code(rhs.Code)
      , Line(rhs.Line)
      , FileName(rhs.FileName) {
    assert((rhs.Handled = true));
  }

  ~Error() { assert(Handled); }

  operator bool() const {
    assert((Handled = true));
    return Code != NoError;
  }

  bool operator==(int code) const {
    assert((Handled = true));
    return Code == code;
  }

  char const* GetMessage() const { return Message; }
  char const* GetFileName() const { return FileName; }
  int GetCode() const { return Code; }
  int GetLine() const { return Line; }
};

} // namespace gget
