#pragma once
#include <rapidjson/document.h>
#include <fmt/format.h>
#include <format>
#include <spdlog/fmt/fmt.h>

/** @cond Doxygen_Exclude */
namespace CesiumUtility_detail {
inline const char* rapidjsonParseErrorName(rapidjson::ParseErrorCode code) {
  switch (code) {
  case rapidjson::ParseErrorCode::kParseErrorNone:
    return "No error.";
  case rapidjson::ParseErrorCode::kParseErrorDocumentEmpty:
    return "The document is empty.";
  case rapidjson::ParseErrorCode::kParseErrorDocumentRootNotSingular:
    return "The document root must not follow by other values.";
  case rapidjson::ParseErrorCode::kParseErrorValueInvalid:
    return "Invalid value.";
  case rapidjson::ParseErrorCode::kParseErrorObjectMissName:
    return "Missing a name for object member.";
  case rapidjson::ParseErrorCode::kParseErrorObjectMissColon:
    return "Missing a colon after a name of object member.";
  case rapidjson::ParseErrorCode::kParseErrorObjectMissCommaOrCurlyBracket:
    return "Missing a comma or '}' after an object member.";
  case rapidjson::ParseErrorCode::kParseErrorArrayMissCommaOrSquareBracket:
    return "Missing a comma or ']' after an array element.";
  case rapidjson::ParseErrorCode::kParseErrorStringUnicodeEscapeInvalidHex:
    return "Incorrect hex digit after \\u escape in string.";
  case rapidjson::ParseErrorCode::kParseErrorStringUnicodeSurrogateInvalid:
    return "The surrogate pair in string is invalid.";
  case rapidjson::ParseErrorCode::kParseErrorStringEscapeInvalid:
    return "Invalid escape character in string.";
  case rapidjson::ParseErrorCode::kParseErrorStringMissQuotationMark:
    return "Missing a closing quotation mark in string.";
  case rapidjson::ParseErrorCode::kParseErrorStringInvalidEncoding:
    return "Invalid encoding in string.";
  case rapidjson::ParseErrorCode::kParseErrorNumberTooBig:
    return "Number too big to be stored in double.";
  case rapidjson::ParseErrorCode::kParseErrorNumberMissFraction:
    return "Miss fraction part in number.";
  case rapidjson::ParseErrorCode::kParseErrorNumberMissExponent:
    return "Miss exponent in number.";
  case rapidjson::ParseErrorCode::kParseErrorTermination:
    return "Parsing was terminated.";
  case rapidjson::ParseErrorCode::kParseErrorUnspecificSyntaxError:
    return "Unspecific syntax error.";
  default:
    return "unknown";
  }
}
} // namespace CesiumUtility_detail

template <>
struct fmt::formatter<rapidjson::ParseErrorCode>
    : fmt::formatter<fmt::string_view> {
  auto format(rapidjson::ParseErrorCode code, fmt::format_context& ctx) const {
    return fmt::formatter<fmt::string_view>::format(
        CesiumUtility_detail::rapidjsonParseErrorName(code), ctx);
  }
};

template <>
struct std::formatter<rapidjson::ParseErrorCode>
    : std::formatter<std::string_view> {
  auto format(rapidjson::ParseErrorCode code, std::format_context& ctx) const {
    return std::formatter<std::string_view>::format(
        CesiumUtility_detail::rapidjsonParseErrorName(code), ctx);
  }
};
/** @endcond */
