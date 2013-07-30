#include "../../headers/utils/exceptions.h"

namespace gdata {
namespace utils {

GDataException::GDataException(const std::string& message)
	: m_message(message)
{
}

GDataException::~GDataException() throw()
{
}

const char* GDataException::what() const throw()
{
	return m_message.c_str();
}

} // namespace utils
} // namespace gdata
