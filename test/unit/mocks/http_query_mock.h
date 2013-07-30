#ifndef GDATA_SPREADSHEETS_CPP_HTTP_QUERY_MOCK_H_
#define GDATA_SPREADSHEETS_CPP_HTTP_QUERY_MOCK_H_

#include <string>

#include <gmock/gmock.h>

#include "../../../headers/service/http_query_interface.h"
#include "../../../headers/service/http_methods.h"

namespace gdata {
namespace test {

class HTTPQueryMock : public service::HTTPQueryInterface
{
 public:
	MOCK_METHOD2(add_header, void(const std::string& name, const std::string& value));
	MOCK_METHOD2(add_query_field, void(const std::string& name, const std::string& value));

	MOCK_METHOD0(run, std::string());

	MOCK_METHOD1(set_data, void(const std::string& data));
	MOCK_METHOD1(set_method, void(const service::HTTPMethod& method));
	MOCK_METHOD1(set_uri, void(const std::string& uri));
};

} // namespace test
} // namespace gdata


#endif /* GDATA_SPREADSHEETS_CPP_HTTP_QUERY_MOCK_H_ */
