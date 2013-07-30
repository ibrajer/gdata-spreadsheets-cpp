#ifndef GDATA_SPREADSHEETS_CPP_HTTPS_QUERY_H_
#define GDATA_SPREADSHEETS_CPP_HTTPS_QUERY_H_

#include <map>

#include "../utils/exceptions.h"
#include "http_query_interface.h"

namespace gdata {
namespace service {

class HTTPSQuery : public HTTPQueryInterface
{
 public:
	class MessageNotReceivedException : public utils::GDataException
	{
	 public:
		MessageNotReceivedException();
		~MessageNotReceivedException() throw();
	};

	class ResponseCodeException : public utils::GDataException
	{
	 public:
		ResponseCodeException(std::uint32_t response_code);
		~ResponseCodeException() throw();
	};

	HTTPSQuery();
	~HTTPSQuery();

	void add_header(const std::string& name, const std::string& value);
	void add_query_field(const std::string& name, const std::string& value);

	std::string run();

	void set_data(const std::string& data);
	void set_method(const HTTPMethod& method);
	void set_uri(const std::string& uri);

 private:
	std::string m_uri;
	std::string m_method;
	std::string m_data;
	std::map<std::string, std::string> m_headers;
	std::string m_query;
};

} // namespace service
} // namespace gdata


#endif /* GDATA_SPREADSHEETS_CPP_HTTPS_QUERY_H_ */
