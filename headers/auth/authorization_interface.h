#ifndef GDATA_SPREADSHEETS_CPP_AUTHORIZATION_INTERFACE_H_
#define GDATA_SPREADSHEETS_CPP_AUTHORIZATION_INTERFACE_H_

#include <string>
#include <memory>

#include "../service/http_query_interface.h"

// implements logic of getting authorization token from Google services
// ways to get authorization token:
// ClientLogin
// TODO: OAuth 2.0

namespace gdata {
namespace auth {

class AuthorizationInterface
{
 public:
	virtual ~AuthorizationInterface() {};

	virtual std::string get_authorization_token(const std::unique_ptr<service::HTTPQueryInterface>& query) = 0;
};

} // namespace auth
} // namespace gdata

#endif /* GDATA_SPREADSHEETS_CPP_AUTHORIZATION_INTERFACE_H_ */
