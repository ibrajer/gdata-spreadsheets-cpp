#ifndef GDATA_SPREADSHEETS_CPP_HTTP_QUERY_INTERFACE_H_
#define GDATA_SPREADSHEETS_CPP_HTTP_QUERY_INTERFACE_H_

#include <string>

#include "http_methods.h"

namespace gdata {
namespace service {

class HTTPQueryInterface
{
 public:
	virtual ~HTTPQueryInterface() {};

	virtual void add_header(const std::string& name, const std::string& value) = 0;
	virtual void add_query_field(const std::string& name, const std::string& value) = 0;

	virtual std::string run() = 0;

	virtual void set_data(const std::string& data) = 0;
	virtual void set_method(const HTTPMethod& method) = 0;
	virtual void set_uri(const std::string& uri) = 0;
};

} // namespace service
} // namespace gdata


#endif /* GDATA_SPREADSHEETS_CPP_HTTP_QUERY_INTERFACE_H_ */
