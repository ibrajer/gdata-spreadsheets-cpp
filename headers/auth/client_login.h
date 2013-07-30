#ifndef GDATA_SPREADSHEETS_CPP_CLIENTLOGIN_H_
#define GDATA_SPREADSHEETS_CPP_CLIENTLOGIN_H_

#include "authorization_interface.h"
#include "../utils/exceptions.h"
#include "../utils/macros.h"

namespace gdata {
namespace auth {

class ClientLogin : public AuthorizationInterface
{
 public:
	class ClientLoginException : public utils::GDataException
	{
	 public:
		ClientLoginException(const std::string& message);
		~ClientLoginException() throw();
	};

	ClientLogin(const std::string& email, const std::string& password);
	~ClientLogin();

	std::string get_authorization_token(const std::unique_ptr<service::HTTPQueryInterface>& query);

 private:
	static const std::string kAuthorizationTag;

	std::string extract_token(const std::string& value);

	const std::string m_email;
	const std::string m_password;
};

} // namespace auth
} // namespace gdata

#endif /* GDATA_SPREADSHEETS_CPP_CLIENTLOGIN_H_ */
