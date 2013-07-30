#include "../../headers/auth/client_login.h"

#include "../../headers/service/http_methods.h"

namespace gdata {
namespace auth {

const std::string ClientLogin::kAuthorizationTag = "Auth=";

ClientLogin::ClientLoginException::ClientLoginException(const std::string& message)
	: utils::GDataException(message)
{
}

ClientLogin::ClientLoginException::~ClientLoginException() throw()
{
}

ClientLogin::ClientLogin(const std::string& email, const std::string& password)
	: m_email(email), m_password(password)
{
}

ClientLogin::~ClientLogin()
{
}

std::string ClientLogin::get_authorization_token(const std::unique_ptr<service::HTTPQueryInterface>& query)
{
	query->set_uri("https://www.google.com/accounts/ClientLogin");
	query->set_method(service::HTTPMethod::POST);

	query->add_header("Content-Type", "application/x-www-form-urlencoded");
	query->add_header("Content-Length", "0");

	query->add_query_field("accountType", "HOSTED_OR_GOOGLE");
	query->add_query_field("Email", m_email);
	query->add_query_field("Passwd", m_password);
	query->add_query_field("service", "wise");
	query->add_query_field("source", "ClientApp-GDataSpreadsheetsCpp-1.0");

	std::string output = query->run();

	output = extract_token(output);
	return output;
}

std::string ClientLogin::extract_token(const std::string& value)
{
	std::size_t position = value.find(kAuthorizationTag);

	if (position == std::string::npos)
		throw ClientLoginException("Authorization data not found in received message");

	return value.substr(position + kAuthorizationTag.length());
}

} // namespace auth
} // namespace gdata
