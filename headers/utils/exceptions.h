#ifndef GDATA_SPREADSHEETS_CPP_EXCEPTIONS_H_
#define GDATA_SPREADSHEETS_CPP_EXCEPTIONS_H_

#include <exception>
#include <string>

#include "macros.h"

namespace gdata {
namespace utils {

class GDataException : public std::exception
{
 public:
	GDataException(const std::string& message);
	virtual ~GDataException() throw();

	const char* what() const throw ();

 protected:
	std::string m_message;
};

} // namespace utils
} // namespace gdata


#endif /* GDATA_SPREADSHEETS_CPP_EXCEPTIONS_H_ */
