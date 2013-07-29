#ifndef GDATA_SPREADSHEETS_CPP_AUTHORIZATION_INTERFACE_H_
#define GDATA_SPREADSHEETS_CPP_AUTHORIZATION_INTERFACE_H_

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

	virtual std::string get_authorization_token() = 0;
};

} // namespace auth
} // namespace gdata

#endif /* GDATA_SPREADSHEETS_CPP_AUTHORIZATION_INTERFACE_H_ */
