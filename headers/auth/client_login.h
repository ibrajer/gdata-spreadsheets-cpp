#ifndef GDATA_SPREADSHEETS_CPP_CLIENTLOGIN_H_
#define GDATA_SPREADSHEETS_CPP_CLIENTLOGIN_H_

#include <string>

#include "authorization_interface.h"
#include "../utils/macros.h"

namespace gdata {
namespace auth {

class ClientLogin : public AuthorizationInterface
{
 public:
	ClientLogin(const std::string& email, const std::string& password);
	~ClientLogin();

	std::string get_authorization_token();

 private:
	static const std::string kAuthorizationTag;

	std::string extract_token(const std::string& value);
	std::string make_query();

	const std::string m_email;
	const std::string m_password;

	DISALLOW_COPY_AND_ASSIGN(ClientLogin);
};

} // namespace auth
} // namespace gdata

#endif /* GDATA_SPREADSHEETS_CPP_CLIENTLOGIN_H_ */
